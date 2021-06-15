#ifndef PENDINGTRANSFERS_H
#define PENDINGTRANSFERS_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>

namespace Qcn
{
class ITransferManager;
class File;

class PendingTransfers : public QAbstractListModel
{
	Q_OBJECT
public:
	enum UserInfo {
		Id  = Qt::UserRole + 1,
		FileName,
		FilePath,
		FileSize,
		Url,
		ClientName
	};

	explicit PendingTransfers(ITransferManager* tm, QObject* parent = nullptr);
	~PendingTransfers();
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

public Q_SLOTS:

	void updateList();

Q_SIGNALS:

	void transfersAdded(int);

protected:
	QHash<int, QByteArray> roleNames() const;
	ITransferManager *m_tm;
	QList<File> m_transfers;

	QString bytesToString(quint64 bytes) const;

};

}

#endif

