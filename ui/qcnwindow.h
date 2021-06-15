#ifndef QcnWindow_H
#define QcbWindow_H

#include <QQmlApplicationEngine>

namespace Qcn
{
class IControlCenter;
class UiManager;

class QcnWindow
{

public:
    explicit QcnWindow();
    ~QcnWindow();

	void show();

protected:
	QQmlApplicationEngine m_engine;
};

}

#endif
