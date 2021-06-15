#ifndef CONTROLCENTERPRIVATE_H
#define CONTROLCENTERPRIVATE_H

namespace Qcn
{

class MessageServer;
class ClientManager;
class CryptEngine;
class TransferManager;
class TransferServer;
class UserSettings;
class ControlCenter;


class ControlCenterPrivate
{
public:

	explicit ControlCenterPrivate(ControlCenter* parent = nullptr);

	~ControlCenterPrivate();

	void init();

	void shutdown();

	MessageServer* m_messageServer;
	TransferServer* m_transferServer;
	ClientManager* m_clientManager;
	CryptEngine* m_cryptEngine;
	TransferManager* m_transferManager;
	UserSettings* m_userSettings;

	ControlCenter* m_cc;
};

}

#endif
