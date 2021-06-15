#ifndef FILE_H
#define FILE_H

#include <QObject>

namespace Qcn
{

class File
{

public:
	explicit File();
	~File();

	typedef enum Action {
		UNKNOWN = 0,
		SEND,
		RECIEVE
	} Action;

	qint16 id() const;
	QString name() const;
	QString path() const;
	quint64 size() const;
	Action action() const;
	QString url() const;
	QString userName() const;
	int progress() const;
	int rate() const;
	int transfered() const;
	quint64 timeRemaining() const;

	void setId(qint16);
	void setName(QString);
	void setPath(QString);
	void setSize(quint64);
	void setAction(Action);
	void setUrl(QString);
	void setUserName(QString);
	void setProgress(int);
	void setRate(int);
	void setTransfered(quint64);
	void setTimeRemaining(quint64);

protected:
	qint16 m_id;
	QString m_name;
	QString m_path;
	quint64 m_size;
	Action m_action;
	QString m_url;
	QString m_userName;
	int m_prog;
	int m_rate;
	quint64 m_transfered;
	quint64 m_timeRemaining;

};

}

Q_DECLARE_METATYPE(Qcn::File);

#endif

