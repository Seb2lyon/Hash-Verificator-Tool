#include "mainWindow.h"
#include "helpwindow.h"
#include "searchFileWindow.h"


/* Main Window Constructor */
mainWindow::mainWindow() : QWidget()
{ 
    /* Main Window */
    setFixedSize(500, 550);

    QPalette palette1;
    palette1.setColor(QPalette::Window, QColor(225, 225, 225, 255));
    setPalette(palette1);

    setFont(QFont("Arial", 10));

    setWindowTitle("Hash Verificator Tool - v. 1.0");

    setWindowIcon(QIcon("images/icon.png"));

    /* 1. Banner */
    QLabel *banner = new QLabel(this);
    banner->setPixmap(QPixmap("images/banner.jpeg"));
    banner->setGeometry(0, 0, 500, 100);
    banner->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    /* 2. App page */
    QWidget *page = new QWidget(this);
    page->setGeometry(0, 105, 500, 450);

	/* 2.1 Header zone */    
    QLabel *header = new QLabel(page);
    header->setGeometry(9, 0, 482, 76);

    /* 2.1.1 Title */
    QLabel *title = new QLabel(header);
    title->setGeometry(115, 2, 251, 20),
    title->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    title->setFont(QFont("Arial", 10, QFont::Bold));
    title->setText(tr("Bienvenue sur \"Hash Verificator Tool\""));
    
    /* 2.1.2 Message */
    QLabel *message = new QLabel(header);
    message->setGeometry(0, 24, 482, 48);
    message->setText(tr("Ce logiciel vous permettra de calculer la signature numérique de vos fichiers\ntéléchargés afin de vérifier leur intégrité.\nLe mode d'emploi est disponible en cliquant sur le bouton \"Aide\" (en bas à droite)."));

    /* 2.2 Group 1 zone */
    QGroupBox *group1 = new QGroupBox(page);
    group1->setGeometry(9, 81, 482, 58);
    group1->setTitle(tr("1. Fichier à vérifier"));

    /* 2.2.1 Label Group 1 */
    QLabel *fileSelected = new QLabel(group1);
    fileSelected->setGeometry(10, 25, 51, 16);
    fileSelected->setText(tr("Fichier : "));

    /* 2.2.2 Search Button Group 1 */
    selectButton = new QPushButton(group1);
    selectButton->setGeometry(62, 21, 85, 25);
    selectButton->setFont(QFont("Arial", 10, QFont::Bold));
    selectButton->setText(tr("Rechercher"));

    /* 2.2.3 Search result label Group 1 */
    fileSelectedPath = "";
    fileToChoose = new QLabel(group1);
    fileToChoose->setGeometry(162, 25, 311, 16);
    fileToChoose->setFont(QFont("Arial", 10, QFont::Bold, true));
    fileToChoose->setText("");
    fileToChoose->setToolTip("");

    /* 2.3 Group 2 zone */
    QGroupBox *group2 = new QGroupBox(page);
    group2->setGeometry(9, 144, 482, 54);
    group2->setTitle(tr("2. Choix de l'algorithme"));

    /* 2.3.1 Radio Buttons Group 2 */
    hashAlgorith = "MD5";

    MD4 = new QRadioButton(group2);
    MD4->setGeometry(10, 25, 51, 19);
    MD4->setText("MD4");

    MD5 = new QRadioButton(group2);
    MD5->setGeometry(100, 25, 51, 19);
    MD5->setChecked(true);
    MD5->setText("MD5");

    SHA1 = new QRadioButton(group2);
    SHA1->setGeometry(190, 25, 57, 19);
    SHA1->setText("SHA1");

    SHA256 = new QRadioButton(group2);
    SHA256->setGeometry(280, 25, 72, 19);
    SHA256->setText("SHA256");

    /* 2.4 Group 3 zone */
    QGroupBox *group3 = new QGroupBox(page);
    group3->setGeometry(9, 203, 482, 94);
    group3->setTitle(tr("3. Hash du fichier"));

    /* 2.4.1 Label  Group 3 */
    QLabel *hash1 = new QLabel(group3);
    hash1->setGeometry(10, 30, 42, 16);
    hash1->setText("Hash : ");

    /* 2.4.2 Line edit Group 3 */
    hashResult = new QLineEdit(group3);
    hashResult->setGeometry(53, 28, 420, 21);
    hashResult->setFont(QFont("Arial", 8));
    QPalette palette2;
    palette2.setColor(QPalette::Base, QColor(235, 235, 235, 255));
    hashResult->setPalette(palette2);
    hashResult->setReadOnly(true);

    /* 2.4.3 Calculate Button Group 3 */
    calculateButton = new QPushButton(group3);
    calculateButton->setGeometry(53, 59, 85, 25);
    calculateButton->setFont(QFont("Arial", 10, QFont::Bold));
    calculateButton->setText(tr("Calculer"));

    /* 2.4.4 Copy Button Group 3 */
    copy = new QPushButton(group3);
    copy->setGeometry(289, 59, 85, 25);
    copy->setText(tr("Copier"));

    /* 2.4.5 Save Button Group 3 */
    save = new QPushButton(group3);
    save->setGeometry(388, 59, 85, 25);
    save->setText(tr("Enregistrer"));

    /* 2.4.6 CheckBox Group 3 */
    upperCase = new QCheckBox(group3);
    upperCase->setGeometry(197, 62, 82, 19);
    upperCase->setText(tr("Majuscule"));

    /* 2.5 Group 4 zone */
    QGroupBox *group4 = new QGroupBox(page);
    group4->setGeometry(9, 302, 482, 94);
    group4->setTitle(tr("4. Vérification"));

    /* 2.5.1 Label  Group 4 */
    QLabel *hash2 = new QLabel(group4);
    hash2->setGeometry(10, 30, 42, 16);
    hash2->setText("Hash : ");

    /* 2.5.2 Line edit  Group 4 */
    hashInput = new QLineEdit(group4);
    hashInput->setGeometry(53, 28, 420, 21);
    hashInput->setFont(QFont("Arial", 8));

    /* 2.5.3 Paste button Group 4 */
    paste = new QPushButton(group4);
    paste->setGeometry(53, 59, 85, 25);
    paste->setText(tr("Coller"));

    /* 2.5.4 Compare button Group 4 */
    compare = new QPushButton(group4);
    compare->setGeometry(388, 59, 85, 25);
    compare->setFont(QFont("Arial", 10, QFont::Bold));
    compare->setText(tr("Comparer"));

    /* 2.5.5 Result verification (icon) Group 4 */
    icon_verify = new QLabel(group4);
    icon_verify->setGeometry(200, 62, 20, 20);
    icon_verify->setPixmap(QPixmap(""));

    /* If the 2 hashes are identical : QPixmap("images/same.png") */
    /* If the 2 hashes are different : QPixmap("images/different.png") */

    /* 2.5.6 Result verification Group 4 */
    verify = new QLabel(group4);
    verify->setGeometry(225, 64, 121, 16);
    verify->setFont(QFont("Arial", 10, QFont::Bold));
    QPalette palette3;
    palette3.setColor(QPalette::WindowText, QColor(255, 0, 0, 255));
    verify->setPalette(palette3);
    verify->setText(tr(""));

    /* If the 2 hashes are identical : palette3.setColor(QPalette::WindowText, QColor(0, 170, 0, 255)) + verify->setText(tr("Hash identiques")) */
    /* If the 2 hashes are different : verify->setText(tr("Hash différents")) */

    /* 2.6 Footer zone */
    QWidget *footer = new QWidget(page);
    footer->setGeometry(9, 399, 482, 44);

    /* 2.6.1 Link to web site */
    webSite = new QLabel(footer);
    webSite->setGeometry(0, 14, 147, 16);
    webSite->setText("<html><head/><body><p><a href=\"http://seb2lyon.info.free.fr\"><span style=\" text-decoration: underline; color:#0000ff;\">http://seb2lyon.info.free.fr</span></a></p></body></html>");
    webSite->setTextFormat(Qt::RichText);

    /* 2.6.2 Quit button */
    quit = new QPushButton (footer);
    quit->setGeometry(199, 9, 85, 25);
    quit->setFont(QFont("Arial", 10, QFont::Bold));
    quit->setText(tr("Quitter"));

    /* 2.6.3 Help button */
    about = new QPushButton(footer);
    about->setGeometry(453, 7, 30, 30);
    about->setIcon(QIcon("images/help.png"));

    /* Connexions */
    QObject::connect(selectButton, SIGNAL(clicked()), this, SLOT(showSearchFileWindow())); /* Open search file window */
    QObject::connect(MD4, SIGNAL(clicked()), this, SLOT(hashSelectedMD4())); /* MD4 selected */
    QObject::connect(MD5, SIGNAL(clicked()), this, SLOT(hashSelectedMD5())); /* MD5 selected */
    QObject::connect(SHA1, SIGNAL(clicked()), this, SLOT(hashSelectedSHA1())); /* SHA1 selected */
    QObject::connect(SHA256, SIGNAL(clicked()), this, SLOT(hashSelectedSHA256())); /* SHA256 selected */



    QObject::connect(about, SIGNAL(clicked()), this, SLOT(showHelpWindow())); /* Open help window */

}

