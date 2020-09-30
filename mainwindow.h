#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QTimer>
#include <QtSql/QSqlDatabase>
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>
#include "wiringPi.h"
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}
class Console;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString IP_DB, Username, Password, DB_Name;
    QString IP_TCP, Port_TCP;
    QString ID_Group;
    QString ID_Machine;


public slots:
    void init_serial();
    void disconnected_COM(QSerialPort::SerialPortError error);
    void checkAvailable();
    void processRead();
    void load_Configuration();

    void init_Counter();
    void Count_Up(QString value);
    void Update_Counter();
    void Update_Table_Counter();

    void init_db();
    void init_devicelist();

    void Read_Clock();

    int check_device_list_exist(QString RFAddress);
    int check_Memory(QString RFAddress, QString Button);
    void insert_table_memory(QString RFAddress, QString Button);
    void update_table_memory(int i, QString button);
    void Proses_panggilan(QString RFAddress, QString ButtonID);
    void Panggil(QString RFAddress, QString ButtonID, QString MC_ID, QString Pos_ID);

private slots:
    void on_btn_save_clicked();

    void on_btn_clear_clicked();

    void keyPressEvent(QKeyEvent * event);


private:
    Ui::MainWindow *ui;
    Console *console;
    QSerialPort *serial;
    QTimer *timer_Serial;
    QSqlDatabase db;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
