#include "helpwindow.h"


/* Help Window Constructor */
helpWindow::helpWindow(mainWindow *parent) : QDialog(parent)
{
    /* Help Window */
    setFixedSize(400, 450);

    setWindowFlags((windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowContextHelpButtonHint);

    QPalette palette1;
    palette1.setColor(QPalette::Window, QColor(225, 225, 225, 255));
    setPalette(palette1);

    setFont(QFont("Arial", 10));
    setWindowTitle(tr("Hash Verificator Tool - v. 1.0 - Aide"));
    setWindowIcon(QIcon("images/icon.png"));

    /* Header */
    QWidget *header = new QWidget(this);
    header->setGeometry(0, 9, 400, 55);

    QLabel *appName = new QLabel(header);
    appName->setGeometry(0, 0, 400, 16);
    appName->setFont(QFont("Arial", 10, QFont::Bold));
    QPalette palette2;
    palette2.setColor(QPalette::WindowText, QColor(0, 0, 127, 255));
    appName->setPalette(palette2);
    appName->setText("Hash Verificator Tool - v. 1.0");
    appName->setAlignment(Qt::AlignCenter);

    QLabel *appDev = new QLabel(header);
    appDev->setGeometry(0, 18, 400, 16);
    appDev->setText(tr("Créé et développé par Seb2lyon"));
    appDev->setAlignment(Qt::AlignCenter);

    QLabel *appDate = new QLabel(header);
    appDate->setGeometry(0, 37, 400, 16);
    appDate->setFont(QFont("Arial", 9, QFont::Normal, true));
    appDate->setText(tr("05/08/2020"));
    appDate->setAlignment(Qt::AlignCenter);

    /* User guide zone */
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setGeometry(9, 73, 382, 334);
    QPalette palette3;
    palette3.setColor(QPalette::Window, QColor(255, 255, 255, 255));
    scrollArea->setPalette(palette3);
    scrollArea->setFont(QFont("Arial", 9));

    QLabel *helpTitle = new QLabel;
    helpTitle->setFont(QFont("Arial", 10, QFont::Bold));
    helpTitle->setText(tr("    Mode d'emploi"));
    helpTitle->setAlignment(Qt::AlignCenter);

    QLabel *helpText = new QLabel;
    helpText->setOpenExternalLinks(true);
    helpText->setText(tr("<html><head/><body><p align=\"justify\"><span style=\" color:#ff0000;\">1. Fichier à vérifier : </span>sélectionnez le fichier sur votre ordinateur en cliquant sur le bouton <span style=\" font-weight:600;\">Rechercher</span> (ou faites un glisser/déposer de ce fichier dans la fenêtre du logiciel).</p><p align=\"justify\"><span style=\" color:#ff0000;\">2. Choix de l'algorithme : </span>sélectionnez l’algorithme de hash en cliquant sur la puce souhaitée.</p><p align=\"justify\"><span style=\" color:#ff0000;\">3. Hash du fichier : </span>lancer le calcul du hash du fichier en cliquant sur le bouton <span style=\" font-weight:600;\">Calculer</span>.<br/><span style=\" font-weight:600; text-decoration: underline;\">ATTENTION</span> : le processus peut être très long en fonction de la taille du fichier sélectionné.<br/>Une fois le hash obtenu, il s’affiche dans la ligne de formulaire du logiciel.<br/>- Vous pourrez alors l’afficher en majuscule ou en minuscule en cochant la <span style=\" font-weight:600;\">case Majuscule</span> ou en la décochant.<br/>- Vous pourrez également copier le hash affiché dans la mémoire tampon de votre ordinateur en cliquant sur le bouton <span style=\" font-weight:600;\">Copier</span>.<br/>- Vous pourrez enfin cliquer sur le bouton <span style=\" font-weight:600;\">Enregistrer </span>afin de générer automatiquement un document texte (.txt) qui résumera toutes les caractéristiques de votre fichier (ainsi que son hash). Après avoir donné un nom à ce document, il sera enregistré sur votre disque dur à l’emplacement de votre choix.</p><p align=\"justify\"><span style=\" color:#ff0000;\">4. Vérification : </span>si vous le souhaitez, vous pourrez comparer la hash généré avec un autre hash que vous collerez dans la ligne du formulaire du logiciel. Cela vous permettra de vérifier l’intégrité de votre fichier.<br/>Vous pourrez coller un hash précédemment copié (sur le site de téléchargement de votre fichier, par exemple) en cliquant sur le bouton <span style=\" font-weight:600;\">Coller</span> du logiciel, ou en faisant un clic-droit dans la case puis en sélectionnant « Coller » dans le menu contextuel.<br/>Vous pourrez ensuite cliquer sur le bouton <span style=\" font-weight:600;\">Comparer</span> afin de vérifier si les deux hash sont identiques.</p><p align=\"justify\">N’hésitez pas à visiter mon site web : <a href=\"http://seb2lyon.info.free.fr/\"><span style=\" text-decoration: underline; color:#0000ff;\">http://seb2lyon.info.free.fr</span></a></p><p><span style=\" font-style:italic; color:#000000;\">Enjoy :-)</span></p></body></html>"));
    helpText->setWordWrap(true);

    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->setContentsMargins(9, 3, 9, 9);
    verticalLayout->addWidget(helpTitle);
    verticalLayout->addWidget(helpText);

    QWidget *scrollAreaContent = new QWidget;
    scrollAreaContent->setGeometry(0, 0, 363, 610);
    scrollAreaContent->setLayout(verticalLayout);

    scrollArea->setWidget(scrollAreaContent);

    /* Close button */
    QPushButton *closeButton = new QPushButton(this);
    closeButton->setGeometry(158, 416, 85, 25);
    closeButton->setFont(QFont("Arial", 10, QFont::Bold));
    closeButton->setText(tr("Fermer"));

    QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

void helpWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}
