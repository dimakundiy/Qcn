#ifndef CLIENTINFORMATION_H
#define CLIENTINFORMATION_H

#include <QObject>

namespace Qcn
{

class ClientInformation
{

public:
	explicit ClientInformation();
	~ClientInformation();

	qint16 id() const;
	QString name() const;
	QString ip() const;

	void setId(qint16);
	void setName(QString);
	void setIp(QString);

protected:
	qint16 m_id;
	QString m_name;
	QString m_ip;

};

}

Q_DECLARE_METATYPE(Qcn::ClientInformation);

#endif
