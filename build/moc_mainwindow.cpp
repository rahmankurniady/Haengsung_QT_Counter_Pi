/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[35];
    char stringdata0[443];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "init_serial"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16), // "disconnected_COM"
QT_MOC_LITERAL(4, 41, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(5, 70, 5), // "error"
QT_MOC_LITERAL(6, 76, 14), // "checkAvailable"
QT_MOC_LITERAL(7, 91, 11), // "processRead"
QT_MOC_LITERAL(8, 103, 18), // "load_Configuration"
QT_MOC_LITERAL(9, 122, 12), // "init_Counter"
QT_MOC_LITERAL(10, 135, 8), // "Count_Up"
QT_MOC_LITERAL(11, 144, 5), // "value"
QT_MOC_LITERAL(12, 150, 14), // "Update_Counter"
QT_MOC_LITERAL(13, 165, 20), // "Update_Table_Counter"
QT_MOC_LITERAL(14, 186, 7), // "init_db"
QT_MOC_LITERAL(15, 194, 15), // "init_devicelist"
QT_MOC_LITERAL(16, 210, 10), // "Read_Clock"
QT_MOC_LITERAL(17, 221, 23), // "check_device_list_exist"
QT_MOC_LITERAL(18, 245, 9), // "RFAddress"
QT_MOC_LITERAL(19, 255, 12), // "check_Memory"
QT_MOC_LITERAL(20, 268, 6), // "Button"
QT_MOC_LITERAL(21, 275, 19), // "insert_table_memory"
QT_MOC_LITERAL(22, 295, 19), // "update_table_memory"
QT_MOC_LITERAL(23, 315, 1), // "i"
QT_MOC_LITERAL(24, 317, 6), // "button"
QT_MOC_LITERAL(25, 324, 16), // "Proses_panggilan"
QT_MOC_LITERAL(26, 341, 8), // "ButtonID"
QT_MOC_LITERAL(27, 350, 7), // "Panggil"
QT_MOC_LITERAL(28, 358, 5), // "MC_ID"
QT_MOC_LITERAL(29, 364, 6), // "Pos_ID"
QT_MOC_LITERAL(30, 371, 19), // "on_btn_save_clicked"
QT_MOC_LITERAL(31, 391, 20), // "on_btn_clear_clicked"
QT_MOC_LITERAL(32, 412, 13), // "keyPressEvent"
QT_MOC_LITERAL(33, 426, 10), // "QKeyEvent*"
QT_MOC_LITERAL(34, 437, 5) // "event"

    },
    "MainWindow\0init_serial\0\0disconnected_COM\0"
    "QSerialPort::SerialPortError\0error\0"
    "checkAvailable\0processRead\0"
    "load_Configuration\0init_Counter\0"
    "Count_Up\0value\0Update_Counter\0"
    "Update_Table_Counter\0init_db\0"
    "init_devicelist\0Read_Clock\0"
    "check_device_list_exist\0RFAddress\0"
    "check_Memory\0Button\0insert_table_memory\0"
    "update_table_memory\0i\0button\0"
    "Proses_panggilan\0ButtonID\0Panggil\0"
    "MC_ID\0Pos_ID\0on_btn_save_clicked\0"
    "on_btn_clear_clicked\0keyPressEvent\0"
    "QKeyEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x0a /* Public */,
       3,    1,  120,    2, 0x0a /* Public */,
       6,    0,  123,    2, 0x0a /* Public */,
       7,    0,  124,    2, 0x0a /* Public */,
       8,    0,  125,    2, 0x0a /* Public */,
       9,    0,  126,    2, 0x0a /* Public */,
      10,    1,  127,    2, 0x0a /* Public */,
      12,    0,  130,    2, 0x0a /* Public */,
      13,    0,  131,    2, 0x0a /* Public */,
      14,    0,  132,    2, 0x0a /* Public */,
      15,    0,  133,    2, 0x0a /* Public */,
      16,    0,  134,    2, 0x0a /* Public */,
      17,    1,  135,    2, 0x0a /* Public */,
      19,    2,  138,    2, 0x0a /* Public */,
      21,    2,  143,    2, 0x0a /* Public */,
      22,    2,  148,    2, 0x0a /* Public */,
      25,    2,  153,    2, 0x0a /* Public */,
      27,    4,  158,    2, 0x0a /* Public */,
      30,    0,  167,    2, 0x08 /* Private */,
      31,    0,  168,    2, 0x08 /* Private */,
      32,    1,  169,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString,   18,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,   18,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   18,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   23,   24,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   18,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   26,   28,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 33,   34,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->init_serial(); break;
        case 1: _t->disconnected_COM((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 2: _t->checkAvailable(); break;
        case 3: _t->processRead(); break;
        case 4: _t->load_Configuration(); break;
        case 5: _t->init_Counter(); break;
        case 6: _t->Count_Up((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->Update_Counter(); break;
        case 8: _t->Update_Table_Counter(); break;
        case 9: _t->init_db(); break;
        case 10: _t->init_devicelist(); break;
        case 11: _t->Read_Clock(); break;
        case 12: { int _r = _t->check_device_list_exist((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: { int _r = _t->check_Memory((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 14: _t->insert_table_memory((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: _t->update_table_memory((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 16: _t->Proses_panggilan((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 17: _t->Panggil((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 18: _t->on_btn_save_clicked(); break;
        case 19: _t->on_btn_clear_clicked(); break;
        case 20: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
