#ifndef RUNNINGTRANSFERS_H
#define RUNNINGTRANSFERS_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>

namespace Qcn
{
class ITransferManager;
class File;

class RunningTransfers : public QAbstractListModel
{
	Q_OBJECT
public:
	enum UserInfo {
		Id  = Qt::UserRole + 1,
		FileName,
		FilePath,
		FileSize,
		Url,
		ClientName,
		Progress,
		Transfered,
		Rate,
		TimeRemaining
	};

	explicit RunningTransfers(ITransferManager* tm, QObject* parent = nullptr);
	~RunningTransfers();
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

public Q_SLOTS:

	void updateList();

	void updateProgress(qint16,int,quint64,int);

protected:
	QHash<int, QByteArray> roleNames() const;
	ITransferManager *m_tm;
	QList<File> m_transfers;

	QString bytesToString(quint64 bytes) const;

	QString timeForFile(File f) const;

};

}

#endif

