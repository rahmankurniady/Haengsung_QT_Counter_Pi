#ifndef READGPIO_H
#define READGPIO_H

#include <QObject>

class ReadGpio : public QObject
{
    Q_OBJECT
public:
    explicit ReadGpio(QObject *parent = 0);
    double keytimerIn;
    double debouncetimer;
    unsigned int inputIn;
    unsigned int input_compare;

signals:
    void Signal_In(const QString &value);

public slots:
    void read_input();
};

#endif // READGPIO_H
