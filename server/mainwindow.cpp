#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialization();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialization()
{
    //获取本机所有可用IP地址
	QList<QHostAddress> list = QNetworkInterface::allAddresses();
    for(auto address:list)
        if (address.protocol() == QAbstractSocket::IPv4Protocol)
            ui->comboBox_IP->addItem(address.toString());
    
    ui->btn_Stop->setEnabled(false);
    ui->comboBox_connection->setEnabled(false);
    ui->edit_message->setEnabled(false);
	ui->btn_Send->setEnabled(false);
    ui->lab_state->setText(u8"停止");
    now_connect = 0;
    ui->lab_connectnumber->setText(QString::number(now_connect));
	
    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

/// <summary>
/// 点击:"开始监听"按钮
/// </summary>
void MainWindow::on_btn_Start_clicked()
{
    QString IP = ui->comboBox_IP->currentText();
    quint16 port = ui->spinBox_ports->value();
    QHostAddress addr(IP);
    if (tcpServer->listen(addr, port))
    {
        ui->appendPlainText->append("**开始监听...");
        ui->appendPlainText->append("**服务器地址:" + tcpServer->serverAddress().toString());
        ui->appendPlainText->append("**服务器端口:"+QString::number(tcpServer->serverPort()));

        ui->spinBox_ports->setValue(tcpServer->serverPort());
        ui->btn_Start->setEnabled(false);
        ui->btn_Stop->setEnabled(true);
        ui->spinBox_ports->setEnabled(false);
        ui->comboBox_IP->setEnabled(false);
        ui->lab_state->setText("正在监听");
        ui->comboBox_connection->setEnabled(true);
        ui->edit_message->setEnabled(true);
        ui->btn_Send->setEnabled(true);
        return;
    }
    ui->appendPlainText->append("**错误:无法开始监听");
    ui->lab_state->setText("错误");
}

/// <summary>
/// 槽:新的客户端接入
/// </summary>
void MainWindow::onNewConnection()
{
    tcpSocket = tcpServer->nextPendingConnection();
    tcpCLientList.append(tcpSocket);
    ++now_connect;
    ui->lab_connectnumber->setText(QString::number(now_connect));

    //将客户端的IP和端口号加入到comboBox_connection
    QString clientInfo = tr("%1:%2")
        .arg(tcpSocket->peerAddress().toString())
        .arg(tcpSocket->peerPort());
    ui->comboBox_connection->addItem(clientInfo);

    onClientConnected();
	
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));	
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
}

void MainWindow::onClientConnected()
{
    //先保存当前正在聊天的对象
    QString address = ui->comboBox_connection->currentText().split(":")[0];//保存IP
    int socket = ui->comboBox_connection->currentText().split(":")[1].toInt();//保存端口号
    
    //将侦听到的新的IP和端口号赋值给新窗口
    QString msg = "";
    msg.append(tcpSocket->peerAddress().toString());
    msg.append(":");
    msg.append(QString::number(tcpSocket->peerPort()));
    ui->comboBox_connection->setCurrentText(msg);

    //输出连接的新客户端
    ui->appendPlainText->append("**连接到客户端");
    ui->appendPlainText->anchorClicked("**IP地址:" + tcpSocket->peerAddress().toString());
    ui->appendPlainText->anchorClicked("**端口:" + QString::number((tcpSocket->peerPort())));
    ui->lab_state->setText("已连接");

    //发送数据
    sendMessage("10", ui->edit_name_my->text());

    //还原正在聊天的窗口
    msg = "";
    msg.append(address);
    msg.append(":");
    msg.append(socket);
    ui->comboBox_connection->setCurrentText(msg);
}

void MainWindow::onClientDisconnected()
{
    for (int i = 0; i < tcpCLientList.length(); i++) 
    {
        if (tcpCLientList[i]->state() == QAbstractSocket::UnconnectedState) 
        {
            QString clientInfo = tr("%1:%2")
                .arg(tcpCLientList[i]->peerAddress().toString())
                .arg(tcpCLientList[i]->peerPort());

            tcpCLientList[i]->destroyed();
            tcpCLientList.removeAt(i);

            ui->comboBox_connection->removeItem(ui->comboBox_connection->findText(clientInfo));
            ui->appendPlainText->append(tr("**客户端:%1 已脱机\n").arg(clientInfo));
            --now_connect;
            ui->lab_connectnumber->setText(QString::number(now_connect));
        }
    }
}

