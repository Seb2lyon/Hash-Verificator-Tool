#include "searchFileWindow.h"


/* Search File window constructor */
searchFileWindow::searchFileWindow(mainWindow *parent) : QFileDialog()
{
    QPalette palette;

    setWindowTitle(tr("Hash Verificator Tool - v. 1.0 - Choix du fichier"));

    setDirectory(QDir::homePath());

    QObject::connect(this, SIGNAL(fileSelected(QString)), parent, SLOT(selectedFileTreatment(QString)));
}

