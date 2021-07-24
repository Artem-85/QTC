#include <QTC_Core.h>
#include <QTC_Configuration.h>
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

    return theApp.exec();
}
