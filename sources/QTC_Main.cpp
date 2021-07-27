#include <QTC_Configuration.h>
#include <QTC_Core.h>
#ifdef BUILD_DEBUG
    #include <QDebug>
#endif
//#include <QLocale>
//#include <QTranslator>

int main(int argc, char *argv[])
{
    QTC_Core theApp(argc, argv);
//    QApplication theApp(argc, argv);

//    QTranslator translator;
//    const QStringList uiLanguages = QLocale::system().uiLanguages();
//    for (const QString &locale : uiLanguages) {
//        const QString baseName = "QTC_" + QLocale(locale).name();
//        if (translator.load(":/i18n/" + baseName)) {
//            a.installTranslator(&translator);
//            break;
//        }
//    }
    #ifdef BUILD_DEBUG
        qDebug() << "Application started";
        qDebug() << "Application user: " << theApp.applicationUser();
        qDebug() << "Application locale: " << theApp.applicationLocale();
        qDebug() << "Application directory: " << theApp.applicationPath();
        qDebug() << "System locale: " << theApp.systemLocale();
    #endif

    return theApp.exec();
}