void MainWindow::onSocketReadyRead()
{
    //对方传来的数据格式：
    //数据传入的首两个字符为key值信息
    //10：消息内容为名称
    //11：消息内容为聊天记录
    QByteArray str_;
    for (int i = 0; i < tcpCLientList.length(); i++) 
    {
        QByteArray str_ = tcpCLientList[i]->readAll();
        if (str_.isEmpty()) {
            continue;
        }

        QList<QString> msgList = unpacking(str_);
        while (!msgList.isEmpty()) {
            QString msg = msgList.first();//读取拆包返回的第一个字符串
            if (msg.startsWith("10")) {//消息内容为名称
                msg.remove(0, 2);
                //ui->edit_name_other->setText(msg);
            }
            else if (msg.startsWith("11")) {//消息内容为数据
                msg.remove(0, 2);
                ui->appendPlainText->append(tr("收到来自[%1:%2]的信息：\n%3\n")
                    .arg(tcpCLientList[i]->peerAddress().toString())
                    .arg(tcpCLientList[i]->peerPort())
                    .arg(msg));
            }
            else {//消息内容未定义
            }
            msgList.removeFirst();//将第一个字符串出栈
        }
    }
}

void MainWindow::on_btn_Stop_clicked()
{
    if(tcpServer->isListening())
    {
        while(tcpCLientList.length() != 0)
            tcpCLientList[0]->disconnectFromHost();

        tcpServer->close();

        ui->btn_Start->setEnabled(true);
        ui->btn_Stop->setEnabled(false);
        ui->lab_state->setText("停止");
        ui->comboBox_IP->setEnabled(true);
        ui->spinBox_ports->setEnabled(true);
        ui->appendPlainText->append("**停止监听");
        now_connect = 0;
        ui->lab_connectnumber->setText(QString::number(now_connect));
        ui->comboBox_connection->setEnabled(false);
        ui->edit_message->setEnabled(false);
        ui->btn_Send->setEnabled(false);
    }
    else
    {
        ui->appendPlainText->append("**没有连接的服务");
    }
}

void MainWindow::on_btn_cleartext_clicked()
{
    ui->appendPlainText->clear();
}

void MainWindow::on_btn_Send_clicked()
{
    //确认目前有正在通信的客户端
    if (tcpServer->isListening() && tcpSocket != nullptr && tcpSocket->state() == QAbstractSocket::ConnectedState) {
        sendMessage("10", ui->edit_name_my->text());

        QString msg = ui->edit_message->text();
        sendMessage("11", msg);//函数里会再次确认一次

        //更改ui界面
        ui->appendPlainText->append(tr("向[%1]发送信息：\n%2\n")
            .arg(ui->comboBox_connection->currentText())
            .arg(msg));
        ui->edit_message->clear();
        ui->edit_message->setFocus();//将鼠标指针移到文本框
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

    //确认目前有正在通信的客户端
    if (tcpServer->isListening() && tcpSocket != nullptr && tcpSocket->state() == QAbstractSocket::ConnectedState) {
        if (msg.isEmpty()) {//排除空串
            return;
        }

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

        QString clientIP = ui->comboBox_connection->currentText().split(":")[0];//设置IP
        int clientPort = ui->comboBox_connection->currentText().split(":")[1].toInt();//设置端口号

        //寻找发送对象(遍历所有已连接对象，查找目标)
        for (int i = 0; i < tcpCLientList.length(); i++)
        {
            //peerAddress()功能：如果套接字处于ConnectedState，则返回已连接对等方的地址；否则返回QHostAddress：Null
            if (tcpCLientList[i]->peerAddress().toString() == clientIP && tcpCLientList[i]->peerPort() == clientPort)
            {
                tcpCLientList[i]->write(str);
                //ui->appendPlainText->append("[TEST][sendMessage][str]\n" + str);
                //ui->appendPlainText->append("[TEST][sendMessage][QString(str)]\n" + QString(str));
                return;
            }
        }
    }
    else {
        ui->appendPlainText->append("**未连接到客户端");
        ui->edit_message->clear();
    }
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