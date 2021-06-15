#include "iclient.h"

#include "iconnection.h"

#include <QObject>

namespace Qcn
{

IClient::IClient(QObject* parent) : QObject(parent)
{
}

IClient::~IClient(){}

}
