#include "readgpio.h"
#include <wiringPi.h>
#include <QDebug>

ReadGpio::ReadGpio(QObject *parent) : QObject(parent)
{
    wiringPiSetup();
    pinMode(12,INPUT);
    //IO SCAN

    keytimerIn=0;
}

void ReadGpio::read_input(){
    while(1){
        inputIn = digitalRead(12);

        if(inputIn!=input_compare){
            if(inputIn>input_compare){
                if(keytimerIn>debouncetimer){
                    qDebug() << "Counter Signal";
                    emit Signal_In(QString("1"));
                 //Input_counter();
                }
                else{
                    qDebug() << "error";
                }
                keytimerIn=0;

            }
            else if(inputIn<input_compare){
                 //qDebug() << "B";
            }

            input_compare=inputIn;
        }

        if(inputIn==1){
            //    keytimer1++;
                //qDebug() << "high";
        }
        else {
             keytimerIn++;
                //qDebug() << "low";
        }
    }

}
