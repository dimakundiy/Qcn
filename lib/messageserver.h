#ifndef MESSAGESERVER_H
#define MESSAGESERVER_H

#include "interfaces/iserver.h"

#include <QObject>

namespace Qcn
{

class MessageServer : public IServer
{
	Q_OBJECT

public:

	explicit MessageServer(QObject* parent);

	~MessageServer();

	void start() override;

	void shutdown();

protected:
	QTcpServer m_server;

	void incomingConnection(qintptr handle) override;

};

}

#endif
 
