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

    mainWindow appWindow;
    appWindow.show();

    return app.exec();
}
