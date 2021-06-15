#ifndef SECURETUNNEL_H
#define SECURETUNNEL_H

#include <QObject>

namespace Qcn
{
class IConnection;
class Message;

class SecureTunnel : public QObject
{
	Q_OBJECT

public:

	explicit SecureTunnel(QObject* parent = nullptr);

	~SecureTunnel();

	void create();

	bool secure() const;

	void send(QByteArray data);

	QByteArray read();

	Message readMessage();

	void setConnection(IConnection* conn);

Q_SIGNALS:

	void secured();

protected:

	void readyRead();

	void sendKey();

	void sendAESPass();

	void getAESPass();

	void getRSAPub();

	QByteArray dataSize(quint32 size);

	QByteArray readRawData();

	QByteArray readAESDecryptedData();

	QByteArray readRSADecryptedData();

private:
	bool m_secured;
	bool m_gotRSAPub;
	bool m_keySent;
	bool m_keyAccepted;
	IConnection* m_conn;
	QByteArray m_clientPublicKey;
	QString m_aesPassPhrase;
};

}


#endif
