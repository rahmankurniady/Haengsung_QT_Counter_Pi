#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include "console.h"
#include <QDateTime>
#include "readgpio.h"
#include <QKeyEvent>

QThread *mThread= new QThread();
ReadGpio *serviceGPIO = new ReadGpio();

double dummy_counter=0;
double dummy_counter_out=0;
double dummy_table=0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    console = new Console;
    console->setEnabled(false);
    ui->stackedWidget->insertWidget(0,console);
    ui->stackedWidget->setCurrentIndex(0);
//    console->setEnabled(true);

    serial = new QSerialPort(this);
    connect(serial,static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),this,&MainWindow::disconnected_COM);
    connect(serial,&QSerialPort::readyRead,this,&MainWindow::checkAvailable);

    timer_Serial= new QTimer(this);
    connect(timer_Serial, SIGNAL(timeout()), this, SLOT(processRead()));
    timer_Serial->setInterval(10);
    init_serial();


    load_Configuration();
    Read_Clock();
    init_db();
    init_devicelist();
    init_Counter();

    /* Service Thread Read GPIO */
    serviceGPIO->moveToThread(mThread);
    connect(serviceGPIO, SIGNAL(Signal_In(QString)),this,SLOT(Count_Up(QString)));
    connect(mThread, SIGNAL(started()),serviceGPIO, SLOT(read_input()));
    mThread->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    //qDebug() << "you press" << event->key();
    if(event->key()==47){
        ui->tabWidget->setCurrentIndex(0);
    }
    else if(event->key()==42){
        ui->tabWidget->setCurrentIndex(1);
    }
    else if(event->key()==45){
        ui->tabWidget->setCurrentIndex(2);
    }
    else if(event->key()==43){
        ui->tabWidget->setCurrentIndex(3);
    }
}

/* Clock Setting  */
void MainWindow::Read_Clock(){

    qDebug() << "-----------------------   Init Clock   -----------------------";
      socket = new QTcpSocket(this);
      socket->connectToHost(IP_TCP,Port_TCP.toInt());
       if(!socket->waitForConnected(2500)){
            qDebug() << "socket Disconnected";
            ui->lbl_stat_tcp->setText("Disconnected");
       }
       else {
            qDebug() << "socket Connected";
            ui->lbl_stat_tcp->setText("Connected");
            QByteArray ba;
            QString data_SEND = "GET /clock/index.php HTTP/1.0\r\n\r\n\r\n";
            ba.append(data_SEND);
            socket->write(ba);
            socket->waitForBytesWritten(200);
            socket->waitForReadyRead(600);
       }
         QThread::msleep(50);
         QByteArray socketread;
               socketread.append(socket->readAll());
               //QThread::msleep(100);
               while(socket->waitForReadyRead(200)){
                      socketread.append(socket->readAll());
                  }
               int i=0;
                         for(i=0;i<512;i++){
                             if(socketread[i]=='#'){
                                 break;
                             }
                         }
               socketread.remove(0,i+1);

               qDebug() << "Received" << socketread;

               //SET TIME
               QString text = tr("sudo date -s '%1.0000+0700'").arg((QString) socketread);

               qDebug() << text;
               system(text.toUtf8().constData());

               text = "sudo hwclock -w";
               system(text.toUtf8().constData());
}


/* Void Process Signal Cunter */
void MainWindow::init_Counter(){
    if(db.open()){
       ui->lbl_stat_db->setText("Connected");  //Connected
       qDebug() << "DB Connected";

       //Check Data today exist
       QSqlQuery query(db);
       query.prepare(tr("SELECT qty_actual,qty_table FROM `itx_t_result` where machine_id='%1' AND DATE(createDate)=CURRENT_DATE")
                     .arg(ID_Machine));
       query.exec();
       while(query.next()){
            dummy_counter=query.value(0).toDouble();
            ui->lbl_counter_In->setText(tr("%1").arg(dummy_counter));
            dummy_table=query.value(1).toDouble();
            ui->lbl_counter_table->setText(tr("%1").arg(dummy_table));
       }
    }
    else{
        ui->lbl_stat_db->setText("Disconnected");  //Disconnected
        qDebug() << db.lastError().text();
    }

}

