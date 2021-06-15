#include "file.h"

namespace Qcn
{

File::File() : m_name(QString()) , m_path(QString()) , m_size(0) , m_action(UNKNOWN) , m_url(QString()) ,
				 m_userName(QString()) , m_prog(0) , m_rate(0) , m_transfered(0) , m_timeRemaining(0)
{
}

File::~File()
{
}

qint16 File::id() const
{
	return m_id;
}

QString File::name() const
{
	return m_name;
}

QString File::path() const
{
	return m_path;
}

quint64 File::size() const
{
	return m_size;
}

File::Action File::action() const
{
	return m_action;
}

QString File::url() const
{
	return m_url;
}

QString File::userName() const
{
	return m_userName;
}

int File::progress() const
{
	return m_prog;
}

int File::rate() const
{
	return m_rate;
}

int File::transfered() const
{
	return m_transfered;
}

quint64 File::timeRemaining() const
{
	return m_timeRemaining;
}

void File::setId(qint16 id)
{
	m_id = id;
}

void File::setName(QString name)
{
	m_name = name;
}

void File::setPath(QString path)
{
	m_path = path;
}

void File::setSize(quint64 size)
{
	m_size = size;
}

void File::setAction(Action action)
{
	m_action = action;
}

void File::setUrl(QString url)
{
	m_url = url;
}

void File::setUserName(QString name)
{
	m_userName  = name;
}

void File::setProgress(int prog)
{
	m_prog = prog;
}

void File::setRate(int rate)
{
	m_rate = rate;
}

void File::setTransfered(quint64 trans)
{
	m_transfered = trans;
}

void File::setTimeRemaining(quint64 trem)
{
	m_timeRemaining = trem;
}

}
