/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpServerClass
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *editAddress;
    QLabel *label;
    QLineEdit *editPort;
    QPushButton *btnListen;
    QLabel *label_3;
    QTextEdit *textRecv;
    QLabel *label_4;
    QTextEdit *textSend;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSend;

    void setupUi(QWidget *TcpServerClass)
    {
        if (TcpServerClass->objectName().isEmpty())
            TcpServerClass->setObjectName(QStringLiteral("TcpServerClass"));
        TcpServerClass->setWindowModality(Qt::WindowModal);
        TcpServerClass->setEnabled(true);
        TcpServerClass->resize(615, 806);
        verticalLayoutWidget = new QWidget(TcpServerClass);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 611, 801));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        editAddress = new QLineEdit(verticalLayoutWidget);
        editAddress->setObjectName(QStringLiteral("editAddress"));

        horizontalLayout->addWidget(editAddress);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        editPort = new QLineEdit(verticalLayoutWidget);
        editPort->setObjectName(QStringLiteral("editPort"));

        horizontalLayout->addWidget(editPort);

        btnListen = new QPushButton(verticalLayoutWidget);
        btnListen->setObjectName(QStringLiteral("btnListen"));

        horizontalLayout->addWidget(btnListen);


        verticalLayout->addLayout(horizontalLayout);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        textRecv = new QTextEdit(verticalLayoutWidget);
        textRecv->setObjectName(QStringLiteral("textRecv"));

        verticalLayout->addWidget(textRecv);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        textSend = new QTextEdit(verticalLayoutWidget);
        textSend->setObjectName(QStringLiteral("textSend"));
        textSend->setMaximumSize(QSize(16777215, 150));

        verticalLayout->addWidget(textSend);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnSend = new QPushButton(verticalLayoutWidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));

        horizontalLayout_2->addWidget(btnSend);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(TcpServerClass);

        QMetaObject::connectSlotsByName(TcpServerClass);
    } // setupUi

    void retranslateUi(QWidget *TcpServerClass)
    {
        TcpServerClass->setWindowTitle(QApplication::translate("TcpServerClass", "TcpServer", Q_NULLPTR));
        label_2->setText(QApplication::translate("TcpServerClass", "Address", Q_NULLPTR));
        editAddress->setText(QApplication::translate("TcpServerClass", "127.0.0.1", Q_NULLPTR));
        label->setText(QApplication::translate("TcpServerClass", "Port", Q_NULLPTR));
        editPort->setText(QApplication::translate("TcpServerClass", "5500", Q_NULLPTR));
        btnListen->setText(QApplication::translate("TcpServerClass", "Listen", Q_NULLPTR));
        label_3->setText(QApplication::translate("TcpServerClass", "Recv:", Q_NULLPTR));
        label_4->setText(QApplication::translate("TcpServerClass", "Send:", Q_NULLPTR));
        btnSend->setText(QApplication::translate("TcpServerClass", "Send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TcpServerClass: public Ui_TcpServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
