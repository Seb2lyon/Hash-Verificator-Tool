#include "mainWindow.h"
#include "helpwindow.h"
#include "searchFileWindow.h"
#include "waitHashWindow.h"


/* Main Window Constructor */
mainWindow::mainWindow() : QWidget()
{ 
    /* Main Window */
    setWindowFlags((windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowMinimizeButtonHint & ~Qt::WindowMaximizeButtonHint);

    setAcceptDrops(true);

    setFixedSize(500, 550);

    QPalette palette1;
    palette1.setColor(QPalette::Window, QColor(225, 225, 225, 255));
    setPalette(palette1);

    setFont(QFont("Arial", 10));

    setWindowTitle("Hash Verificator Tool - v. 1.0");

    setWindowIcon(QIcon("images/icon.png"));

    /* 1. Banner */
    QLabel *banner = new QLabel(this);
    banner->setPixmap(QPixmap("images/banner.png"));
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
    hashAlgorith = "Md5";

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
    hash = "";
    hashResult = new QLineEdit(group3);
    hashResult->setGeometry(53, 28, 420, 21);
    hashResult->setFont(QFont("Arial", 8));
    QPalette palette2;
    palette2.setColor(QPalette::Base, QColor(235, 235, 235, 255));
    hashResult->setPalette(palette2);
    hashResult->setReadOnly(true);
    hashResult->setText(hash);

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

    /* 2.5.6 Result verification Group 4 */
    verify = new QLabel(group4);
    verify->setGeometry(225, 64, 121, 16);
    verify->setFont(QFont("Arial", 10, QFont::Bold));
    QPalette palette3;
    palette3.setColor(QPalette::WindowText, QColor(255, 255, 255, 255));
    verify->setPalette(palette3);
    verify->setText(tr(""));

    /* 2.6 Footer zone */
    QWidget *footer = new QWidget(page);
    footer->setGeometry(9, 399, 482, 44);

    /* 2.6.1 Link to web site */
    QString link("<html><head/><body><p><a href=\"http://seb2lyon.info.free.fr\"><span style=\" text-decoration: underline; color:#0000ff;\">http://seb2lyon.info.free.fr</span></a></p></body></html>");
    webSite = new QLabel(footer);
    webSite->setGeometry(0, 14, 147, 16);
    webSite->setOpenExternalLinks(true);
    webSite->setText(link);

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
    QObject::connect(calculateButton, SIGNAL(clicked()), this, SLOT(showWaitHashWindow())); /* Open wait hash window */
    QObject::connect(upperCase, SIGNAL(stateChanged(int)), this, SLOT(upperCaseState(int))); /* Upper case checkbox */
    QObject::connect(copy, SIGNAL(clicked()), this, SLOT(copyHashToClipboard())); /* Copy hash to clipboard */
    QObject::connect(save, SIGNAL(clicked()), this, SLOT(saveHash())); /* Save Hash in a file */
    QObject::connect(paste, SIGNAL(clicked()), this, SLOT(pasteHashFromClipboard())); /* Paste hash from clipboard */
    QObject::connect(compare, SIGNAL(clicked()), this, SLOT(verifyHash())); /* Verify is the 2 hashes are identical or not */
    QObject::connect(about, SIGNAL(clicked()), this, SLOT(showHelpWindow())); /* Open help window */
    QObject::connect(quit, SIGNAL(clicked()), this, SLOT(quitApp())); /* Quit application 1/2 */
    QObject::connect(this, SIGNAL(closeApp()), qApp, SLOT(quit()));  /* Quit application 2/2 */
}

/* Call search file window */
void mainWindow::showSearchFileWindow()
{
    searchFileWindow searchFileDialog(this);
    searchFileDialog.exec();
}

/* Treatment on the selected file */
void mainWindow::selectedFileTreatment(QString completeFilePath)
{
    QFile file(completeFilePath);

    if(!completeFilePath.isEmpty() && file.open(QIODevice::ReadOnly))
    {
        hashResult->setText("");
        hash = "";
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
        hash = "";
        hashResult->setText("");
        QPalette palette2;
        palette2.setColor(QPalette::WindowText, QColor(255, 0, 0, 255));
        fileToChoose->setPalette(palette2);
        fileToChoose->setText(tr("Aucun fichier sélectionné"));
        fileToChoose->setToolTip("");
        QMessageBox::critical(this, tr("Erreur"), tr("<html><head></head><body><span style=\" font-weight:600;\">Aucun fichier valide sélectionné...</span><br/>Veuillez réessayer !</body></html>"));
    }

    file.close();
}

/* Drag file function */
void mainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();
    }
    else
    {
        fileSelectedPath = "";
        hash = "";
        hashResult->setText("");
        QMessageBox::critical(this, tr("Erreur"), tr("<html><head></head><body><span style=\" font-weight:600;\">Aucun fichier valide sélectionné...</span><br/>Veuillez réessayer !</body></html>"));
        QPalette palette2;
        palette2.setColor(QPalette::WindowText, QColor(255, 0, 0, 255));
        fileToChoose->setPalette(palette2);
        fileToChoose->setText(tr("Aucun fichier sélectionné"));
        fileToChoose->setToolTip("");
    }
}

