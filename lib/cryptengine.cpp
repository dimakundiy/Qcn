#include "cryptengine.h"

#include "interfaces/icryptengine.h"
#include "crypt.h"
#include "rsapair.h"

#include <openssl/rsa.h>

#include <QObject>

namespace Qcn
{

CryptEngine::CryptEngine(QObject* parent) : ICryptEngine(parent) , m_crypt(new Crypt(this))
{
	RSAPair rsa;
	rsa.generateNewPair();
	m_privKey = rsa.privateKey();
	m_pubKey = rsa.publicKey();
	m_privRSA = m_crypt->getPrivateKey(m_privKey);
	m_pubRSA = m_crypt->getPublicKey(m_pubKey);
}

CryptEngine::~CryptEngine()
{
	if(m_privRSA)
		m_crypt->freeKey(m_privRSA);
	if(m_pubRSA)
		m_crypt->freeKey(m_pubRSA);
	m_crypt->deleteLater();
}

QByteArray CryptEngine::publicKey()
{
	return m_pubKey;
}

QByteArray CryptEngine::privateKey()
{
	return m_privKey;
}

QByteArray CryptEngine::randomPassword()
{
	return m_crypt->randomBytes(16);
}

bool CryptEngine::encryptAES(QByteArray passphrase, QByteArray& input, QByteArray& output)
{
	output = m_crypt->encryptAES(passphrase,input);
	if(output.isEmpty())
		return false;
	else
		return true;
}

bool CryptEngine::decryptAES(QByteArray passphrase, QByteArray& input, QByteArray& output)
{
	output = m_crypt->decryptAES(passphrase,input);
	if(output.isEmpty())
		return false;
	else
		return true;
}

bool CryptEngine::encryptRSA(QByteArray& pubKey , QByteArray& input , QByteArray& output)
{
	RSA* pub = m_crypt->getPublicKey(pubKey);
	output = m_crypt->encryptRSA(pub,input);
	m_crypt->freeKey(pub);
	if(output.isEmpty())
		return false;
	else
		return true;
}

bool CryptEngine::decryptRSA(QByteArray& input , QByteArray& output)
{
	output = m_crypt->decryptRSA(m_privRSA,input);
	if(output.isEmpty())
		return false;
	else
		return true;
	return false;
}

}
