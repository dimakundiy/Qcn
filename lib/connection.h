#ifndef CONNECTION_H
#define CONNECTION_H

#include "interfaces/iconnection.h"

#include <QObject>

namespace Qcn
{

class Connection : public IConnection
{
	Q_OBJECT

public:
	explicit Connection();
	~Connection();

	QByteArray data(quint32 size = 0) override;
	QByteArray seek(quint32 size = 0) override;
	bool hasUnreadData() override;
	quint32 availableSize() override;

protected:
	void isError();
	void saveData();

	QByteArray m_data;
	bool m_unreadData;

};

}

#endif
