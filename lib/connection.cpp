#include "connection.h"

#include <QAbstractSocket>
#include <QDebug>

namespace Qcn
{

Connection::Connection() : m_unreadData(false)
{
	connect(this,static_cast<void (Connection::*)(QAbstractSocket::SocketError)>(&Connection::error),this,&Connection::isError);
	connect(this,&Connection::readyRead,this,&Connection::saveData);
}

Connection::~Connection(){}

void Connection::isError()
{
	if(error() == QAbstractSocket::HostNotFoundError || error() == QAbstractSocket::ConnectionRefusedError)
		emit hostNotFound();
	else
		emit errorOccurred();
}

QByteArray Connection::data(quint32 size)
{
	QByteArray result;
	result.clear();
	if(size == 0 || m_data.size() == size) {
		m_unreadData = false;
		result = m_data;
		m_data.clear();
		return result;
	}
	else if(m_data.size() > size) {
		result = m_data.mid(0,size);
		m_data = m_data.mid(size);
		return result;
	}
	else {
		return result;
	}
}

QByteArray Connection::seek(quint32 size)
{
	QByteArray result;
	result.clear();
	if(size == 0 || m_data.size() == size) {
		m_unreadData = false;
		result = m_data;
		return result;
	}
	else if(m_data.size() > size) {
		result = m_data.mid(0,size);
		return result;
	}
	else {
		return result;
	}
}

bool Connection::hasUnreadData()
{
	return m_unreadData;
}

quint32 Connection::availableSize()
{
	return m_data.size();
}

void Connection::saveData()
{
	QByteArray data = readAll();
	if (hasUnreadData())
		m_data += data;
	else
		m_data = data;
	m_unreadData = true;
	emit dataAvailable();
}

}
