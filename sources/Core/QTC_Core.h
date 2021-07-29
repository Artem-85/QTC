#ifndef QTC_CORE_H
#define QTC_CORE_H

#include <QTC_Configuration.h>
#include <QApplication>
#include <QDir>
#include <QSettings>
#include <QMessageBox>

#ifdef BUILD_DEBUG
    #include <QDebug>
#endif

class QTC_Core: public QApplication
{
    Q_OBJECT

public:

    typedef QMap<QString,QVariant> SetMap;

    typedef QMap<QString,QLocale> LocMap;

    explicit QTC_Core(int &argc, char **argv);

    ~QTC_Core();

    void init();

    void firstRunCheck();

    void readSettings();

    void writeSettings();

    void setApplicationUser(const QString& user);

    void setApplicationPath(const QString& path);

    void setApplicationLocale(const QLocale& locale);

    void switchAppTranslation(QLocale newLocale);

    QString applicationUser();

    QString applicationPath();

    QLocale applicationLocale();

    SetMap& applicationSettingsToUpdate();

    QLocale systemLocale();

    LocMap& applicationTranslations();

    QWidget* getMainWinInstance();

private:

    QSettings m_appSettings;

    QString m_appUser;

    QString m_appPath;

    QLocale m_appLocale;

    SetMap m_settingsToUpdate;

    QLocale m_sysLocale;

    LocMap m_appTranslations;

    QString getDefaultUserName();

    QString getDefaultPath();

    QLocale getSystemLocale();

private slots:

    void onQuit();

};

#endif // QTC_CORE_H