void MainWindow::Count_Up(QString value){
    if(value=="1"){
        qDebug() << "Counter In";
        dummy_counter++;
        ui->lbl_counter_In->setText(tr("%1").arg(dummy_counter));
        Update_Counter();
    }
    else if(value=="2"){
        qDebug() << "Counter Table";
        dummy_table++;
        ui->lbl_counter_table->setText(tr("%1").arg(dummy_table));
        Update_Table_Counter();

    }
    else if(value=="3"){
        qDebug() << "Counter Out";
        dummy_counter_out++;
        ui->lbl_counter_out->setText(tr("%1").arg(dummy_counter_out));
    }
}

void MainWindow::Update_Table_Counter(){
    int result_query=-1;
    if(db.open()){
       ui->lbl_stat_db->setText("Connected");  //Connected
       qDebug() << "DB Connected";

       //Check Data today exist
       QSqlQuery query(db);
       query.prepare(tr("SELECT if(DATE(createDate)=CURRENT_DATE, '1','0') FROM `itx_t_result` where machine_id='%1' order by createDate desc Limit 1")
                     .arg(ID_Machine));
       query.exec();
       while(query.next()){
            result_query=query.value(0).toInt();
       }

       if((result_query==0)||(result_query==-1)){
           //Insert Data
           console->putData("Table IN Insert\r\n");
           query.prepare(tr("INSERT INTO `itx_t_result`"
                            "(`machine_id`, `qty_table`, `start_time`) VALUES "
                            "('%1','1',CURRENT_TIMESTAMP)")
                         .arg(ID_Machine));
           query.exec();

       }
       else if(result_query==1){
           //Update Data
           console->putData("Table IN Update\r\n");
           query.prepare(tr("UPDATE `itx_t_result` SET `qty_table`=`qty_table`+1 "
                            "WHERE machine_id='%1' AND DATE(createDate)=CURRENT_DATE;")
                         .arg(ID_Machine));
           query.exec();


       }
       else{
            //No Result Query

       }


    }
    else {
       ui->lbl_stat_db->setText("Disconnected");  //Disconnected
       qDebug() << db.lastError().text();
    }
}

void MainWindow::Update_Counter(){
    int result_query=-1;
    if(db.open()){
       ui->lbl_stat_db->setText("Connected");  //Connected
       qDebug() << "DB Connected";

       //Check Data today exist
       QSqlQuery query(db);
       query.prepare(tr("SELECT if(DATE(createDate)=CURRENT_DATE, '1','0') FROM `itx_t_result` where machine_id='%1' order by createDate desc Limit 1")
                     .arg(ID_Machine));
       query.exec();
       while(query.next()){
            result_query=query.value(0).toInt();
       }

       if((result_query==0)||(result_query==-1)){
           //Insert Data
           console->putData("Counter IN Insert\r\n");
           query.prepare(tr("INSERT INTO `itx_t_result`"
                            "(`machine_id`, `qty_actual`, `start_time`) VALUES "
                            "('%1','1',CURRENT_TIMESTAMP)")
                         .arg(ID_Machine));
           query.exec();

       }
       else if(result_query==1){
           //Update Data
           console->putData("Counter IN Update\r\n");
           query.prepare(tr("UPDATE `itx_t_result` SET `qty_actual`=`qty_actual`+1 , `finish_time`=CURRENT_TIMESTAMP "
                            "WHERE machine_id='%1' AND DATE(createDate)=CURRENT_DATE;")
                         .arg(ID_Machine));
           query.exec();


       }
       else{
            //No Result Query

       }


    }
    else {
       ui->lbl_stat_db->setText("Disconnected");  //Disconnected
       qDebug() << db.lastError().text();
    }

}

/*  Database */
void MainWindow::init_db(){
    qDebug() << "-----------------------    init_DB      -----------------------";
           db = QSqlDatabase::addDatabase("QMYSQL");
           db.setHostName(IP_DB);
           db.setUserName(Username);
           db.setPassword(Password);
           db.setDatabaseName(DB_Name);

           if(db.open()){
              ui->lbl_stat_db->setText("Connected");  //Connected
              qDebug() << "DB Connected";
           }
           else {
              ui->lbl_stat_db->setText("Disconnected");  //Disconnected
              qDebug() << db.lastError().text();
           }

}

