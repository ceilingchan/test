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

//simple Tcp �����
class TcpServer : public QWidget
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = nullptr);
    ~TcpServer();

private:
    //��ʼ��server����
    void initServer();
    //close server
    void closeServer();
    //���µ�ǰ״̬
    void updateState();
    //ת�����ݸ�ʽ
    QString text2Show(const QString &text);

private:
    Ui::TcpServerClass *ui;
    //server���ڼ����˿ڣ���ȡ�µ�tcp���ӵ�������
    QTcpServer *server;
    //�洢�����ӵ�socket����
    QList<QTcpSocket*> clientList;
};

#endif // TCPSERVER_H
