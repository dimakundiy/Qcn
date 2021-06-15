#ifndef CRYPTENGINE_H
#define CRYPTENGINE_H

#include "interfaces/icryptengine.h"

#include <openssl/rsa.h>

#include <QObject>

namespace Qcn
{
class Crypt;

class CryptEngine : public ICryptEngine
{
	Q_OBJECT

public:
	explicit CryptEngine(QObject* parent = nullptr);
	~CryptEngine();

	QByteArray publicKey() override;
	QByteArray privateKey() override;
	QByteArray randomPassword() override;

	bool encryptRSA(QByteArray& pubKey, QByteArray& input, QByteArray& output) override;
	bool decryptRSA(QByteArray& input, QByteArray& output) override;
	bool encryptAES(QByteArray pass, QByteArray& input, QByteArray& output) override;
	bool decryptAES(QByteArray pass, QByteArray& input, QByteArray& output) override;

private:
	RSA* m_pubRSA;
	RSA* m_privRSA;
	QByteArray m_privKey;
	QByteArray m_pubKey;
	Crypt* m_crypt;
};

}

#endif
