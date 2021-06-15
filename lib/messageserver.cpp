#include "messageserver.h"

#include "controlcenter.h"
#include "connection.h"
#include "debug.h"
#include "interfaces/iclientmanager.h"
#include "interfaces/iserver.h"

#include <QObject>
#include <QTcpServer>

namespace Qcn
{

MessageServer::MessageServer(QObject* parent) : IServer(parent){}

MessageServer::~MessageServer(){}

void MessageServer::start()
{
	if(listen(QHostAddress::Any, 2424))
		qCDebug(BASE) << this << "started on 2424";
	else
		qCDebug(BASE) << this << "could not start on 2424";
}

void MessageServer::shutdown()
{
	qCDebug(BASE) << this << "Stopped" ;
	close();
}

void MessageServer::incomingConnection(qintptr handle)
{
	qCDebug(BASE) << this << "new connection " << handle ;
	Connection *conn = new Connection();
	conn->setSocketDescriptor(handle);
	emit gotConnection(conn);
}

}
