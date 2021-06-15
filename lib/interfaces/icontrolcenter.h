#ifndef ICONTROLCENTER_H
#define ICONTROLCENTER_H

#include <QObject>

namespace Qcn
{

class IServer;
class IClientManager;
class ICryptEngine;
class ITransferManager;
class IUserSettings;

class IControlCenter : public QObject
{
	Q_OBJECT

public:

	static IControlCenter* instance();

	virtual IServer* messageServer() = 0;

	virtual IServer* transferServer() = 0;

	virtual IClientManager* clientManager() = 0;

	virtual ICryptEngine* cryptEngine() = 0;

	virtual ITransferManager* transferManager() = 0;

	virtual IUserSettings* userSettings() = 0;

protected:

	static IControlCenter* m_instance;

	explicit IControlCenter(QObject* parent = nullptr);

	~IControlCenter();

};

}

#endif
