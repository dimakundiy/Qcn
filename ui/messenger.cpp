#include "messenger.h"

#include <lib/interfaces/iclientmanager.h>

#include <QObject>
#include <QDebug>

namespace Qcn
{

Messenger::Messenger(IClientManager* cc) : m_cm(cc)
{
}

Messenger::~Messenger()
{
}

void Messenger::sendMessage(int id, QString msg)
{
	m_cm->sendMessage(id,msg);
}

}
