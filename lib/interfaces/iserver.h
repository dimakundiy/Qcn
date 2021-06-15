#ifndef ISERVER_H
#define ISERVER_H

#include <QObject>
#include <QTcpServer>

namespace Qcn
{

class IConnection;


class IServer : public QTcpServer
{
	Q_OBJECT

public:

	virtual void start() = 0;

Q_SIGNALS:

	void gotConnection(IConnection*);

protected:

	explicit IServer(QObject* parent);

	~IServer();

};

}

#endif
