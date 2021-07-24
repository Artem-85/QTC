#ifndef QTC_CORE_H
#define QTC_CORE_H

#include <QApplication>
#include <QDir>
#include <QSettings>
#include <QMessageBox>
#include <QTC_Configuration.h>

class QTC_Core: public QApplication
{
    Q_OBJECT

public:

    explicit QTC_Core(int &argc, char **argv);

    ~QTC_Core();

    void init();

    void readSettings();

    void writeSettings();

    void setApplicationUser(QString user);

    void setApplicationPath(QString path);

    void setApplicationLocale(QLocale locale);

    void switchAppTranslation(QLocale newLocale);

    QString applicationUser();

    QString applicationPath();

    QLocale applicationLocale();

    QLocale systemLocale();

    QMap<QString,QLocale> applicationTranslations();

private:

    QString m_appUser;

    QString m_appPath;

    QLocale m_appLocale;

    QLocale m_sysLocale;

    QMap<QString,QLocale> m_appTranslations;

    QString getDefaultUserName();

    QString getDefaultPath();

    QLocale getSystemLocale();

};

#endif // QTC_CORE_H