/* Drop file function */
void mainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urlList = event->mimeData()->urls();
    int nbrUrl = urlList.count();

    if(urlList.isEmpty() || nbrUrl == 0)
    {
        fileSelectedPath = "";
        hash = "";
        hashResult->setText("");
        QMessageBox::critical(this, tr("Erreur"), tr("<html><head></head><body><span style=\" font-weight:600;\">Aucun fichier valide sélectionné...</span><br/>Veuillez réessayer !</body></html>"));
        QPalette palette1;
        palette1.setColor(QPalette::WindowText, QColor(255, 0, 0, 255));
        fileToChoose->setPalette(palette1);
        fileToChoose->setText(tr("Aucun fichier sélectionné"));
        fileToChoose->setToolTip("");
    }
    else if(nbrUrl > 1)
    {
        fileSelectedPath = "";
        hash = "";
        hashResult->setText("");
        QMessageBox::critical(this, tr("Erreur"), tr("<html><head></head><body><span style=\" font-weight:600;\">Vous ne pouvez sélectionner qu'un seul fichier...</span><br/>Veuillez réessayer !</body></html>"));
        QPalette palette1;
        palette1.setColor(QPalette::WindowText, QColor(255, 0, 0, 255));
        fileToChoose->setPalette(palette1);
        fileToChoose->setText(tr("Aucun fichier sélectionné"));
        fileToChoose->setToolTip("");
    }
    else
    {
        const QUrl url = urlList.at(0);
        fileSelectedPath = url.toLocalFile();
        hashResult->setText("");
        hash = "";

        QFileInfo infoFile(fileSelectedPath);
        if(!infoFile.isFile())
        {
            fileSelectedPath = "";
            hash = "";
            hashResult->setText("");
            QMessageBox::critical(this, tr("Erreur"), tr("<html><head></head><body><span style=\" font-weight:600;\">Aucun fichier valide sélectionné...</span><br/>Veuillez réessayer !</body></html>"));
            QPalette palette1;
            palette1.setColor(QPalette::WindowText, QColor(255, 0, 0, 255));
            fileToChoose->setPalette(palette1);
            fileToChoose->setText(tr("Aucun fichier sélectionné"));
            fileToChoose->setToolTip("");
        }
        else
        {
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
    }
}

/* Hash selected */
void mainWindow::hashSelectedMD4()
{
    hashAlgorith = "Md4";
    hashResult->setText("");
    hash = "";
}

void mainWindow::hashSelectedMD5()
{
    hashAlgorith = "Md5";
    hashResult->setText("");
    hash = "";
}

void mainWindow::hashSelectedSHA1()
{
    hashAlgorith = "Sha1";
    hashResult->setText("");
    hash = "";
}

void mainWindow::hashSelectedSHA256()
{
    hashAlgorith = "Sha256";
    hashResult->setText("");
    hash = "";
}

/* Call wait hash window */
void mainWindow::showWaitHashWindow()
{
    if(fileSelectedPath.isEmpty())
    {
        QMessageBox::warning(this, tr("Attention"), tr("<html><head></head><body><p>Aucun fichier sélectionné...<br/>Veuillez choisir un fichier en cliquant sur le bouton <span style=\" font-weight:600;\">\"Rechercher\"</span><br/>situé dans la zone <span style=\" color:#ff0000;\">1. Fichier à vérifier</span> ci-dessus.</p></body></html>"));
    }
    else
    {
        QFile file(getFileSelectedPath());

        if(file.open(QIODevice::ReadOnly))
        {
            if(file.size() == 0)
            {
                QMessageBox::information(this, tr("Fichier vide"), tr("<html><head></head><body><p><span style=\" font-weight:600;\">Fichier vide...</span><br/>Aucun hash n'a pu être calculé !</p></body></html>"));
                file.close();
            }
            else
            {
                file.close();

                hashResult->setText("");
                hash = "";

                waitHashWindow appWaitWindow(this);
                appWaitWindow.exec();

                if(upperCase->isChecked())
                {
                    hash = hash.toUpper();
                }
                else
                {
                    hash = hash.toLower();
                }

                hashResult->setText(hash);
            }
        }
    }
}

