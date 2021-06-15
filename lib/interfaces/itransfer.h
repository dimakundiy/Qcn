#ifndef IDOWNLOADER_H
#define IDOWNLOADER_H

#include <QObject>

namespace Qcn
{

class File;

class ITransfer : public QObject
{
	Q_OBJECT

public:

	virtual void accept() = 0;

	virtual void reject() = 0;

	virtual void sendFile() = 0;

	virtual File file() = 0;

	virtual int rate() = 0;

Q_SIGNALS:

	void error();

	void progress(int progress,quint64 transfered,int rate);

protected:

	explicit ITransfer(QObject* parent = nullptr);

	~ITransfer();

};

}

#endif
