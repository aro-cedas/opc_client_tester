#ifndef OPCCLIENT_H
#define OPCCLIENT_H

#include <QObject>
#include <QtOpcUa>

class OpcClient : public QObject
{
    Q_OBJECT
public:
    OpcClient();
    void start();
public slots:
    void connectionState(QOpcUaClient::ClientState);

private:
    QString m_state;
//    QOpcUaClient client;
//    QOpcUaNode node;
};

#endif // OPCCLIENT_H
