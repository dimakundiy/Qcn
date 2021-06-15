#include "controlcenter_p.h" 

#include "interfaces/iconnection.h"
#include "clientmanager.h"
#include "cryptengine.h"
#include "controlcenter.h"
#include "messageserver.h"
#include "transfermanager.h"
#include "transferserver.h"
#include "usersettings.h"

#include <QObject>

namespace Qcn
{

ControlCenterPrivate::ControlCenterPrivate(ControlCenter* parent) : m_cc(parent){}

ControlCenterPrivate::~ControlCenterPrivate(){}

void ControlCenterPrivate::init()
{
	m_userSettings = new UserSettings();
	m_cryptEngine = new CryptEngine(m_cc);
	m_clientManager = new ClientManager(m_cc);
	m_messageServer = new MessageServer(m_cc);
	m_transferManager = new TransferManager(m_cc);
	m_transferServer = new TransferServer(m_cc);
	QObject::connect(m_messageServer,&MessageServer::gotConnection,m_clientManager,&ClientManager::addConnection,Qt::QueuedConnection);
	m_messageServer->start();
	QObject::connect(m_transferServer,&TransferServer::gotConnection,m_transferManager,&TransferManager::addConnection,Qt::QueuedConnection);
	m_transferServer->start();
}

void ControlCenterPrivate::shutdown()
{
	if(m_transferServer) {
		m_transferServer->shutdown();
		m_transferServer->deleteLater();
	}

	if(m_messageServer) {
		m_messageServer->shutdown();
		m_messageServer->deleteLater();
	}

	if(m_clientManager) {
		m_clientManager->shutdown();
		m_clientManager->deleteLater();
	}

	if(m_cryptEngine)
		m_cryptEngine->deleteLater();

	if(m_transferManager) {
		m_transferManager->shutdown();
		m_transferManager->deleteLater();
	}

	if(m_userSettings)
		m_userSettings->deleteLater();
}

}
