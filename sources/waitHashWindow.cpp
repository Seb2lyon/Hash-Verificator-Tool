#include "waitHashWindow.h"


/* Wait hash process window constructor */
waitHashWindow::waitHashWindow(mainWindow *parent) : QDialog(parent)
{
    setFixedSize(300, 200);

    setWindowFlags((windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowContextHelpButtonHint);

    parentLink = parent;

    setFont(QFont("Arial", 10));

    setWindowTitle(tr("Hash Verificator Tool - v. 1.0 - Calcul..."));
    setWindowIcon(QIcon("images/icon.png"));

    waitMessage = new QLabel(this);
    waitMessage->setGeometry(9, 20, 282, 44);
    waitMessage->setFont(QFont("Arial", 12, QFont::Bold, true));
    waitMessage->setText(tr("Veuillez patienter...\nCalcul du hash en cours !!"));
    waitMessage->setAlignment(Qt::AlignCenter);

    progressBar = new QProgressBar(this);
    progressBar->setGeometry(12, 95, 282, 20);
    progressBar->setValue(0);

    cancelButton = new QPushButton(this);
    cancelButton->setGeometry(107, 160, 85, 25);
    cancelButton->setText(tr("Annuler"));

    thread = new hashThread(parent);
    thread->start();

    QObject::connect(thread, SIGNAL(changeValue(int)), this, SLOT(newValue(int)));
    QObject::connect(thread, SIGNAL(complete()), this, SLOT(endProcess()));
    QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}

/* Update progress bar value */
void waitHashWindow::newValue(int value)
{
    progressBar->setValue(value);
}

/* End of the hash calculation process */
void waitHashWindow::endProcess()
{
    QPalette palette1;
    palette1.setColor(QPalette::WindowText, QColor(0, 0, 255, 255));
    waitMessage->setPalette(palette1);
    waitMessage->setText(tr("Le calcul du hash est terminé !!!"));
    cancelButton->setFont(QFont("Arial", 10, QFont::Bold));
    cancelButton->setText(tr("Terminé"));
}
