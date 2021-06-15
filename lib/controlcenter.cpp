#include "controlcenter.h"

#include "interfaces/iclientmanager.h"
#include "interfaces/icontrolcenter.h"
#include "interfaces/iserver.h"
#include "interfaces/itransfermanager.h"
#include "interfaces/iusersettings.h"
#include "clientmanager.h"
#include "cryptengine.h"
#include "controlcenter_p.h"
#include "messageserver.h"
#include "transfermanager.h"
#include "transferserver.h"
#include "usersettings.h"

#include <QObject>

namespace Qcn
{

ControlCenter* ControlCenter::m_instance = nullptr;

ControlCenter::ControlCenter(QObject* parent) : IControlCenter(parent) , m_ccp(new ControlCenterPrivate(this)){}

ControlCenter::~ControlCenter()
{
	shutdown();
}

ControlCenter* ControlCenter::instance()
{
	return m_instance;
}

void ControlCenter::init()
{
	m_instance = new ControlCenter();
	m_instance->m_ccp->init();
}

void ControlCenter::quit()
{
	m_instance->deleteLater();
	m_instance = nullptr;
}

IServer* ControlCenter::messageServer()
{
	return m_ccp->m_messageServer;
}

IServer* ControlCenter::transferServer()
{
	return m_ccp->m_transferServer;
}

IClientManager* ControlCenter::clientManager()
{
	return m_ccp->m_clientManager;
}

ICryptEngine* ControlCenter::cryptEngine()
{
	return m_ccp->m_cryptEngine;
}

ITransferManager* ControlCenter::transferManager()
{
	return m_ccp->m_transferManager;
}

IUserSettings* ControlCenter::userSettings()
{
	return m_ccp->m_userSettings;
}

void ControlCenter::shutdown()
{
	m_instance->m_ccp->shutdown();
	delete m_ccp;
}

}
