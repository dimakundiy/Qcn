#include "lib/controlcenter.h"
#include "ui/qcnwindow.h"

#include <iostream>
#include <QApplication>
#include <QLoggingCategory>
#include <QIcon>

using namespace Qcn;

int main(int argc, char* argv[])
{
	QApplication a(argc,argv);
    a.setApplicationName("Qcn");
    a.setOrganizationName("Qcn");

    QLoggingCategory::setFilterRules(QStringLiteral("qcn.transferrigor=false\n"));

	ControlCenter::init();
	QObject::connect(&a,&QApplication::aboutToQuit,ControlCenter::instance(),&ControlCenter::shutdown);
    QcnWindow w;
	w.show();

	a.exec();
	ControlCenter::quit();
	return 0;
}
