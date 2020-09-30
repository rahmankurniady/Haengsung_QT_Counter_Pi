#include "readgpio.h"
#include <wiringPi.h>
#include <QDebug>
#include <QThread>

ReadGpio::ReadGpio(QObject *parent) : QObject(parent)
{
    wiringPiSetup();
    pinMode(12,INPUT);
    pinMode(13,INPUT);
    pinMode(14,INPUT);
    //IO SCAN
    input_compare_1 = digitalRead(12);
    input_compare_2 = digitalRead(13);
    input_compare_3 = digitalRead(14);

    keytimerIn_1=0;
    keytimerIn_2=0;
    keytimerIn_3=0;

    //Signal_In 1 -> Input
    //Signal_In 2 -> Table
    //Signal_In 3 -> Output
}

void ReadGpio::read_input(){
    while(1){
        inputIn_1 = digitalRead(12);
        inputIn_2 = digitalRead(13);
        inputIn_3 = digitalRead(14);

        if(inputIn_1!=input_compare_1){
            if(inputIn_1>input_compare_1){
                if(keytimerIn_1>debouncetimer){
                    qDebug() << "Counter Signal";
                    emit Signal_In(QString("1"));
                }
                else{
                    qDebug() << "error";
                }
                keytimerIn_1=0;
            }
            else if(inputIn_1<input_compare_1){
            }

            input_compare_1=inputIn_1;
        }
        if(inputIn_1==1){
            //    keytimerIn_1++;
                //qDebug() << "high";
        }
        else {
             keytimerIn_1++;
                //qDebug() << "low";
        }

        if(inputIn_2!=input_compare_2){
            if(inputIn_2>input_compare_2){
                if(keytimerIn_2>debouncetimer){
                    qDebug() << "Counter Signal";
                    emit Signal_In(QString("2"));
                }
                else{
                    qDebug() << "error";
                }
                keytimerIn_2=0;
            }
            else if(inputIn_2<input_compare_2){
            }

            input_compare_2=inputIn_2;
        }
        if(inputIn_2==1){
            //    keytimerIn_2++;
                //qDebug() << "high";
        }
        else {
             keytimerIn_2++;
                //qDebug() << "low";
        }

        if(inputIn_3!=input_compare_3){
            if(inputIn_3>input_compare_3){
                if(keytimerIn_3>debouncetimer){
                    qDebug() << "Counter Signal";
                    emit Signal_In(QString("3"));
                }
                else{
                    qDebug() << "error";
                }
                keytimerIn_3=0;
            }
            else if(inputIn_3<input_compare_3){
            }

            input_compare_3=inputIn_3;
        }
        if(inputIn_3==1){
            //    keytimerIn_3++;
                //qDebug() << "high";
        }
        else {
             keytimerIn_3++;
                //qDebug() << "low";
        }
    QThread::msleep(1);
    }
}

