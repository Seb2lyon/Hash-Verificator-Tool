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

    QLabel *waitMessage = new QLabel(this);
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

    hashCalculator();

    QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}


/* Hash calculator function */
void waitHashWindow::hashCalculator()
{
    QFile file(parentLink->getFileSelectedPath());

    if(file.open(QIODevice::ReadOnly))
    {
        if(file.size() == 0)
        {
            progressBar->setValue(100);
            parentLink->setHash("");
            QMessageBox::information(this, tr("Fichier vide"), tr("<html><head></head><body><p><span style=\" font-weight:600;\">Fichier vide...</span><br/>Aucun hash n'a pu être calculé !</p></body></html>"));
        }
        else
        {
            int partFile = (file.size()) / 1024;

            int loop = 1;

            int percent = 0;

            if(parentLink->getHashAlgorith() == "Md4")
            {
                hasher = new QCryptographicHash(QCryptographicHash::Md4);
            }
            else if(parentLink->getHashAlgorith() == "Md5")
            {
                hasher = new QCryptographicHash(QCryptographicHash::Md5);
            }
            else if(parentLink->getHashAlgorith() == "Sha1")
            {
                hasher = new QCryptographicHash(QCryptographicHash::Sha1);
            }
            else if(parentLink->getHashAlgorith() == "Sha256")
            {
                hasher = new QCryptographicHash(QCryptographicHash::Sha256);
            }

            while(!file.atEnd())
            {
                hasher->addData(file.read(1024));
                if(partFile > 0)
                {
                    percent = (loop * 100) / partFile;
                    progressBar->setValue(percent);
                    loop++;
                }
                else
                {
                    progressBar->setValue(100);
                }
            }

            parentLink->setHash(hasher->result().toHex());
        }

        file.close();
    }
}
