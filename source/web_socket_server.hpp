#ifndef ECHOSERVER_H
#define ECHOSERVER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>

#include <QtWebSockets/QWebSocket>
#include <QtWebSockets/QWebSocketServer>



class EchoServer : public QObject
{
    Q_OBJECT
public:
    explicit EchoServer(quint16 port, bool debug = false, QObject *parent = nullptr);
    ~EchoServer();

Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void onNewConnection();
    void processTextMessage(QString message);
    void processBinaryMessage(QByteArray message);
    void socketDisconnected();

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;
    bool m_debug;
};

#endif //ECHOSERVER_H