/* Upper case checkbox */
void mainWindow::upperCaseState(int state)
{
    if(!hash.isEmpty())
    {
        if(state == Qt::Unchecked)
        {
            hash = hash.toLower();
            hashResult->setText(hash);
        }
        else if(state == Qt::Checked)
        {
            hash = hash.toUpper();
            hashResult->setText(hash);
        }
    }
    else
    {
        hashResult->setText("");
    }
}

/* Copy hash to clipboard */
void mainWindow::copyHashToClipboard()
{
    if(hashResult->text() == "")
    {
        QMessageBox::warning(this, tr("Aucun hash calculé"), tr("<html><head></head><body><p><span style=\" font-weight:600;\">Aucun hash calculé...</span><br/>Veuillez choisir un fichier puis calculer son hash en cliquant sur le bouton <span style=\" font-weight:600;\">\"Calculer\"</span> situé dans la zone <span style=\" color:#ff0000;\">3. Hash du fichier</span> ci-dessus.</p></body></html>"));
    }
    else
    {
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(hash);
        QMessageBox::information(this, tr("Copie dans la mémoire tampon"), tr("<html><head></head><body><p><span style=\" font-weight:600;\">Copie effectuée avec succès...</span><br/>Le hash est bien copié dans la mémoire de votre ordinateur !</p></body></html>"));
    }
}

/* Save hash in a file */
void mainWindow::saveHash()
{
    if(hashResult->text() == "")
    {
        QMessageBox::warning(this, tr("Aucun hash calculé"), tr("<html><head></head><body><p><span style=\" font-weight:600;\">Aucun hash calculé...</span><br/>Veuillez choisir un fichier puis calculer son hash en cliquant sur le bouton <span style=\" font-weight:600;\">\"Calculer\"</span> situé dans la zone <span style=\" color:#ff0000;\">3. Hash du fichier</span> ci-dessus.</p></body></html>"));
    }
    else
    {
        QFile file(fileSelectedPath);
        QFileInfo fileInfo(file);

        int fileSize;
        int convertFileSize;
        QString unit;

        fileSize = fileInfo.size();
        
        if(fileSize >= 1000000000)
        {
        	convertFileSize = fileSize / 1000000000;
            unit = tr(" Go");
        }
        else if(fileSize >= 1000000)
        {
        	convertFileSize = fileSize / 1000000;
            unit = tr(" Mo");
        }
        else if(fileSize >= 1000)
        {
        	convertFileSize = fileSize / 1000;
            unit = tr(" Ko");
        }
        else
        {
            convertFileSize = fileSize;
            unit = tr(" o");
        }

        QString stringSize;
        stringSize.setNum(convertFileSize);
        QString completeStringSize;
        completeStringSize.setNum(fileSize);

        contentFile = new QString;
        contentFile->append("=====================================================================\n");
        contentFile->append(tr("Généré par le logiciel Hash Verificator Tool v. 1.0\n"));
        contentFile->append(tr("Le "));
        contentFile->append(QDateTime::currentDateTime().toString(tr("dd/MM/yyyy à HH:mm:ss")));
        contentFile->append("\n");
        contentFile->append(tr("Créé et développé par Seb2lyon\n"));
        contentFile->append("http://seb2lyon.info.free.fr\n");
        contentFile->append("=====================================================================\n\n");
        contentFile->append(tr("Nom du fichier : "));
		contentFile->append(fileInfo.fileName());
		contentFile->append("\n");
        contentFile->append(tr("Chemin d'accès : "));
		contentFile->append(fileInfo.absoluteFilePath());
        contentFile->append("\n");
        contentFile->append(tr("Taille : "));
        if(unit != tr(" o"))
        {
            contentFile->append(completeStringSize);
            contentFile->append(tr(" octets ("));
        }
        contentFile->append(stringSize);
		contentFile->append(unit);
        if(unit != tr(" o"))
        {
            contentFile->append(")");
        }
        contentFile->append("\n");
        contentFile->append(tr("Date de création : "));
		contentFile->append(fileInfo.birthTime().toString(tr("dd/MM/yyyy HH:mm:ss")));
        contentFile->append("\n");
        contentFile->append(tr("Date de modification : "));
        contentFile->append(fileInfo.lastModified().toString(tr("dd/MM/yyyy HH:mm:ss")));
        contentFile->append("\n");
        contentFile->append(tr("Date de dernier accès : "));
		contentFile->append(fileInfo.lastRead().toString(tr("dd/MM/yyyy HH:mm:ss")));
        contentFile->append("\n");
        contentFile->append("Hash ");
        contentFile->append(hashAlgorith);
        contentFile->append(" : ");
        contentFile->append(hash);
        contentFile->append("\n\n=====================================================================\n\n");

        QString filePath;
        QFileDialog saveFileDialog;
        filePath = saveFileDialog.getSaveFileName(this, tr("Hash Verificator Tool - v. 1.0 - Enregistrer le fichier"), QDir::homePath(), tr("Fichier texte (*.txt)"));
        saveFileTreatment(filePath);
    }
}

