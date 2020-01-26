#include "searchFileWindow.h"


/* Search File window constructor */
searchFileWindow::searchFileWindow(mainWindow *parent) : QFileDialog()
{
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(225, 225, 225, 255));
    setPalette(palette);

    setFont(QFont("Arial", 10));

    setWindowTitle(tr("Hash Verificator Tool - v. 1.0 - Choix du fichier"));
    setWindowIcon(QIcon("images/icon.png"));

    setDirectory(QDir::homePath());

    QObject::connect(this, SIGNAL(fileSelected(QString)), parent, SLOT(selectedFileTreatment(QString)));
}

