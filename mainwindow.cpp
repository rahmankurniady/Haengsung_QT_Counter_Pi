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


QThread *mThread= new QThread();
ReadGpio *serviceGPIO = new ReadGpio();

double dummy_counter=0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    console = new Console;
    console->setEnabled(false);
    ui->stackedWidget->insertWidget(0,console);
    ui->stackedWidget->setCurrentIndex(0);
    console->setEnabled(true);

    serial = new QSerialPort(this);
    connect(serial,static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),this,&MainWindow::disconnected_COM);
    connect(serial,&QSerialPort::readyRead,this,&MainWindow::checkAvailable);

    timer_Serial= new QTimer(this);
    connect(timer_Serial, SIGNAL(timeout()), this, SLOT(processRead()));
    timer_Serial->setInterval(10);
    init_serial();


    load_Configuration();
    init_db();
    init_devicelist();


    /* Service Thread Read GPIO */
    serviceGPIO->debouncetimer=1000;
    serviceGPIO->moveToThread(mThread);
    connect(serviceGPIO, SIGNAL(Signal_In(QString)),this,SLOT(Count_Up(QString)));
    connect(mThread, SIGNAL(started()),serviceGPIO, SLOT(read_input()));
    mThread->start();




}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Void Process Signal Cunter */
void MainWindow::Count_Up(QString value){
    qDebug() << "count UP signal received" << value;
    dummy_counter++;
    ui->lbl_counter_In->setText(tr("%1").arg(dummy_counter));
}

/*  Database */
void MainWindow::init_db(){
    qDebug() << "------------------init_DB----------------";
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

    qDebug() << "---------------------Init Device List -----------------";

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
        //Pharse
        data_String=tr("%1").arg((QString)incomingData);
        data_to_pharse=data_String.split("#");

        //Panggil
        if(data_to_pharse.at(0)=="DAT"){
            Proses_panggilan(data_to_pharse.at(1),data_to_pharse.at(2));
        }
        else if(data_to_pharse.at(0)=="WHO"){
           console->putData("WHO Process \r\n");
        }
    }

}

//END SERIAL

void MainWindow::load_Configuration(){
    qDebug() << "init Settings";

    QString dir = qApp->applicationDirPath();
    QString dirFile = tr("%1/%2").arg(dir).arg("setting.ini");

    QFile mInitFile(dirFile);
       if(!mInitFile.open(QIODevice::ReadWrite)){
           qDebug()<< ":Init Setting:Error...Couldn't open file";
       }

       else{
           QTextStream mInitText(&mInitFile);
           QString text=mInitText.readAll();

           qDebug() << text;

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

           ui->line_IP_DB->setText(IP_DB);
           ui->line_Username->setText(Username);
           ui->line_Password->setText(Password);
           ui->line_DB_Name->setText(DB_Name);
           ui->line_IP_TCP->setText(IP_TCP);
           ui->line_Port_TCP->setText(Port_TCP);
           ui->line_ID_Group->setText(ID_Group);
           ui->line_ID_MC->setText(ID_Machine);
       }
}

void MainWindow::on_btn_save_clicked()
{
    QString IP_DB_str, Username_str, Password_str,DB_Name_str,IP_TCP_str,Port_TCP_str,ID_Group_str,ID_MC_str;
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



          QFile setting_save(Loc_Setting);
             if(setting_save.open(QIODevice::ReadWrite)){
                 QTextStream stream(&setting_save);
                 stream << IP_DB_str <<"#"<<Username_str<<"#"<<Password_str <<"#" <<DB_Name_str << "#" << IP_TCP_str <<"#" << Port_TCP_str  << "#" << ID_Group_str << "#" << ID_MC_str << "#" <<endl;
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
            console->putData("RF Terdaftar\r\n");
        }
        else{
            console->putData("RF Tidak Terdaftar\r\n");
        }
     }

}

void MainWindow::Panggil(){
    QString prepare_get;
     QString call_id;  //nama panggilan dari button 1,2,4,8 di ubah 1,2,3,4
     QString datetime;
     QString Status_id;
     double flag_search=0;

//    if(db.open){
//        ui->lbl_stat_db->setText("Connected");  //Connected
//    }
//    else{
//        ui->lbl_stat_db->setText("Disconnected");  //Disconnected
//        qDebug() << db.lastError().text();
//    }
}