void MainWindow::init_devicelist(){
    double row;

    qDebug() << "-----------------------Init Device List -----------------------";

    if(db.open()){
       ui->lbl_stat_db->setText("Connected");
       qDebug() << "Load Data";
       ui->table_device_list->setRowCount(0);

       QSqlQuery query(db);
       query.prepare(tr("SELECT * FROM itx_m_device_list WHERE group_id='%1'").arg(ID_Group));
       query.exec();

       while(query.next()){

           row = ui->table_device_list->rowCount();
           ui->table_device_list->insertRow(row);

            QTableWidgetItem *item1 = new QTableWidgetItem(query.value(1).toString());
            item1->setTextAlignment(Qt::AlignCenter);
            ui->table_device_list->setItem(row, 0, item1);
            QTableWidgetItem *item2 = new QTableWidgetItem(query.value(2).toString());
            item2->setTextAlignment(Qt::AlignCenter);
            ui->table_device_list->setItem(row, 1, item2);
            QTableWidgetItem *item3 = new QTableWidgetItem(query.value(0).toString());
            item3->setTextAlignment(Qt::AlignCenter);
            ui->table_device_list->setItem(row, 2, item3);
            QTableWidgetItem *item4 = new QTableWidgetItem(query.value(3).toString());
            item1->setTextAlignment(Qt::AlignCenter);
            ui->table_device_list->setItem(row, 3, item4);
            QTableWidgetItem *item5 = new QTableWidgetItem(query.value(4).toString());
            item1->setTextAlignment(Qt::AlignCenter);
            ui->table_device_list->setItem(row, 4, item5);
       }
    }
    else{
        ui->lbl_stat_db->setText("Disconnected");  //Disconnected
        qDebug() << db.lastError().text();
    }
}



//START SERIAL
void MainWindow::init_serial(){

         serial->setPortName("ttyS0");
         serial->setBaudRate(QSerialPort::Baud115200);
         serial->setDataBits(QSerialPort::Data8);
         serial->setParity(QSerialPort::NoParity);
         serial->setStopBits(QSerialPort::OneStop);
         serial->setFlowControl(QSerialPort::NoFlowControl);

         if(serial->open(QIODevice::ReadWrite)){
               qDebug() << "COM connect\r\n";
              }
         else{
              //error
              QByteArray error = serial->errorString().toUtf8();
              qDebug() << error;
         }
}


void MainWindow::disconnected_COM(QSerialPort::SerialPortError error){


    if (error == QSerialPort::ResourceError){
        QMessageBox::critical(this,tr("Critical Error"), serial->errorString());
         qDebug() << "disconnected";
         serial->close();
    }
}

void MainWindow::checkAvailable() {
    if (serial->bytesAvailable() < 78) {
       if (!timer_Serial->isActive())
            timer_Serial->start();
    } else {
        processRead();
    }
}


void MainWindow::processRead() {

    QString RF_Address;
    QString ID_Button;
    QString data_String;
    QStringList data_to_pharse;

    timer_Serial->stop();
    serial->waitForReadyRead(100);
    QByteArray incomingData;

     serial->waitForReadyRead(10);
    incomingData.append(serial->readAll());
    while(serial->waitForReadyRead(100)){
        incomingData.append(serial->readAll());
    }

    if(incomingData.size()>5){
        qDebug() << "Received :" << incomingData;
        console->putData(incomingData);

        //Clear Data

        //Pharse
        data_String=tr("%1").arg((QString)incomingData);
        data_to_pharse=data_String.split("#");

        //Panggil
        if(data_to_pharse.at(0)=="DAT"){
            QString buttonID = tr("%1%2").arg(data_to_pharse.at(2)[0]).arg(data_to_pharse.at(2)[1]);
            Proses_panggilan(data_to_pharse.at(1),buttonID);
        }
        else if(data_to_pharse.at(0)=="WHO"){
           console->putData("WHO Process \r\n");
        }
    }

}

//END SERIAL

