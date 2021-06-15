#include <openssl/rsa.h>

#include <QObject>

#define PADDING RSA_PKCS1_PADDING
#define KEYSIZE 32
#define IVSIZE 32
#define BLOCKSIZE 256
#define SALTSIZE 8

namespace Qcn
{

class Crypt : public QObject
{
	Q_OBJECT

public:
	explicit Crypt(QObject* parent = nullptr);
	~Crypt();

	RSA* getPublicKey(QByteArray &);
	RSA* getPrivateKey(QByteArray &);
	void freeKey(RSA*);
	QByteArray randomBytes(int);

	QByteArray encryptRSA(RSA *key, QByteArray &data);
	QByteArray decryptRSA(RSA *key, QByteArray &data);
	QByteArray encryptAES(QByteArray, QByteArray&);
	QByteArray decryptAES(QByteArray, QByteArray&);
};

}
