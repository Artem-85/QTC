#include <QTC_Core.h>

QTC_Core::QTC_Core(int &argc, char **argv)
    :QApplication(argc,argv)
{

}

QTC_Core::~QTC_Core()
{

}

void QTC_Core::init()
{
    QString displayName = QStringLiteral("%1 v. %2").arg(APPLICATION_NAME,APPLICATION_VERSION);
    setApplicationDisplayName(displayName);
}

void QTC_Core::readSettings()
{
    QString defaultUser, defaultPath;
    QLocale defaultLocale;

    QSettings appSettings;
    // check for the first run:
    if (!appSettings.value("lastRun").isValid()) {

        defaultUser = getDefaultUserName();
        defaultLocale = getSystemLocale();
        defaultPath = getDefaultPath();

//        switchAppTranslation(defaultLocale);

        QMessageBox firstRun;
        firstRun.setIcon(QMessageBox::Information);
        firstRun.setText(tr("It seems like you are running QtCAD for the first run, or the settings information was erased. "
            "All settings are set to default"));
        firstRun.exec();

    }

    appSettings.beginGroup("Application");

    QString oldVersion = appSettings.value("version").toString();
    setApplicationUser(appSettings.value("user", defaultUser).toString());
    setApplicationLocale(appSettings.value("locale", defaultLocale).toLocale());
//    switchAppTranslation(applicationLocale());
    setApplicationPath(appSettings.value("path", defaultPath).toString());
    // check if version updated:
    if (appSettings.value("version").isValid() and oldVersion != applicationVersion()) {

        QMessageBox appUpdated;
        appUpdated.setIcon(QMessageBox::Information);
        appUpdated.setText(tr("Your QtCAD has been updated since the last run"));
        appUpdated.setDetailedText(tr("Old version: %1\n"
            "New version: %2").arg(oldVersion,applicationVersion()));
        // TODO:
        // add whatsnew's content to details
        appUpdated.exec();

    }

    appSettings.endGroup();
}

void QTC_Core::writeSettings()
{
    QSettings appSettings;

    appSettings.setValue("lastRun", QDateTime::currentSecsSinceEpoch());

    appSettings.beginGroup("Application");
    appSettings.setValue("version", applicationVersion());
    appSettings.setValue("user", applicationUser());
    appSettings.setValue("locale", applicationLocale());
    appSettings.setValue("path", applicationPath());
    appSettings.endGroup();
}

void QTC_Core::setApplicationUser(QString user)
{
    m_appUser = user;
}

void QTC_Core::setApplicationPath(QString path)
{
    m_appPath = path;
}

void QTC_Core::setApplicationLocale(QLocale locale)
{
    m_appLocale = locale;
}

QString QTC_Core::applicationUser()
{
    return m_appUser;
}

QLocale QTC_Core::applicationLocale()
{
    return m_appLocale;
}

QString QTC_Core::applicationPath()
{
    return m_appPath;
}

QLocale QTC_Core::systemLocale()
{
    return m_sysLocale;
}

QMap<QString,QLocale> QTC_Core::applicationTranslations()
{

}

QString QTC_Core::getDefaultUserName()
{
    QString userName;

    #ifdef PLATFORM_WIN
        userName = qgetenv("USERNAME");
    #else
        userName = qgetenv("USER");
    #endif

    if (userName.length() > 0)
        return userName;
    else
        return "user";
}

QString QTC_Core::getDefaultPath()
{
    QString homePath = QDir::homePath().append("/QTC files");

    QDir homeDir(homePath);

    if (homeDir.mkpath("."))
        return homePath;
    else
        return QDir::homePath();
}

QLocale QTC_Core::getSystemLocale()
{
    QLocale systemLocale = QLocale::system();
    return systemLocale;
}
