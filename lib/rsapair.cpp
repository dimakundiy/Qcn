#include "rsapair.h"

#include <QDebug>
#include <QFile>
#include <QObject>
#include <QStandardPaths>

namespace Qcn
{

RSAPair::RSAPair()
{
}

RSAPair::~RSAPair()
{
}

void RSAPair::generateNewPair()
{
	QString tempDir = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    QString privFileLocation = tempDir+"/qcn_priv_key.pem";
    QString pubFileLocation = tempDir+"/qcn_pub_key.pem";
	QString genPrivate = "openssl genrsa -out "+privFileLocation+" 2048";
	QString genPublic = "openssl rsa -in "+privFileLocation+" -pubout > "+pubFileLocation;
	system(genPrivate.toStdString().c_str());
	system(genPublic.toStdString().c_str());

	QFile priv(privFileLocation);
	if(!priv.open(QFile::ReadOnly))
	{
		qDebug() << "cannot open file " << privFileLocation ;
		return;
	}

	QByteArray privateKey = priv.readAll();
	priv.close();

	QFile pub(pubFileLocation);
	if(!pub.open(QFile::ReadOnly))
	{
		qDebug() << "cannot open file " << pubFileLocation ;
		return;
	}

	QByteArray publicKey = pub.readAll();
	pub.close();
	
	m_priv = privateKey;
	m_pub = publicKey;
}

QByteArray RSAPair::privateKey()
{
	return m_priv;
}

QByteArray RSAPair::publicKey()
{
	return m_pub;
}

}
