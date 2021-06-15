#include "message.h"

#include <QJsonObject>
#include <QJsonDocument>

namespace Qcn
{

Message::Message(QByteArray data)
{
	parseJson(data);
}

Message::Message()
{

}

Message Message::fromJson(QByteArray data)
{
	return Message(data);
}

Message::Method Message::method()
{
	return m_method;
}

void Message::setMethod(Method method)
{
	m_method = method;
}

Message::Option Message::option()
{
	return m_option;
}

void Message::setOption(Option option)
{
	m_option = option;
}

QString Message::data(QString key)
{
	return m_data[key].toString();
}

void Message::setData(QString key, QString value)
{
	m_data[key] = value;
}

QByteArray Message::toJson()
{
	QJsonObject root;
	root["METHOD"] = m_method;
	root["OPTION"] = m_option;
	root["DATA"] = m_data;
	QJsonDocument jd(root);
	return jd.toJson();
}

void Message::parseJson(QByteArray data)
{
	QJsonDocument json(QJsonDocument::fromJson(data));
	QJsonObject root = json.object();
	m_method = Method(root["METHOD"].toInt());
	m_option = Option(root["OPTION"].toInt());
	m_data = root["DATA"].toObject();
}

}
