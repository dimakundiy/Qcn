#ifndef TRANSFERMANAGER_H
#define TRANSFERMANAGER_H

#include "interfaces/itransfermanager.h"

#include <QObject>
#include <QList>
#include <QMap>
#include <QThread>
#include "file.h"

namespace Qcn
{

class IConnection;
class File;
class Transfer;
class TransferThreadManager;

class TransferManager : public ITransferManager
{
	Q_OBJECT

public:
	explicit TransferManager(QObject* parent = nullptr);
	~TransferManager();

	void shutdown() override;
	void addConnection(IConnection*) override;
	QList<File> pendingTransfers() override;
	QList<File> runningTransfers() override;
	void sendFile(File) override;
	void acceptTransfer(qint16) override;
	void rejectTransfer(qint16) override;
	void stopTransfer(qint16) override;

public Q_SLOTS:
	void createManualTransfer();
	void removeManualTransfer();

	void addToPending(File);
	void transferRemoved(qint16);
	void accepted(qint16);
	void rejected(qint16);
	void progressTransfer(qint16,int,quint64,int);

Q_SIGNALS:
	void transferCreated(Transfer*);
	void acceptPending(qint16);
	void rejectPending(qint16);
	void removeTransfer(qint16);
	void manualTransferCreated(Transfer*);

protected:
	TransferThreadManager* m_ttm;
	QMap<qint16,File> m_pendingTransfers;
	QMap<qint16,File> m_runningTransfers;
	QMap<qint16,File> m_allTransfers;
	QMap<IConnection*,File> m_pendingConnections;
	QThread* m_transferThread;
	int m_transferCount;

	Transfer* createTransfer(IConnection*);
};

}

#endif
