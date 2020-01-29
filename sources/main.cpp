/******************************************
 *      Hash Verificator Tool v. 1.0      *
 *                 -------                *
 *            Coder : Seb2lyon            *
 *     from 18-01-2020 to XX-XX-2020      *
 *                                        *
 *                Enjoy ;)                *
 *****************************************/

#include <QApplication>
#include "mainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);

    QTranslator translator1;
    translator1.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));

    app.installTranslator(&translator1);

    mainWindow appWindow;
    appWindow.show();

    return app.exec();
}
