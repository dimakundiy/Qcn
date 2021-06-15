#ifndef TRANSFERSERVER_H
#define TRANSFERSERVER_H

#include "interfaces/iserver.h"

#include <QObject>

namespace Qcn
{

class TransferServer : public IServer
{
	Q_OBJECT

public:

	explicit TransferServer(QObject* parent);

	~TransferServer();

	void start() override;

	void shutdown();

protected:
	QTcpServer m_server;

	void incomingConnection(qintptr handle) override;

};

}

#endif
 