void MainWindow::load_Configuration(){
    qDebug() << "-----------------------  Init Settings -----------------------";
    QString debounce_str;

    QString dir = qApp->applicationDirPath();
    QString dirFile = tr("%1/%2").arg(dir).arg("setting.ini");

    QFile mInitFile(dirFile);
       if(!mInitFile.open(QIODevice::ReadWrite)){
           qDebug()<< ":Init Setting:Error...Couldn't open file";
       }

       else{
           QTextStream mInitText(&mInitFile);
           QString text=mInitText.readAll();

           int a=0;
           int x=0;

           for(x=0;x<512;x++){
              if(text[x]=='#'){
                 break;
              }
              IP_DB[a++]=text[x];
           }
           a=0;
           for(x=x+1;x<512;x++){
              if(text[x]=='#'){
                 break;
              }
              Username[a++]=text[x];
           }
           a=0;
           for(x=x+1;x<512;x++){
              if(text[x]=='#'){
                 break;
              }
              Password[a++]=text[x];
           }
           a=0;
           for(x=x+1;x<512;x++){
              if(text[x]=='#'){
                 break;
              }
              DB_Name[a++]=text[x];
           }
           a=0;
           for(x=x+1;x<512;x++){
              if(text[x]=='#'){
                 break;
              }
              IP_TCP[a++]=text[x];
           }
           a=0;
           for(x=x+1;x<512;x++){
              if(text[x]=='#'){
                 break;
              }
              Port_TCP[a++]=text[x];
           }
           a=0;
           for(x=x+1;x<512;x++){
              if(text[x]=='#'){
                 break;
              }
              ID_Group[a++]=text[x];
           }
           a=0;
           for(x=x+1;x<512;x++){
              if(text[x]=='#'){
                 break;
              }
              ID_Machine[a++]=text[x];
           }
           a=0;
           for(x=x+1;x<512;x++){
              if(text[x]=='#'){
                 break;
              }
              debounce_str[a++]=text[x];
           }

           ui->line_IP_DB->setText(IP_DB);
           ui->line_Username->setText(Username);
           ui->line_Password->setText(Password);
           ui->line_DB_Name->setText(DB_Name);
           ui->line_IP_TCP->setText(IP_TCP);
           ui->line_Port_TCP->setText(Port_TCP);
           ui->line_ID_Group->setText(ID_Group);
           ui->line_ID_MC->setText(ID_Machine);
           serviceGPIO->debouncetimer=debounce_str.toDouble();
           ui->spin_debounce->setValue(debounce_str.toInt());

           qDebug() << "Database Server   : " << IP_DB;
           qDebug() << "Database Username : " << Username;
           qDebug() << "Database Password : " << Password;
           qDebug() << "Database Name     : " << DB_Name;
           qDebug() << "TCP IP            : " << IP_TCP;
           qDebug() << "TCP Port          : " << Port_TCP;
           qDebug() << "ID Group Button   : " << ID_Group;
           qDebug() << "ID Machine        : " << ID_Machine;
           qDebug() << "Debounce Input    : " << serviceGPIO->debouncetimer;
       }
}

void MainWindow::on_btn_save_clicked()
{
    QString IP_DB_str, Username_str, Password_str,DB_Name_str,IP_TCP_str,Port_TCP_str,ID_Group_str,ID_MC_str,Debounce_str;
    QString Loc;

          Loc = qApp->applicationDirPath();
          //qDebug()<< Loc;
          QString Loc_Setting = (tr("%1/%2").arg(Loc).arg("setting.ini"));

          IP_DB_str = ui->line_IP_DB->text();
          Username_str = ui->line_Username->text();
          Password_str = ui->line_Password->text();
          DB_Name_str = ui->line_DB_Name->text();
          IP_TCP_str = ui->line_IP_TCP->text();
          Port_TCP_str = ui->line_Port_TCP->text();
          ID_Group_str = ui->line_ID_Group->text();
          ID_MC_str = ui->line_ID_MC->text();
          Debounce_str = ui->spin_debounce->text();



          QFile setting_save(Loc_Setting);
             if(setting_save.open(QIODevice::ReadWrite)){
                 QTextStream stream(&setting_save);
                 stream << IP_DB_str <<"#"<<Username_str<<"#"<<Password_str <<"#" <<DB_Name_str << "#" << IP_TCP_str <<"#" << Port_TCP_str  << "#" << ID_Group_str << "#" << ID_MC_str << "#" << Debounce_str << "#" <<endl;
                 }
}

