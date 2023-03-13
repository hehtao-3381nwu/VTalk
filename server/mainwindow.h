#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QtNetwork>
#pragma execution_character_set("utf-8")
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int now_connect;
    void initialization();
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket=nullptr;
    QList<QTcpSocket *> tcpCLientList;
    void sendMessage(QString key, QString msg);
    QList<QString> unpacking(QByteArray msg);

private slots:
    void onNewConnection();
    void on_btn_Start_clicked();
    void onClientConnected();
    void onClientDisconnected();
    void onSocketReadyRead();
    void on_btn_Stop_clicked();
    void on_btn_cleartext_clicked();
    void on_btn_Send_clicked();
};

#endif // MAINWINDOW_H
