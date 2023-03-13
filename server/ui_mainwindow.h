/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_Start;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_Stop;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_cleartext;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_IP;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QSpinBox *spinBox_ports;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QComboBox *comboBox_connection;
    QLabel *label_7;
    QComboBox *comboBox_connection_name;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *edit_message;
    QPushButton *btn_Send;
    QTextBrowser *appendPlainText;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *lab_state;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *lab_connectnumber;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *edit_name_my;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(488, 398);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btn_Start = new QPushButton(centralwidget);
        btn_Start->setObjectName(QString::fromUtf8("btn_Start"));

        horizontalLayout_4->addWidget(btn_Start);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        btn_Stop = new QPushButton(centralwidget);
        btn_Stop->setObjectName(QString::fromUtf8("btn_Stop"));

        horizontalLayout_4->addWidget(btn_Stop);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        btn_cleartext = new QPushButton(centralwidget);
        btn_cleartext->setObjectName(QString::fromUtf8("btn_cleartext"));

        horizontalLayout_4->addWidget(btn_cleartext);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBox_IP = new QComboBox(centralwidget);
        comboBox_IP->setObjectName(QString::fromUtf8("comboBox_IP"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_IP->sizePolicy().hasHeightForWidth());
        comboBox_IP->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(comboBox_IP);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        spinBox_ports = new QSpinBox(centralwidget);
        spinBox_ports->setObjectName(QString::fromUtf8("spinBox_ports"));
        spinBox_ports->setMaximum(65535);

        horizontalLayout_3->addWidget(spinBox_ports);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_5);

        comboBox_connection = new QComboBox(centralwidget);
        comboBox_connection->setObjectName(QString::fromUtf8("comboBox_connection"));
        sizePolicy.setHeightForWidth(comboBox_connection->sizePolicy().hasHeightForWidth());
        comboBox_connection->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(comboBox_connection);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_7);

        comboBox_connection_name = new QComboBox(centralwidget);
        comboBox_connection_name->setObjectName(QString::fromUtf8("comboBox_connection_name"));
        sizePolicy.setHeightForWidth(comboBox_connection_name->sizePolicy().hasHeightForWidth());
        comboBox_connection_name->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(comboBox_connection_name);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        edit_message = new QLineEdit(centralwidget);
        edit_message->setObjectName(QString::fromUtf8("edit_message"));

        horizontalLayout_6->addWidget(edit_message);

        btn_Send = new QPushButton(centralwidget);
        btn_Send->setObjectName(QString::fromUtf8("btn_Send"));

        horizontalLayout_6->addWidget(btn_Send);


        verticalLayout->addLayout(horizontalLayout_6);

        appendPlainText = new QTextBrowser(centralwidget);
        appendPlainText->setObjectName(QString::fromUtf8("appendPlainText"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(appendPlainText->sizePolicy().hasHeightForWidth());
        appendPlainText->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(appendPlainText);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lab_state = new QLabel(centralwidget);
        lab_state->setObjectName(QString::fromUtf8("lab_state"));

        horizontalLayout->addWidget(lab_state);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lab_connectnumber = new QLabel(centralwidget);
        lab_connectnumber->setObjectName(QString::fromUtf8("lab_connectnumber"));

        horizontalLayout->addWidget(lab_connectnumber);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        edit_name_my = new QLineEdit(centralwidget);
        edit_name_my->setObjectName(QString::fromUtf8("edit_name_my"));

        horizontalLayout_5->addWidget(edit_name_my);


        verticalLayout->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\347\253\257", nullptr));
        btn_Start->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
        btn_Stop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\347\233\221\345\220\254", nullptr));
        btn_cleartext->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\233\221\345\220\254\345\234\260\345\235\200\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\233\221\345\220\254\347\253\257\345\217\243(\344\270\215\345\217\257\347\224\250\345\210\231\350\207\252\345\212\250\351\205\215\347\275\256):", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257\346\230\265\347\247\260\357\274\232", nullptr));
        btn_Send->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\214\347\212\266\346\200\201\357\274\232", nullptr));
        lab_state->setText(QCoreApplication::translate("MainWindow", "none", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\350\277\236\346\216\245\346\225\260\351\207\217\357\274\232", nullptr));
        lab_connectnumber->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\346\230\265\347\247\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
