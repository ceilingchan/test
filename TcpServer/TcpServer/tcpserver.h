#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QtWidgets/QWidget>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
    class TcpServerClass;
}
QT_END_NAMESPACE

//simple Tcp 服务端
class TcpServer : public QWidget
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = nullptr);
    ~TcpServer();

private:
    //初始化server操作
    void initServer();
    //close server
    void closeServer();
    //更新当前状态
    void updateState();
    //转换数据格式
    QString text2Show(const QString &text);

private:
    Ui::TcpServerClass *ui;
    //server用于监听端口，获取新的tcp连接的描述符
    QTcpServer *server;
    //存储已连接的socket对象
    QList<QTcpSocket*> clientList;
};

#endif // TCPSERVER_H
