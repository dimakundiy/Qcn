#ifndef RSAPAIR_H
#define RSAPAIR_H

#include <QObject>

namespace Qcn
{

class RSAPair
{
public:
	explicit RSAPair();
	~RSAPair();

	void generateNewPair();

	QByteArray publicKey();

	QByteArray privateKey();

private:
	QByteArray m_pub;
	QByteArray m_priv;

};

}
#endif
