#ifndef IUSERSETTINGS_H
#define IUSERSETTINGS_H

#include <QObject>

namespace Qcn
{

class IUserSettings : public QObject
{
	Q_OBJECT

public:

	Q_INVOKABLE virtual QString ip() = 0;

	Q_INVOKABLE virtual bool runningFirstTime() = 0;

	Q_INVOKABLE virtual QString name() = 0;

	Q_INVOKABLE virtual QString downloadDir() = 0;

	Q_INVOKABLE virtual QString theme() = 0;

	Q_INVOKABLE virtual void setName(QString name) = 0;

	Q_INVOKABLE virtual void setDownloadDir(QString ddir) = 0;

	Q_INVOKABLE virtual void setTheme(QString color) = 0;

protected:

	explicit IUserSettings();

	~IUserSettings();

};

}

#endif
