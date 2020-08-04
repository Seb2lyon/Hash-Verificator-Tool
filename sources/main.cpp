/******************************************
 *      Hash Verificator Tool v. 1.0      *
 *                 -------                *
 *            Coder : Seb2lyon            *
 *     from 18-01-2020 to 05-08-2020      *
 *                                        *
 *                Enjoy ;)                *
 *****************************************/

#include <QApplication>
#include "mainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString local = QLocale::system().name().section('_', 0, 0);

    QTranslator translator;

    if(local == "en")
    {
        translator.load(QString("config/Hash-Verificator-Tool_") + local);
    }
    else
    {
        translator.load(QString("qt_") + local, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    }

    app.installTranslator(&translator);





    mainWindow appWindow;
    appWindow.show();

    return app.exec();
}
