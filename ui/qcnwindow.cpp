#include "qcnwindow.h"

#include <lib/interfaces/icontrolcenter.h>
#include <lib/interfaces/iusersettings.h>
#include "uimanager.h"
#include "messenger.h"

#include <QObject>
#include <QQmlApplicationEngine>
#include <QAbstractListModel>
#include <QQmlContext>

namespace Qcn
{

QcnWindow::QcnWindow()
{
    qmlRegisterSingletonType<UiManager>("api.ui.qcn",2,0,"Qcn",UiManager::uimanager_singleton);
}

QcnWindow::~QcnWindow()
{
}

void QcnWindow::show()
{
	m_engine.load(QUrl("qrc:/resources/MainWindow.qml"));
}

}