/* Call search file window */
void mainWindow::showSearchFileWindow()
{
    searchFileWindow fileDialog(this);
    fileDialog.exec();
}

/* Treatment on the selected file */
void mainWindow::selectedFileTreatment(QString completeFilePath)
{
    QFile file(completeFilePath);

    if(!completeFilePath.isEmpty() && file.open(QIODevice::ReadOnly))
    {
        fileSelectedPath = completeFilePath;
        QFileInfo infoFile(fileSelectedPath);
        QString fileName = infoFile.fileName();
        int fileNameSize = fileName.size();
        QPalette palette1;
        palette1.setColor(QPalette::WindowText, QColor(0, 0, 255, 255));
        fileToChoose->setPalette(palette1);

        if(fileNameSize > 30)
        {
            QString shortName = fileName.mid(0, 25) + " (...)";
            fileToChoose->setText(shortName);
            fileToChoose->setToolTip(fileName);
        }
        else
        {
            fileToChoose->setText(fileName);
            fileToChoose->setToolTip("");
        }
    }
    else
    {
        fileSelectedPath = "";
        QPalette palette2;
        palette2.setColor(QPalette::WindowText, QColor(255, 0, 0, 255));
        fileToChoose->setPalette(palette2);
        fileToChoose->setText(tr("Aucun fichier séléctionné"));
        fileToChoose->setToolTip("");
    }

    file.close();
}

/* Hash selected */
void mainWindow::hashSelectedMD4()
{
    hashAlgorith = "MD4";
}

void mainWindow::hashSelectedMD5()
{
    hashAlgorith = "MD5";
}

void mainWindow::hashSelectedSHA1()
{
    hashAlgorith = "SHA1";
}

void mainWindow::hashSelectedSHA256()
{
    hashAlgorith = "SHA256";
}





/* Call help window */
void mainWindow::showHelpWindow()
{
    helpWindow appHelpWindow;
    appHelpWindow.exec();
}
