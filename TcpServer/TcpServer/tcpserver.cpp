#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QHostAddress>

TcpServer::TcpServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpServerClass)
{
    ui->setupUi(this);
    setWindowTitle("Server");
    initServer();
}

TcpServer::~TcpServer()
{
    //�ر�server
    closeServer();
    delete ui;
}

void TcpServer::initServer()
{
    //����Server����
    server = new QTcpServer(this);

    //���������ť����ʼ����
    connect(ui->btnListen, &QPushButton::clicked, [this] {
        //�жϵ�ǰ�Ƿ��ѿ���������close������listen
        if (server->isListening()) {
            //server->close();
            closeServer();
            //�ر�server��ָ�����״̬
            ui->btnListen->setText("Listen");
            ui->editAddress->setEnabled(true);
            ui->editPort->setEnabled(true);
        } else {
            //�ӽ����϶�ȡip�Ͷ˿�
            //����ʹ�� QHostAddress::Any �������е�ַ�Ķ�Ӧ�˿�
            const QString address_text = ui->editAddress->text();
            const QHostAddress address = (address_text == "Any")
                ? QHostAddress::Any
                : QHostAddress(address_text);
            const unsigned short port = ui->editPort->text().toUShort();
            //��ʼ���������ж��Ƿ�ɹ�
            if (server->listen(address, port)) {
                //���ӳɹ����޸Ľ��水ť��ʾ���Լ���ַ�����ɱ༭
                ui->btnListen->setText("Close");
                ui->editAddress->setEnabled(false);
                ui->editPort->setEnabled(false);
            }
        }
        updateState();
    });

    //�������µĿͻ�����������
    connect(server, &QTcpServer::newConnection, this, [this] {
        //������µ����Ӿ�ȡ��
        while (server->hasPendingConnections()) {
            //nextPendingConnection������һ�������������Ϊ�����ӵ�QTcpSocket����
            //�׽�������Ϊ���������Ӽ������ģ�����ζ������QTcpServer����ʱ���Զ�ɾ�����׽��֡�
            //�������ɴ������ʽɾ���ö����Ա����˷��ڴ档
            //���ص�QTcpSocket�����ܴ���һ���߳�ʹ�ã�������Ҫ����дincomingConnection().
            QTcpSocket *socket = server->nextPendingConnection();
            clientList.append(socket);
            ui->textRecv->append(QString("[%1:%2] Soket Connected")
                .arg(socket->peerAddress().toString())
                .arg(socket->peerPort()));

            //������ز������źŲ�
            //�յ����ݣ�����readyRead
            connect(socket, &QTcpSocket::readyRead, [this, socket] {
                //û�пɶ������ݾͷ���
                if (socket->bytesAvailable() <= 0)
                    return;
                //ע���շ������ı�Ҫʹ�ö�Ӧ�ı����
                const QString recv_text = QString::fromUtf8(socket->readAll());
                const QString show_text = text2Show(recv_text);
                ui->textRecv->append(QString("[%1:%2]")
                    .arg(socket->peerAddress().toString())
                    .arg(socket->peerPort()));
                ui->textRecv->append(show_text);
            });

            //error�ź���5.15��������
#if QT_VERSION < QT_VERSION_CHECK(5, 15, 0)
            //������Ϣ
            connect(socket, static_cast<void(QAbstractSocket::*)(QAbstractSocket::SocketError)>(&QAbstractSocket::error),
                [this, socket](QAbstractSocket::SocketError) {
                ui->textRecv->append(QString("[%1:%2] Soket Error:%3")
                    .arg(socket->peerAddress().toString())
                    .arg(socket->peerPort())
                    .arg(socket->errorString()));
            });
#else
            //������Ϣ
            connect(socket, &QAbstractSocket::errorOccurred, [this, socket](QAbstractSocket::SocketError) {
                ui->textRecv->append(QString("[%1:%2] Soket Error:%3")
                    .arg(socket->peerAddress().toString())
                    .arg(socket->peerPort())
                    .arg(socket->errorString()));
            });
#endif

            //���ӶϿ�������socket��������Ϊ�˿���serverʱsocket��ȷ�ͷ�
            connect(socket, &QTcpSocket::disconnected, [this, socket] {
                socket->deleteLater();
                clientList.removeOne(socket);
                ui->textRecv->append(QString("[%1:%2] Soket Disonnected")
                    .arg(socket->peerAddress().toString())
                    .arg(socket->peerPort()));
                updateState();
            });
        }
        updateState();
    });

    //server��client��������
    connect(ui->btnSend, &QPushButton::clicked, [this] {
        //�ж��Ƿ�����server
        if (!server->isListening())
            return;
        //���������ı����͸��ͻ���
        const QByteArray send_data = ui->textSend->toPlainText().toUtf8();
        //����Ϊ�վͷ���
        if (send_data.isEmpty())
            return;
        for (QTcpSocket *socket : clientList) {
            socket->write(send_data);
            //socket->waitForBytesWritten();
        }
    });

    //server�Ĵ�����Ϣ
    //�������������serverError()���ش�������ͣ�
    //���ҿ��Ե���errorString()�Ի�ȡ���������¼���������������
    connect(server, &QTcpServer::acceptError, [this](QAbstractSocket::SocketError) {
        ui->textRecv->append("Server Error:" + server->errorString());
    });
}

void TcpServer::closeServer()
{
    //ֹͣ����
    server->close();
    for (QTcpSocket * socket : clientList) {
        //�Ͽ���ͻ��˵�����
        socket->disconnectFromHost();
        if (socket->state() != QAbstractSocket::UnconnectedState) {
            socket->abort();
        }
    }
}

void TcpServer::updateState()
{
    //����ǰserver��ַ�Ͷ˿ڡ��ͻ���������д�ڱ�����
    if (server->isListening()) {
        setWindowTitle(QString("Server[%1:%2] connections:%3")
            .arg(server->serverAddress().toString())
            .arg(server->serverPort())
            .arg(clientList.count()));
    } else {
        setWindowTitle("Server");
    }
}

QString TcpServer::text2Show(const QString &text)
{
    QString start_flag = "[startdata]";
    QString end_flag = "[enddata]";
    int start_idx = text.indexOf(start_flag);
    int end_idx = text.indexOf(end_flag);
    if (start_idx == -1 || end_idx   == -1) {
        return text;
    }

    QString show_text;
    QStringList names;
    names << "Dir" << "Synchronization" << "Type" << "Data";
    QStringList items;
    QString item;
    int idx = start_flag.length();
    while (idx < end_idx) {
        int tmp_idx = text.indexOf(']', idx);
        item = text.mid(idx + 1, tmp_idx - idx - 1);
        items << item;
        idx = tmp_idx + 1;
    }
    if (items.length() >= 4) {
        QString tmp_data = "\n";
        QString data = items[3];
        int idx = 0;
        do {
            int tmp_idx = data.indexOf(',', idx);
            item = data.mid(idx, tmp_idx - idx);
            tmp_data += "     " + item + '\n';
            idx = tmp_idx + 1;
        } while (idx != 0);
        items[3] = tmp_data;
    }
    for (int i = 0; i < items.length(); i++) {
        show_text += names[i] + ":" + items[i] + '\n';
    }

    return show_text;
}

