#include <QTC_Core.h>

QTC_Core::QTC_Core(int &argc, char **argv)
    :QApplication(argc,argv),
      m_appSettings{},
      m_appUser{}
{
    init();
}

QTC_Core::~QTC_Core()
{

}

void QTC_Core::init()
{
    setOrganizationName(ORGANIZATION_NAME);
    setOrganizationDomain(ORGANIZATION_DOMAIN);
    setApplicationVersion(APPLICATION_VERSION);
    setApplicationName(APPLICATION_NAME);

//    firstRunCheck();

    readSettings();

    QString displayName = QStringLiteral("%1 v. %2").arg(APPLICATION_NAME,APPLICATION_VERSION);
    setApplicationDisplayName(displayName);

    connect(this, &QTC_Core::aboutToQuit, this, &QTC_Core::onQuit);

}

void QTC_Core::firstRunCheck()
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
        firstRun.setText(tr("It seems like you are running QTC for the first time, or the application settings were erased. "
            "All settings are set to default now."));
        firstRun.exec();

    }
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
        firstRun.setText(tr("It seems like you are running QTC for the first time, or the application settings were erased. "
            "All settings are set to default now."));
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
        appUpdated.setText(tr("Your QTC has been updated since the last run"));
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

    QSettings settings;

    if (applicationSettingsToUpdate().size() > 0) {
        QMap<QString,QVariant>::iterator i;
//        for (auto& item: *changedSettings()) {
        for (i = applicationSettingsToUpdate().begin(); i != applicationSettingsToUpdate().end(); ++i) {
            qDebug() << "element [" << i.key() << "]: " << i.value();
            qDebug() << "element type: " << i.value().type();
            qDebug() << "element type name: " << i.value().typeName();
            settings.setValue(i.key(),i.value());
//            if (i.key() == "Application/locale") {
//                qtcApp->readSettings();
//                qtcApp->switchTranslation(i.value().toLocale());
//            }
    //        qDebug() << "element: " << item.typeToName();

        }
    } else {

        qDebug() << "No changes";

    }

}

void QTC_Core::setApplicationUser(const QString& user)
{
    m_appUser = user;
}

void QTC_Core::setApplicationPath(const QString& path)
{
    m_appPath = path;
}

void QTC_Core::setApplicationLocale(const QLocale& locale)
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

QTC_Core::SetMap& QTC_Core::applicationSettingsToUpdate()
{
    return m_settingsToUpdate;
}

//QSettings& QTC_Core::applicationSettings()
//{
//    return m_appSettings;
//}

QString QTC_Core::applicationPath()
{
    return m_appPath;
}

QLocale QTC_Core::systemLocale()
{
    return m_sysLocale;
}

QTC_Core::LocMap& QTC_Core::applicationTranslations()
{

}

QWidget* QTC_Core::getMainWinInstance()
{
    if (topLevelWidgets()[0])
        return topLevelWidgets()[0];
    else
        return nullptr;
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

void QTC_Core::onQuit()
{
    writeSettings();
}
