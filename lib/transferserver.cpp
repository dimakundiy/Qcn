#include "transferserver.h"

#include "controlcenter.h"
#include "connection.h"
#include "debugtransfer.h"
#include "interfaces/itransfermanager.h"

#include <QObject>
#include <QTcpServer>

namespace Qcn
{

TransferServer::TransferServer(QObject* parent) : IServer(parent){}

TransferServer::~TransferServer(){}

void TransferServer::start()
{
	if(listen(QHostAddress::Any, 2423))
		qCDebug(TRANSFER) << this << "started on 2423";
	else
		qCDebug(TRANSFER) << this << "could not start on 2423";
}

void TransferServer::shutdown()
{
	qCDebug(TRANSFER) << this << "Stopped" ;
	close();
}

void TransferServer::incomingConnection(qintptr handle)
{
	qCDebug(TRANSFER) << this << "new connection " << handle ;
	Connection *conn = new Connection();
	conn->setSocketDescriptor(handle);
	emit gotConnection(conn);
}

}

