QT       += core gui network quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    app/main.cpp \
    lib/client.cpp \
    lib/clientinformation.cpp \
    lib/clientmanager.cpp \
    lib/clientthreadmanager.cpp \
    lib/connection.cpp \
    lib/controlcenter.cpp \
    lib/controlcenter_p.cpp \
    lib/crypt.cpp \
    lib/cryptengine.cpp \
    lib/debug.cpp \
    lib/debugtransfer.cpp \
    lib/file.cpp \
    lib/interfaces/iclient.cpp \
    lib/interfaces/iclientmanager.cpp \
    lib/interfaces/iconnection.cpp \
    lib/interfaces/icontrolcenter.cpp \
    lib/interfaces/icryptengine.cpp \
    lib/interfaces/iserver.cpp \
    lib/interfaces/itransfer.cpp \
    lib/interfaces/itransfermanager.cpp \
    lib/interfaces/iusersettings.cpp \
    lib/message.cpp \
    lib/messageinformation.cpp \
    lib/messageserver.cpp \
    lib/rsapair.cpp \
    lib/securetunnel.cpp \
    lib/transfer.cpp \
    lib/transfermanager.cpp \
    lib/transferserver.cpp \
    lib/transferthreadmanager.cpp \
    lib/usersettings.cpp \
    app/main.cpp \
    ui/qcnwindow.cpp \
    ui/messagelist.cpp \
    ui/messenger.cpp \
    ui/pendingtransfers.cpp \
    ui/runningtransfers.cpp \
    ui/uimanager.cpp \
    ui/userlist.cpp

HEADERS += \
    lib/client.h \
    lib/clientinformation.h \
    lib/clientmanager.h \
    lib/clientthreadmanager.h \
    lib/connection.h \
    lib/controlcenter.h \
    lib/controlcenter_p.h \
    lib/crypt.h \
    lib/cryptengine.h \
    lib/debug.h \
    lib/debugtransfer.h \
    lib/file.h \
    lib/interfaces/iclient.h \
    lib/interfaces/iclientmanager.h \
    lib/interfaces/iconnection.h \
    lib/interfaces/icontrolcenter.h \
    lib/interfaces/icryptengine.h \
    lib/interfaces/iserver.h \
    lib/interfaces/itransfer.h \
    lib/interfaces/itransfermanager.h \
    lib/interfaces/iusersettings.h \
    lib/message.h \
    lib/messageinformation.h \
    lib/messageserver.h \
    lib/rsapair.h \
    lib/securetunnel.h \
    lib/transfer.h \
    lib/transfermanager.h \
    lib/transferserver.h \
    lib/transferthreadmanager.h \
    lib/usersettings.h \
    ui/qcnwindow.h \
    ui/messagelist.h \
    ui/messenger.h \
    ui/pendingtransfers.h \
    ui/runningtransfers.h \
    ui/uimanager.h \
    ui/userlist.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ui/window.qrc

INCLUDEPATH += C:/OpenSSL/3.0.0-alpha1/include
LIBS += -LC:/OpenSSL/3.0.0-alpha1/lib -llibcrypto
LIBS += -LC:/OpenSSL/3.0.0-alpha1/lib -llibssl
