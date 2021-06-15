#ifndef MESSENGER_H
#define MESSENGER_H

#include <QObject>

namespace Qcn
{
class IClientManager;

class Messenger : public QObject
{
	Q_OBJECT
public:
	explicit Messenger(IClientManager *cm);
	~Messenger();

	void sendMessage(int id, QString msg);

protected:
	IClientManager* m_cm;

};

}

#endif
