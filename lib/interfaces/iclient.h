#ifndef ICLIENT_H
#define ICLIENT_H

#include <QObject>

namespace Qcn
{

class IConnection;
class ClientInformation;

class IClient : public QObject
{
	Q_OBJECT

public:

	virtual IConnection* connection() = 0;

	virtual ClientInformation info() = 0;

	virtual void sendMessage(QString msg) = 0;

protected:

	IClient(QObject* parent = nullptr);

	~IClient();

};

}

#endif
