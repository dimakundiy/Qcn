#ifndef ICLIENTMANAGER_H
#define ICLIENTMANAGER_H

#include <QObject>
#include <QList>
#include "lib/messageinformation.h"

namespace Qcn
{

class IConnection;
class ClientInformation;
class MessageInformation;

class IClientManager : public QObject
{
	Q_OBJECT

public:
	virtual void shutdown() = 0;

	virtual QList<ClientInformation> clients() = 0;

	virtual ClientInformation clientInfo(qint16 id) = 0;

	virtual QList<MessageInformation> messages() = 0;

	virtual void sendMessage(qint16 id,QString msg) = 0;

	virtual void connectManualy(QString url) = 0;

	Q_INVOKABLE virtual void addConnection(IConnection* connection) = 0;

Q_SIGNALS:

	void userListUpdated();

	void messageAdded(MessageInformation mi);

	void manualConnectionFailed(QString url);

protected:

	explicit IClientManager(QObject* parent = nullptr);

	~IClientManager();

};

}

#endif
