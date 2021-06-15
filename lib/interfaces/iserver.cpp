#include "iserver.h"

#include <QTcpServer>

namespace Qcn
{

IServer::IServer(QObject *parent) : QTcpServer(parent){}

IServer::~IServer(){}

}
