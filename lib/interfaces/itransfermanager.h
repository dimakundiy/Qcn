#ifndef ITRANSFERMANAGER_H
#define ITRANSFERMANAGER_H

#include <QObject>
#include <QList>

namespace Qcn
{

class IConnection;
class File;

class ITransferManager : public QObject
{
	Q_OBJECT

public:

	virtual void shutdown() = 0;

	virtual QList<File> pendingTransfers() = 0;

	virtual QList<File> runningTransfers() = 0;

	virtual void sendFile(File file) = 0;

	virtual void acceptTransfer(qint16 id) = 0;

	virtual void rejectTransfer(qint16 id) = 0;

	virtual void stopTransfer(qint16 id) = 0;
	
	Q_INVOKABLE virtual void addConnection(IConnection*) = 0;

Q_SIGNALS:

	void pendingTransfersUpdated();

	void runningTransfersUpdated();

	void transferProgressed(qint16 id,int progress,quint64 transfered,int rate);

protected:

	explicit ITransferManager(QObject* parent = nullptr);

	~ITransferManager();
};

}

#endif