void MainWindow::on_btn_clear_clicked()
{
    console->clear();
}


//ANDON
int MainWindow::check_device_list_exist(QString RFAddress){
    int valReturn=-1;

    int rows = ui->table_device_list->rowCount();
    bool founded = false;
    for(int i = 0; i < rows; ++i)
    {
        if(ui->table_device_list->item(i, 0)->text() == RFAddress)
        {
            //we have found our value so we can update 'i' row
            //qDebug() << "Row Data" << i;
            founded  = true;
            valReturn = i;
            break;
        }
    }
    if(!founded )
    {
        //we didn't find our value, so we can insert row
        valReturn=-1;
    }

    return valReturn;

}

int MainWindow::check_Memory(QString RFAddress, QString Button){
    int valReturn=-1;
    QString Button_last;
    QString DateTime_last;
    QString DateTime_now;

    QDateTime now = QDateTime::currentDateTime();
    QDateTime sec;

    int rows = ui->table_button_memory->rowCount();
    bool founded = false;
    for(int i = 0; i < rows; ++i)
    {
        if(ui->table_button_memory->item(i, 0)->text() == RFAddress)
        {

            Button_last = ui->table_button_memory->item(i,1)->text();
            DateTime_last = ui->table_button_memory->item(i,2)->text();


            sec = QDateTime::fromString(DateTime_last,"yyyy-MM-dd HH:mm:ss");

            if((sec.secsTo(now) > 2)){
               update_table_memory(i,Button);
               valReturn = 1;
            }
            else if(Button!=Button_last){
                console->putData("wait 2 second SKIP\r\n");
                valReturn = 0;

            }
            else{
                 console->putData("SKIP same button\r\n");
                 valReturn = 0;
            }

            //we have found our value so we can update 'i' row
            founded  = true;
            break;
        }
    }
    if(!founded )
    {
        //we didn't find our value, so we can insert row
        qDebug() << "belum ada di memory panggilan di proses";
        //Insert Data ROW
        insert_table_memory(RFAddress,Button);
        valReturn=1;
    }

    return valReturn;

}

void MainWindow::insert_table_memory(QString RFAddress, QString Button){

    QDateTime now = QDateTime::currentDateTime();
    QString now_string = now.toString("yyyy-MM-dd HH:mm:ss");
    const int rowAdder = ui->table_button_memory->rowCount();
    ui->table_button_memory->insertRow(rowAdder);
    QTableWidgetItem *T_RFAddress= new QTableWidgetItem(tr("%1").arg(RFAddress));
    ui->table_button_memory->setItem(rowAdder,0,T_RFAddress);
    QTableWidgetItem *T_Button= new QTableWidgetItem(tr("%1").arg(Button));
    ui->table_button_memory->setItem(rowAdder,1,T_Button);
    QTableWidgetItem *T_Datetime= new QTableWidgetItem(tr("%1").arg(now_string));
    ui->table_button_memory->setItem(rowAdder,2,T_Datetime);
}

void MainWindow::update_table_memory(int i, QString button){

    QDateTime now = QDateTime::currentDateTime();
    QString now_string = now.toString("yyyy-MM-dd HH:mm:ss");

    QTableWidgetItem *T_Button= new QTableWidgetItem(tr("%1").arg(button));
    ui->table_button_memory->setItem(i,1,T_Button);
    QTableWidgetItem *T_Datetime= new QTableWidgetItem(tr("%1").arg(now_string));
    ui->table_button_memory->setItem(i,2,T_Datetime);

}

