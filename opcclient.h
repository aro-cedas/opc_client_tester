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

private:
    QString m_state;

};

#endif // OPCCLIENT_H
