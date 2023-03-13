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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextBrowser *appendPlainText;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *lab_State;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *edit_addr;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QSpinBox *Spin_ports;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_connect;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_discon;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_cleartext;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *edit_Msg;
    QPushButton *btn_Send;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *edit_name_my;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *edit_name_other;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(416, 366);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        appendPlainText = new QTextBrowser(centralwidget);
        appendPlainText->setObjectName(QString::fromUtf8("appendPlainText"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(appendPlainText->sizePolicy().hasHeightForWidth());
        appendPlainText->setSizePolicy(sizePolicy);

        gridLayout->addWidget(appendPlainText, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lab_State = new QLabel(centralwidget);
        lab_State->setObjectName(QString::fromUtf8("lab_State"));

        horizontalLayout->addWidget(lab_State);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        edit_addr = new QLineEdit(centralwidget);
        edit_addr->setObjectName(QString::fromUtf8("edit_addr"));

        horizontalLayout_3->addWidget(edit_addr);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        Spin_ports = new QSpinBox(centralwidget);
        Spin_ports->setObjectName(QString::fromUtf8("Spin_ports"));
        Spin_ports->setMaximum(65535);

        horizontalLayout_3->addWidget(Spin_ports);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btn_connect = new QPushButton(centralwidget);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));

        horizontalLayout_4->addWidget(btn_connect);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        btn_discon = new QPushButton(centralwidget);
        btn_discon->setObjectName(QString::fromUtf8("btn_discon"));

        horizontalLayout_4->addWidget(btn_discon);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        btn_cleartext = new QPushButton(centralwidget);
        btn_cleartext->setObjectName(QString::fromUtf8("btn_cleartext"));

        horizontalLayout_4->addWidget(btn_cleartext);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        edit_Msg = new QLineEdit(centralwidget);
        edit_Msg->setObjectName(QString::fromUtf8("edit_Msg"));

        horizontalLayout_2->addWidget(edit_Msg);

        btn_Send = new QPushButton(centralwidget);
        btn_Send->setObjectName(QString::fromUtf8("btn_Send"));

        horizontalLayout_2->addWidget(btn_Send);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        edit_name_my = new QLineEdit(centralwidget);
        edit_name_my->setObjectName(QString::fromUtf8("edit_name_my"));

        horizontalLayout_6->addWidget(edit_name_my);


        gridLayout->addLayout(horizontalLayout_6, 5, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        edit_name_other = new QLineEdit(centralwidget);
        edit_name_other->setObjectName(QString::fromUtf8("edit_name_other"));

        horizontalLayout_5->addWidget(edit_name_other);


        gridLayout->addLayout(horizontalLayout_5, 6, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "socket\347\212\266\346\200\201\357\274\232", nullptr));
        lab_State->setText(QCoreApplication::translate("MainWindow", "labSocketState", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243:", nullptr));
        btn_connect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        btn_discon->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        btn_cleartext->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
        btn_Send->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\346\230\265\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\257\271\346\226\271\346\230\265\347\247\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
