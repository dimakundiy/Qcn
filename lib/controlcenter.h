#ifndef CONTROLCENTER_H
#define CONTROLCENTER_H

#include "interfaces/icontrolcenter.h"

#include <QObject>

namespace Qcn
{

class IServer;
class IClientManager;
class ICryptEngine;
class ITransferManager;
class ControlCenterPrivate;
class IUserSettings;

class ControlCenter : public IControlCenter
{
	Q_OBJECT
public:
	explicit ControlCenter(QObject* parent = nullptr);
	~ControlCenter();
	static ControlCenter* instance();
	static void init();
	static void quit();

	IServer* messageServer() override;
	IServer* transferServer() override;
	IClientManager* clientManager() override;
	ICryptEngine* cryptEngine() override;
	ITransferManager* transferManager() override;
	IUserSettings* userSettings() override;

public Q_SLOTS:
	void shutdown();

protected:
	friend ControlCenterPrivate;
	ControlCenterPrivate* m_ccp;
	static ControlCenter* m_instance;

};

}

#endif
