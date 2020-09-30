/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QLabel *lbl_counter_In;
    QLabel *label_19;
    QLabel *lbl_counter_table;
    QLabel *label_15;
    QLabel *lbl_counter_out;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_17;
    QLabel *label_18;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QPushButton *btn_clear;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *table_device_list;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_3;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *lbl_IP_DB;
    QLineEdit *line_IP_DB;
    QLabel *lbl_Username;
    QLineEdit *line_Username;
    QLabel *lbl_Password;
    QLineEdit *line_Password;
    QLabel *lbl_DB_Name;
    QLineEdit *line_DB_Name;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *lbl_IP_TCP;
    QLineEdit *line_IP_TCP;
    QLabel *lbl_Port_TCP;
    QLineEdit *line_Port_TCP;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_4;
    QLabel *label_6;
    QLineEdit *line_ID_Group;
    QLineEdit *line_ID_MC;
    QLabel *label_3;
    QGroupBox *groupBox_4;
    QFormLayout *formLayout_5;
    QLabel *label_12;
    QSpinBox *spin_debounce;
    QPushButton *btn_save;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *table_button_memory;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *lbl_stat_tcp;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *lbl_stat_db;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(621, 472);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_6 = new QVBoxLayout(tab_4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_14);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_13);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_5->addWidget(label_9);

        lbl_counter_In = new QLabel(tab_4);
        lbl_counter_In->setObjectName(QStringLiteral("lbl_counter_In"));
        lbl_counter_In->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lbl_counter_In);

        label_19 = new QLabel(tab_4);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_5->addWidget(label_19);

        lbl_counter_table = new QLabel(tab_4);
        lbl_counter_table->setObjectName(QStringLiteral("lbl_counter_table"));
        lbl_counter_table->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lbl_counter_table);

        label_15 = new QLabel(tab_4);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_5->addWidget(label_15);

        lbl_counter_out = new QLabel(tab_4);
        lbl_counter_out->setObjectName(QStringLiteral("lbl_counter_out"));
        lbl_counter_out->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lbl_counter_out);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_4->addWidget(label_10);

        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_4->addWidget(label_11);

        label_17 = new QLabel(tab_4);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_4->addWidget(label_17);

        label_18 = new QLabel(tab_4);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_4->addWidget(label_18);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_6->addLayout(verticalLayout_5);

        stackedWidget = new QStackedWidget(tab_4);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout_6->addWidget(stackedWidget);

        btn_clear = new QPushButton(tab_4);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));

        verticalLayout_6->addWidget(btn_clear);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        table_device_list = new QTableWidget(tab);
        if (table_device_list->columnCount() < 5)
            table_device_list->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_device_list->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_device_list->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_device_list->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_device_list->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_device_list->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        table_device_list->setObjectName(QStringLiteral("table_device_list"));
        table_device_list->horizontalHeader()->setStretchLastSection(true);
        table_device_list->verticalHeader()->setStretchLastSection(false);

        verticalLayout_2->addWidget(table_device_list);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lbl_IP_DB = new QLabel(groupBox);
        lbl_IP_DB->setObjectName(QStringLiteral("lbl_IP_DB"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lbl_IP_DB);

        line_IP_DB = new QLineEdit(groupBox);
        line_IP_DB->setObjectName(QStringLiteral("line_IP_DB"));

        formLayout->setWidget(0, QFormLayout::FieldRole, line_IP_DB);

        lbl_Username = new QLabel(groupBox);
        lbl_Username->setObjectName(QStringLiteral("lbl_Username"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lbl_Username);

        line_Username = new QLineEdit(groupBox);
        line_Username->setObjectName(QStringLiteral("line_Username"));

        formLayout->setWidget(1, QFormLayout::FieldRole, line_Username);

        lbl_Password = new QLabel(groupBox);
        lbl_Password->setObjectName(QStringLiteral("lbl_Password"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lbl_Password);

        line_Password = new QLineEdit(groupBox);
        line_Password->setObjectName(QStringLiteral("line_Password"));

        formLayout->setWidget(2, QFormLayout::FieldRole, line_Password);

        lbl_DB_Name = new QLabel(groupBox);
        lbl_DB_Name->setObjectName(QStringLiteral("lbl_DB_Name"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lbl_DB_Name);

        line_DB_Name = new QLineEdit(groupBox);
        line_DB_Name->setObjectName(QStringLiteral("line_DB_Name"));

        formLayout->setWidget(3, QFormLayout::FieldRole, line_DB_Name);


        formLayout_3->setWidget(0, QFormLayout::LabelRole, groupBox);

        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        lbl_IP_TCP = new QLabel(groupBox_2);
        lbl_IP_TCP->setObjectName(QStringLiteral("lbl_IP_TCP"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lbl_IP_TCP);

        line_IP_TCP = new QLineEdit(groupBox_2);
        line_IP_TCP->setObjectName(QStringLiteral("line_IP_TCP"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, line_IP_TCP);

        lbl_Port_TCP = new QLabel(groupBox_2);
        lbl_Port_TCP->setObjectName(QStringLiteral("lbl_Port_TCP"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, lbl_Port_TCP);

        line_Port_TCP = new QLineEdit(groupBox_2);
        line_Port_TCP->setObjectName(QStringLiteral("line_Port_TCP"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, line_Port_TCP);


        formLayout_3->setWidget(0, QFormLayout::FieldRole, groupBox_2);

        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        formLayout_4 = new QFormLayout(groupBox_3);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_6);

        line_ID_Group = new QLineEdit(groupBox_3);
        line_ID_Group->setObjectName(QStringLiteral("line_ID_Group"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, line_ID_Group);

        line_ID_MC = new QLineEdit(groupBox_3);
        line_ID_MC->setObjectName(QStringLiteral("line_ID_MC"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, line_ID_MC);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_3);


        formLayout_3->setWidget(1, QFormLayout::LabelRole, groupBox_3);

        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        formLayout_5 = new QFormLayout(groupBox_4);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_12);

        spin_debounce = new QSpinBox(groupBox_4);
        spin_debounce->setObjectName(QStringLiteral("spin_debounce"));
        spin_debounce->setMaximum(9999999);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, spin_debounce);


        formLayout_3->setWidget(1, QFormLayout::FieldRole, groupBox_4);


        verticalLayout_3->addLayout(formLayout_3);

        btn_save = new QPushButton(tab_2);
        btn_save->setObjectName(QStringLiteral("btn_save"));

        verticalLayout_3->addWidget(btn_save);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        table_button_memory = new QTableWidget(tab_3);
        if (table_button_memory->columnCount() < 3)
            table_button_memory->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_button_memory->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_button_memory->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_button_memory->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        table_button_memory->setObjectName(QStringLiteral("table_button_memory"));
        table_button_memory->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_4->addWidget(table_button_memory);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        lbl_stat_tcp = new QLabel(centralWidget);
        lbl_stat_tcp->setObjectName(QStringLiteral("lbl_stat_tcp"));

        horizontalLayout->addWidget(lbl_stat_tcp);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lbl_stat_db = new QLabel(centralWidget);
        lbl_stat_db->setObjectName(QStringLiteral("lbl_stat_db"));

        horizontalLayout->addWidget(lbl_stat_db);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Haengsung Gateway", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "SPK ID", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Target", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Counter In :", Q_NULLPTR));
        lbl_counter_In->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Table :", Q_NULLPTR));
        lbl_counter_table->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Counter Out :", Q_NULLPTR));
        lbl_counter_out->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Stat Counter In", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Enabled", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Stat Counter Out", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Enabled", Q_NULLPTR));
        btn_clear->setText(QApplication::translate("MainWindow", "Clear Log", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Home", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = table_device_list->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "RF Address", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = table_device_list->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Group ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = table_device_list->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Device ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = table_device_list->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "MC_ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = table_device_list->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Pos_ID", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "DeviceList", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Database", Q_NULLPTR));
        lbl_IP_DB->setText(QApplication::translate("MainWindow", "IP", Q_NULLPTR));
        lbl_Username->setText(QApplication::translate("MainWindow", "Username", Q_NULLPTR));
        lbl_Password->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        lbl_DB_Name->setText(QApplication::translate("MainWindow", "DBName", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "TCP", Q_NULLPTR));
        lbl_IP_TCP->setText(QApplication::translate("MainWindow", "IP", Q_NULLPTR));
        lbl_Port_TCP->setText(QApplication::translate("MainWindow", "Port", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Gateway Setting", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "ID Group   ", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "ID MC", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Counter Setting", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Debounce", Q_NULLPTR));
        btn_save->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = table_button_memory->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "RF Address", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = table_button_memory->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Last ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = table_button_memory->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Time Last", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Last Memory", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "TCP :", Q_NULLPTR));
        lbl_stat_tcp->setText(QApplication::translate("MainWindow", "Disconnected", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Database :", Q_NULLPTR));
        lbl_stat_db->setText(QApplication::translate("MainWindow", "Disconnected", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
