#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include "confighelper.h"

#if defined (Q_OS_WIN)
#include <Windows.h>
#endif

class Utils: public QObject
{
    Q_OBJECT

public:
    Utils();

    static QString Base64UrlEncode(QString plainText);
    static QString Base64UrlDecode(QString encodedText);

    static QStringList splitLines(const QString &string);
    static QString toCamelCase(const QString& s);
    static QString toQString(const QJsonObject &object);
    static QString getLogDir();
    static void setPermisison(QString &file);

    static QSize smallIconSize(const QWidget *widget = nullptr);
    static QSize mediumIconSize(const QWidget *widget = nullptr);
    static QSize largeIconSize(const QWidget *widget = nullptr);

    static QString bytesConvertor(const quint64 &t);

    static QString getConfigPath();
    static ConfigHelper* getConfigHelper();

    static QList<WsHeader> convertQJsonObject(const QJsonObject &object);
    static QJsonObject convertWsHeader(QList<WsHeader> headers);

#if defined (Q_OS_WIN)
    static PROCESS_INFORMATION createProcessWithoutWindow(QString application, QString arg);
#endif

    static QString getSystemDirectory();
    static QString getSystemVersion();
    static QString getFileVersion(QString fName);

};

#endif // UTILS_H