/* Treatment on saving file */
void mainWindow::saveFileTreatment(QString completeFilePath)
{
    QFile saveHashFile(completeFilePath);
    if(saveHashFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&saveHashFile);
        out << *contentFile;
    }
}

/* Paste hash from clipboard */
void mainWindow::pasteHashFromClipboard()
{
    hashInput->setText("");

    QClipboard *clipboard = QApplication::clipboard();
    QString contentOfClipboard = clipboard->text();

    QRegularExpression hexMatcher32("^[0-9A-F]{32}$", QRegularExpression::CaseInsensitiveOption);
    QRegularExpression hexMatcher40("^[0-9A-F]{40}$", QRegularExpression::CaseInsensitiveOption);
    QRegularExpression hexMatcher64("^[0-9A-F]{64}$", QRegularExpression::CaseInsensitiveOption);

    QRegularExpressionMatch match32 = hexMatcher32.match(contentOfClipboard);
    QRegularExpressionMatch match40 = hexMatcher40.match(contentOfClipboard);
    QRegularExpressionMatch match64 = hexMatcher64.match(contentOfClipboard);


    if(match32.hasMatch() || match40.hasMatch() || match64.hasMatch())
    {
        hashInput->setText(contentOfClipboard);
    }
    else
    {
        QMessageBox::warning(this, tr("Aucun hash dans la mémoire tampon"), tr("<html><head></head><body><p><span style=\" font-weight:600;\">Aucun hash dans la mémoire de votre ordinateur...</span><br/>Assurez-vous de bien avoir copié un hash avant de cliquer sur le bouton <span style=\" font-weight:600;\">\"Coller\"</span>.</p></body></html>"));
    }
}

/* Verify is the 2 hashes are identical or not */
void mainWindow::verifyHash()
{
    QPalette palette3;
    palette3.setColor(QPalette::WindowText, QColor(255, 255, 255, 255));
    verify->setPalette(palette3);
    icon_verify->setPixmap(QPixmap(""));

    if(hashResult->text() != "" && hashInput->text() != "")
    {
        if(hashResult->text().toLower() == hashInput->text().toLower())
        {
            icon_verify->setPixmap(QPixmap("images/same.png"));
            palette3.setColor(QPalette::WindowText, QColor(0, 170, 0, 255));
            verify->setPalette(palette3);
            verify->setText(tr("Hash identiques"));
        }
        else
        {
            icon_verify->setPixmap(QPixmap("images/different.png"));
            palette3.setColor(QPalette::WindowText, QColor(255, 0, 0, 255));
            verify->setPalette(palette3);
            verify->setText(tr("Hash différents"));
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Impossible de lancer une comparaison de hash"), tr("<html><head></head><body><p><span style=\" font-weight:600;\">Il manque des données pour la comparaison...</span><br/>- Veuillez choisir un fichier puis calculer son hash en cliquant sur le bouton <span style=\" font-weight:600;\">\"Calculer\"</span> situé dans la zone <span style=\" color:#ff0000;\">3. Hash du fichier</span> ci-dessus.<br/>- Assurez-vous de bien avoir copié un hash avant de cliquer sur le bouton <span style=\" font-weight:600;\">\"Coller\"</span> situé dans la zone <span style=\" color:#ff0000;\">4. Vérification</span> ci-dessus.</p></body></html>"));
    }
}

/* Quit application */
void mainWindow::quitApp()
{
    int quitAction = QMessageBox::question(this, tr("Quitter"), tr("Voulez-vous vraiment quitter l'application\nHash Verificator Tool ?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if(quitAction == QMessageBox::Yes)
    {
        emit closeApp();
    }
}

/* Close window */
void mainWindow::closeEvent(QCloseEvent *event2)
{
    event2->ignore();
    quitApp();
}

/* Call help window */
void mainWindow::showHelpWindow()
{
    helpWindow appHelpWindow(this);
    appHelpWindow.exec();
}

/* Getters */
QString mainWindow::getFileSelectedPath()
{
    return fileSelectedPath;
}

QString mainWindow::getHashAlgorith()
{
    return hashAlgorith;
}

/* Setters */
void mainWindow::setHash(QString hashString)
{
    hash = hashString;
}
