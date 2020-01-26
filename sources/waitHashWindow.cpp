#include "waitHashWindow.h"


/* Wait hash process window constructor */
waitHashWindow::waitHashWindow() : QDialog()
{
    setFixedSize(300, 200);

    setFont(QFont("Arial", 10));

    setWindowTitle(tr("Hash Verificator Tool - v. 1.0 - Calcul en cours..."));
    setWindowIcon(QIcon("images/icon.png"));

    QLabel *waitMessage = new QLabel(this);
    waitMessage->setGeometry(9, 20, 282, 44);
    waitMessage->setFont(QFont("Arial", 12, QFont::Bold, true));
    waitMessage->setText(tr("Veuillez patienter...\nCalcul du hash en cours !!"));
    waitMessage->setAlignment(Qt::AlignCenter);
}
