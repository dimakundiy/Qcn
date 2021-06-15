#ifndef CLIENTTHREADMANAGER_H
#define CLIENTTHREADMANAGER_H

#include <QObject>
#include <QMap>
#include <QVector>
#include "clientinformation.h"

namespace Qcn
{
class Client;
class ClientInformation;

class ClientThreadManager : public QObject
{
	Q_OBJECT
public:

	explicit ClientThreadManager(QObject* parent = nullptr);

	~ClientThreadManager();

Q_SIGNALS:

	void clientAdded(ClientInformation ci);

	void messageAdded(qint16 id,QString msg);

	void clientRemoved(qint16 id);

public Q_SLOTS:

	void clientCreated(Client* client);

	void addClient(ClientInformation ci);

	void messageRecieved(qint16 id,QString msg);

	void closeConnection(Client* client);

	void removeAllClients();

	void removeClient();

	void sendToClient(qint16 id, QString msg);

protected:

	QMap<qint16,Client*> m_clientList;

	QVector<Client*> m_clientInQueue;

	void addToPending(Client* client);

	bool isPending(Client* client);

	void removeIfPending(Client* client);

};

}

#endif