void MainWindow::Proses_panggilan(QString RFAddress, QString ButtonID){

int flag_proses;
 flag_proses = check_Memory(RFAddress,ButtonID);

    if(flag_proses==1){
        int Row = check_device_list_exist(RFAddress);
        if(Row!=-1){
           QString call_id_button;
           qDebug() << "Received" << ButtonID;

           //call id
           // Quality Check 02 -> 4
           // Material Andon 01 -> 2
           // Machine Andon 04 -> 1
           // Quality Andon 08 -> 3

           if(ButtonID=="01"){  //
              call_id_button="2";
           }
           else if(ButtonID=="02"){ //
              call_id_button="4";
           }
           else if(ButtonID=="04"){ //
              call_id_button="1";
           }
           else if(ButtonID=="08"){  //
              call_id_button="3";
           }
           else {
              call_id_button="0";
           }

           QString MC_ID, POS_ID;
           MC_ID = ui->table_device_list->item(Row, 3)->text();
           POS_ID = ui->table_device_list->item(Row, 4)->text();

            console->putData("RF Terdaftar\r\n");
            Panggil(RFAddress, call_id_button, MC_ID, POS_ID);
        }
        else{
            console->putData("RF Tidak Terdaftar\r\n");
        }
     }

}

void MainWindow::Panggil(QString RFAddress, QString ButtonID, QString MC_ID, QString Pos_ID){
    QString prepare_get;
    QString call_id;  //nama panggilan dari button 1,2,4,8 di ubah 1,2,3,4
    QString datetime;
    QString Status_id;
    double flag_search=0;

    //call id
    // Quality Check 2
    // Material Andon 1
    // Machine Andon 4
    // Quality Andon 8

    //Status id
    // 1 Call
    // 2 Arrive
    // 3 Complete

    QSqlQuery query(db);

    if(db.open()){
        ui->lbl_stat_db->setText("Connected");  //Connected
        //qDebug() <<tr("RF Address : %1 | ID Button : %2 | MC ID : %3  | POS ID : %4 \r\n").arg(RFAddress).arg(ButtonID).arg(MC_ID).arg(Pos_ID);

        //Check last Status Button
        query.prepare(tr("SELECT COUNT(*) FROM itx_t_andon WHERE rf_address ='%1' AND andon_call_id='%2' AND andon_status_id<>'4' AND andon_status_id<>'3' AND Machine_id='%3' AND pos_id='%4'")
                      .arg(RFAddress).arg(ButtonID).arg(MC_ID).arg(Pos_ID));
                    query.exec();
        while (query.next()) {
           flag_search = query.value(0).toDouble();
        }

        if(flag_search>0){
            QString Last_ID;
            //Check Last status ID
            query.prepare(tr("SELECT andon_status_id from itx_t_andon where rf_address='%1' AND Machine_id='%2' AND pos_id='%3' AND andon_call_id='%4' order by datetime desc LIMIT 1 ")
                          .arg(RFAddress).arg(MC_ID).arg(Pos_ID).arg(ButtonID));
            query.exec();

            while (query.next()) {
               Last_ID = query.value(0).toString();
            }

            if(Last_ID=="1"){
                console->putData("Arrive\r\n");
                //IF Last 1 (Call) -> Arrive
                query.prepare(tr("UPDATE itx_t_andon SET time_arrival=CURRENT_TIMESTAMP, andon_status_id='2' WHERE RF_ADDRESS='%1' AND andon_call_id='%2'  AND andon_status_id='1' AND time_arrival='0000-00-00 00:00:00'")
                              .arg(RFAddress).arg(ButtonID));
                query.exec();

            }
            else if(Last_ID=="2"){
                console->putData("Complete\r\n");
                //IF Last 2 (Arrive) -> Complete
                query.prepare(tr("UPDATE itx_t_andon SET time_finish=CURRENT_TIMESTAMP, andon_status_id='3' WHERE RF_ADDRESS='%1' AND andon_call_id='%2'  AND andon_status_id='2' AND time_finish='0000-00-00 00:00:00'")
                              .arg(RFAddress).arg(ButtonID));
                query.exec();

            }
            else{

            }
        }
        else{
            //Make Call
            console->putData("Call\r\n");
            query.prepare(tr("Insert into itx_t_andon "
                             "(`rf_address`,`machine_id`,`pos_id`,`andon_call_id`,`andon_status_id`,`datetime`,`createDate`)"
                             "VALUES"
                             "('%1','%2','%3','%4','1',CURRENT_TIMESTAMP,CURRENT_TIMESTAMP)").arg(RFAddress).arg(MC_ID).arg(Pos_ID).arg(ButtonID));
            query.exec();

        }

    }
    else{
        ui->lbl_stat_db->setText("Disconnected");  //Disconnected
        qDebug() << db.lastError().text();
    }
}
