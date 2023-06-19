#include "opcclient.h"

OpcClient::OpcClient()
{

}

void OpcClient::start()
{
    qDebug() << "start client";
    QOpcUaProvider provider;
    QOpcUaUserTokenPolicy s;
    if (provider.availableBackends().isEmpty())
        return;
    QOpcUaClient *client = provider.createClient(provider.availableBackends()[0]);
    if (!client)
        return;
    // Connect to the stateChanged signal. Compatible slots of QObjects can be used instead of a lambda.
    QObject::connect(client, &QOpcUaClient::stateChanged, [client](QOpcUaClient::ClientState state) {
        qDebug() << "Client state changed:" << state;
        if (state == QOpcUaClient::ClientState::Connected) {
            QOpcUaNode *node = client->node("ns=1;s=temperature1");
            qDebug() << node->allBaseAttributes();
        }
    });
    QObject::connect(client, &QOpcUaClient::endpointsRequestFinished,
                     [client](QVector<QOpcUaEndpointDescription> endpoints) {
                         qDebug() << "Endpoints returned:" << endpoints.count();
                         if (endpoints.size())
                             client->connectToEndpoint(endpoints.first()); // Connect to the first endpoint in the list
                     });

    client->requestEndpoints(QUrl("opc.tcp://127.0.0.1:12345"));
}
