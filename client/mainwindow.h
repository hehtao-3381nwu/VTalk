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

private slots:
    //按钮点击事件
    void on_btn_connect_clicked();
    void on_btn_discon_clicked();
    void on_btn_cleartext_clicked();
    void on_btn_Send_clicked();

    //状态触发事件
    void onConnected();
    void onDisconnected();
    void onSocketReadyRead();
    void onSocketStateChange(QAbstractSocket::SocketState socketState);

private:
    Ui::MainWindow *ui;
    QTcpSocket* tcpClient;
    void sendMessage(QString key, QString msg);
    QList<QString> unpacking(QByteArray msg);
};
#endif // MAINWINDOW_H
