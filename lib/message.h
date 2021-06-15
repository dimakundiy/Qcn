#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QJsonObject>

namespace Qcn
{

class Message
{
public:
	Message(QByteArray);
	Message();

	enum Method{
		SECURE,
		CONNECT,
		TRANSFER,
		MSG
	};

	enum Option{
		RSA,
		AES,
		REQUEST,
		TEXT,
		RSF,
		RAF,
		REJ
	};

	static Message fromJson(QByteArray);

	Method method();
	void setMethod(Method);

	Option option();
	void setOption(Option);

	QString data(QString);
	void setData(QString, QString);

	QByteArray toJson();

protected:
	Method m_method;
	Option m_option;
	QJsonObject m_data;

	void parseJson(QByteArray);
};

}

#endif
