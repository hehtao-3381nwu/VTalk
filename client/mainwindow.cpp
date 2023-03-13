#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QtNetwork>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpClient = new QTcpSocket(this);

    //设置按钮可见性
    ui->btn_connect->setEnabled(true);
    ui->btn_discon->setEnabled(false);
    ui->btn_Send->setEnabled(false);

    ui->lab_State->setText("未连接");

    connect(tcpClient, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(tcpClient, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(tcpClient, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/// <summary>
/// 槽:连接到服务器
/// </summary>
void MainWindow::onConnected()
{
    ui->appendPlainText->append("**已连接到服务器");
    ui->appendPlainText->append("**服务器地址:"+tcpClient->peerAddress().toString());
    ui->appendPlainText->append("端口:" + QString::number(tcpClient->peerPort()));

    //设置按钮是否可点击
    //true
    ui->btn_discon->setEnabled(true);
    ui->btn_Send->setEnabled(true);
    //false
    ui->btn_connect->setEnabled(false);
    ui->Spin_ports->setEnabled(false);
    ui->edit_addr->setEnabled(false);
}

/// <summary>
/// 点击:"连接服务器"按钮
/// </summary>
void MainWindow::on_btn_connect_clicked()
{
    QString addr = ui->edit_addr->text();//服务器地址
    quint16 port = ui->Spin_ports->value();//服务器端口号
    tcpClient->connectToHost(addr, port);

    //向对方发送自己的昵称
    sendMessage("10", ui->edit_name_my->text());
}

/// <summary> 
/// 点击:"断开连接"按钮
/// </summary>
void MainWindow::on_btn_discon_clicked()
{
    if (tcpClient->state() == QAbstractSocket::ConnectedState) {
        tcpClient->disconnectFromHost();
    }
}

/// <summary>
/// 点击:"清空文本框"按钮
/// </summary>
void MainWindow::on_btn_cleartext_clicked()
{
    ui->appendPlainText->clear();
}

/// <summary>
/// 点击:"发送消息"按钮
/// </summary>
void MainWindow::on_btn_Send_clicked()
{
    sendMessage("10", ui->edit_name_my->text());

    QString msg = ui->edit_Msg->text();
    sendMessage("11", msg);

    //更改ui界面
    ui->appendPlainText->append("[发送信息]\n" + msg +"\n");
    ui->edit_Msg->clear();
    ui->edit_Msg->setFocus();//将鼠标指针移到文本框
}

/// <summary>
/// 槽:收到消息
/// </summary>
void MainWindow::onSocketReadyRead()
{
    //对方传来的数据格式：
    //数据传入的首两个字符为key值信息
    //10：消息内容为名称
    //11：消息内容为聊天记录
    QByteArray str_ = tcpClient->readAll();
    //ui->appendPlainText->append("[TEST][onSocketReadyRead][str_]\n" + str_);
    QList<QString> msgList = unpacking(str_);
    //for(auto i : msgList)
        //ui->appendPlainText->append("[TEST][onSocketReadyRead][msgList]\n" + i);

    while (!msgList.isEmpty()) {
        QString msg = msgList.first();//读取拆包返回的第一个字符串
        //ui->appendPlainText->append("[TEST][onSocketReadyRead][msg]\n" + msg);
        if (msg.startsWith("10")) {//消息内容为名称
            msg.remove(0, 2);
            ui->edit_name_other->setText(msg);
        }
        else if (msg.startsWith("11")) {//消息内容为数据
            msg.remove(0, 2);
            ui->appendPlainText->append("[收到信息]\n" + msg + "\n");
        }
        else {//消息内容未定义
        }
        msgList.removeFirst();//将第一个字符串出栈
    }
}

/// <summary>
/// 槽:连接断开
/// </summary>
void MainWindow::onDisconnected()
{
    ui->appendPlainText->append("连接断开");
    ui->btn_connect->setEnabled(true);
    ui->Spin_ports->setEnabled(true);
    ui->edit_addr->setEnabled(true);
    ui->btn_discon->setDisabled(false);
    ui->btn_Send->setEnabled(false);
}

/// <summary>
/// 槽:状态更新
/// </summary>
/// <param name="socketState">套接字连接的状态</param>
void MainWindow::onSocketStateChange(QAbstractSocket::SocketState socketState)
{
    switch (socketState)
    {
    case QAbstractSocket::UnconnectedState:
        ui->lab_State->setText("未连接");break;
    case QAbstractSocket::HostLookupState:
        ui->lab_State->setText("正在执行主机名查找");break;
    case QAbstractSocket::ConnectingState:
        ui->lab_State->setText("正在建立连接");break;
    case QAbstractSocket::ConnectedState:
        ui->lab_State->setText("连接已建立"); break;
    case QAbstractSocket::BoundState:
        ui->lab_State->setText("已绑定");break;
    case QAbstractSocket::ClosingState:
        ui->lab_State->setText("即将关闭");break;
    case QAbstractSocket::ListeningState:
        ui->lab_State->setText("内部使用");break;
    }
}

/// <summary>
/// 向对方发送消息,顺带字符串的包装
/// </summary>
/// <param name="key">标识字符串的作用(格式：两个字符串)</param>
/// <param name="str">字符串(长度限制：0~99999999)</param>
void MainWindow::sendMessage(QString key, QString msg) {
    /**
     * 每个包首有一个8位的字符串标记此数据包的大小
     * key:10 发送自己的昵称
     * key:11 发送消息
     */

    //ui->appendPlainText->append("[TEST][sendMessage][source]\n" + msg);
    //构造要发送的消息串
    QByteArray temp = "";
    temp.append(key);//加入key
    temp.append(msg.toUtf8());
    //ui->appendPlainText->append("[TEST][sendMessage][temp]\n" + temp);

    //开始构造字符串
    QByteArray str = "";
    int32_t length = temp.size();//字符串长度
    str.append(QString("%1").arg(length, 8, 10, QChar('0')));//加入数据长度(头)
    str.append(temp);//加入处理过的信息体(体)

    tcpClient->write(str);
    //ui->appendPlainText->append("[TEST][sendMessage][str]\n" + str);
    //ui->appendPlainText->append("[TEST][sendMessage][QString(str)]\n" + QString(str));
}

/// <summary>
/// 将对方发送过来的数据包进行拆包
/// </summary>
/// <param name="msg">需要处理的数据包</param>
/// <returns>返回该数据包包含的信息</returns>
QList<QString> MainWindow::unpacking(QByteArray msg) {
    /**
     * 每个包首有一个8位的字符串标记此数据包的大小
     * key:10 发送自己的昵称
     * key:11 发送消息
     */

    //ui->appendPlainText->append("[TEST][unpacking][source]\n" + msg);
    QList<QString> qlist;
    if (msg.isEmpty()) {
        return qlist;
    }

    do {
        int32_t length = msg.mid(0, 8).toInt();//取出8个字符数据,为数据包大小
        //ui->appendPlainText->append("[TEST][unpacking][length]\n" + QString::number(length));
        QString str = msg.mid(8, length);
        qlist.append(str);
        //ui->appendPlainText->append("[TEST][unpacking][str]\n" + str);
        msg.remove(0, 8 + length);//将读取过的数据移除
    } while (!msg.isEmpty());

    return qlist;
}