#include "uimanager.h"

#include <lib/controlcenter.h>
#include <lib/interfaces/icontrolcenter.h>
#include <lib/interfaces/iclientmanager.h>
#include <lib/interfaces/iusersettings.h>
#include <lib/interfaces/itransfermanager.h>
#include <lib/file.h>
#include "userlist.h"
#include "messenger.h"
#include "messagelist.h"
#include "pendingtransfers.h"
#include "runningtransfers.h"

#include <QAbstractListModel>
#include <QFileInfo>
#include <QQmlEngine>
#include <QJSEngine>
#include <QDebug>

namespace Qcn
{

UiManager::UiManager() : m_cc(ControlCenter::instance()) , m_selectedUser(-1) , m_unreadMessages(0) , m_unseenTransfers(0)
{
	m_clientManager = m_cc->clientManager();
	m_settings = m_cc->userSettings();
	m_transferManager = m_cc->transferManager();
	m_messages = new MessageList(m_clientManager);
	m_usersList = new UserList(m_clientManager);
	m_messenger = new Messenger(m_clientManager);
	m_pendingTransfersList = new PendingTransfers(m_transferManager);
	m_runningTransfersList = new RunningTransfers(m_transferManager);
	connect(m_clientManager,&IClientManager::manualConnectionFailed,this,&UiManager::manualConnectionFailed);
    m_notificationMsg = "Welcome to Qcn";
	m_notificationStatus = runningFirstTime() ? "Inactive" : "Active" ; 
	connect(m_messages,&MessageList::messagesAdded,this,&UiManager::messagesAdded);
	connect(m_pendingTransfersList,&PendingTransfers::transfersAdded,this,&UiManager::transfersAdded);
}

UiManager::~UiManager()
{
}

QAbstractListModel* UiManager::users()
{
	return m_usersList;
}

QAbstractListModel* UiManager::messages()
{
	return m_messages;
}

QAbstractListModel* UiManager::pendingTransfers()
{
	return m_pendingTransfersList;
}

QAbstractListModel* UiManager::runningTransfers()
{
	return m_runningTransfersList;
}

bool UiManager::runningFirstTime()
{
	return m_settings->runningFirstTime();
}

QString UiManager::theme()
{
	return m_settings->theme();
}

void UiManager::setTheme(QString color)
{
	if(color != theme())
		m_settings->setTheme(color);
	emit themeChanged();
}

QString UiManager::userName()
{
	return m_settings->name();
}

void UiManager::setUserName(QString name)
{
	if(name != userName() && !name.isEmpty() && !name.isNull())
		m_settings->setName(name);
	emit userNameChanged();
}

QString UiManager::downloadDir()
{
	return m_settings->downloadDir();
}

void UiManager::setDownloadDir(QString ddir)
{
	if(ddir.startsWith("file://"))
        ddir = ddir.mid(8);

	if(ddir != downloadDir() && !ddir.isEmpty() && !ddir.isNull())
		m_settings->setDownloadDir(ddir);

	emit downloadDirChanged();
}

qint16 UiManager::selectedUser()
{
	return m_selectedUser;
}

void UiManager::setSelectedUser(qint16 id)
{
	m_selectedUser = id;
	emit selectedUserChanged();
}

QString UiManager::notificationMsg()
{
	return m_notificationMsg;
}

void UiManager::setNotificationMsg(QString msg)
{
	m_notificationMsg = msg;
	emit notificationMsgChanged();
}

QString UiManager::notificationStatus()
{
	return m_notificationStatus;
}

void UiManager::setNotificationStatus(QString status)
{
	m_notificationStatus = status;
	emit notificationStatusChanged();
}

int UiManager::unreadMessages()
{
	return m_unreadMessages;
}

void UiManager::setUnreadMessages(int m)
{
	m_unreadMessages = m;
	emit unreadMessagesChanged();
}

int UiManager::unseenTransfers()
{
	return m_unseenTransfers;
}

void UiManager::setUnseenTransfers(int t)
{
	m_unseenTransfers = t;
	emit unseenTransfersChanged();
}

void UiManager::sendMessage(QString msg)
{
	if(msg.isEmpty())
		return;
	m_messenger->sendMessage(m_selectedUser,msg);
}

void UiManager::sendFile(QString filename)
{
	if(filename.isEmpty() || filename.isNull())
		return;

	File f;
	f.setAction(File::SEND);
	f.setUrl(m_clientManager->clientInfo(m_selectedUser).ip());
	f.setUserName(userName());

	if(filename.startsWith("file://"))
        filename = filename.mid(8);

	QFileInfo file(filename);
	f.setName(file.fileName());
	f.setPath(file.path());
	f.setSize(file.size());

	m_transferManager->sendFile(f);
}

void UiManager::quickConnect(QString url)
{
	if(url.isEmpty() || url.isNull())
		return;

	m_cc->clientManager()->connectManualy(url);
}

void UiManager::acceptTransfer(qint16 id)
{
	m_transferManager->acceptTransfer(id);
}

void UiManager::rejectTransfer(qint16 id)
{
	m_transferManager->rejectTransfer(id);
}

void UiManager::stopTransfer(qint16 id)
{
	m_transferManager->stopTransfer(id);
}

void UiManager::manualConnectionFailed(QString url)
{
	setNotificationMsg("Can't Connect to \""+url+"\"");
	setNotificationStatus("Active");
}

void UiManager::messagesAdded(int n)
{
	setUnreadMessages(unreadMessages() + n);
}

void UiManager::transfersAdded(int n)
{
	setUnseenTransfers(unseenTransfers() + n);
}

QObject* UiManager::uimanager_singleton(QQmlEngine *engine, QJSEngine *scriptEngine)
{
	Q_UNUSED(engine)
	Q_UNUSED(scriptEngine)

	UiManager *manager = new UiManager();
	return manager;
}

}
