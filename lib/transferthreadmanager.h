#ifndef TRANSFERTHREADMANAGER_H
#define TRANSFERTHREADMANAGER_H

#include <QObject>
#include <QList>
#include <QThread>
#include <QMap>
#include "file.h"

namespace Qcn
{

class File;
class Transfer;


class TransferThreadManager : public QObject
{
	Q_OBJECT

public:

	explicit TransferThreadManager(QObject* parent = nullptr);

	~TransferThreadManager();

public Q_SLOTS:

	void transferCreated(Transfer* transfer);

	void manualTransferCreated(Transfer* transfer);

	void acceptPending(qint16 id);

	void rejectPending(qint16 id);

	void stopTransfer(qint16 id);

	void progressTransfer(int prog, quint64 transfered, int rate);

	void requested();

	void destroyTransfer();

	void setThread(QThread* thr);

Q_SIGNALS:

	void requestedTransfer(File f);

	void transferProgressed(qint16 id, int prog, quint64 transfered, int rate);

	void transferRemoved(qint16 id);

	void accepted(qint16 id);

	void rejected(qint16 id);

protected:

	QMap<qint16,Transfer*> m_transferList;

	void removeTransfer(Transfer* t);

};

}

#endif
