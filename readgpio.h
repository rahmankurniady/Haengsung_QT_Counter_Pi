#ifndef READGPIO_H
#define READGPIO_H

#include <QObject>

class ReadGpio : public QObject
{
    Q_OBJECT
public:
    explicit ReadGpio(QObject *parent = 0);
    double keytimerIn_1,keytimerIn_2,keytimerIn_3;
    double debouncetimer;
    unsigned int inputIn_1,inputIn_2,inputIn_3;
    unsigned int input_compare_1,input_compare_2,input_compare_3;

signals:
    void Signal_In(const QString &value);

public slots:
    void read_input();
};

#endif // READGPIO_H
