#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class mainWindow : public QWidget
{
    Q_OBJECT

    public:
    	mainWindow();
        void dragEnterEvent(QDragEnterEvent *event); /* Drag file function */
        void dropEvent(QDropEvent *event); /* Drop file function */
        void closeEvent(QCloseEvent *event2); /* Close window */

        /* Getters */
        QString getFileSelectedPath();
        QString getHashAlgorith();

        /* Setters */
        void setHash(QString hashString);

    public slots:
        /* Call search file window */
        void showSearchFileWindow();

        /* Treatment on the selected file */
        void selectedFileTreatment(QString completeFilePath);

        /* Hash selected */
        void hashSelectedMD4();
        void hashSelectedMD5();
        void hashSelectedSHA1();
        void hashSelectedSHA256();

        /* Open wait hash window */
        void showWaitHashWindow();

        /* Upper case checkbox */
        void upperCaseState(int state);

        /* Copy hash to clipboard */
        void copyHashToClipboard();

        /* Save Hash in a file */
        void saveHash();

        /* Treatment on saving file */
        void saveFileTreatment(QString completeFilePath);

        /* Paste hash from clipboard */
        void pasteHashFromClipboard();

        /* Verify is the 2 hashes are identical or not */
        void verifyHash();

        /* Call help window */
        void showHelpWindow();

        /* Quit application 1/2 */
        void quitApp();

    signals:
        /* Quit application 2/2 */
        void closeApp();

    private:
        /* Group 1 */
        QPushButton *selectButton;
        QLabel *fileToChoose;

        /* Group 2 */
        QRadioButton *MD4;
        QRadioButton *MD5;
        QRadioButton *SHA1;
        QRadioButton *SHA256;

        /* Group 3 */
        QLineEdit *hashResult;
        QPushButton *calculateButton;
        QPushButton *copy;
        QPushButton *save;
        QCheckBox *upperCase;

        /* Group 4 */
        QLineEdit *hashInput;
        QPushButton *paste;
        QPushButton *compare;
        QLabel *icon_verify;
        QLabel *verify;

        /* Footer */
        QLabel *webSite;
        QPushButton *quit;
        QPushButton *about;

        /* File for hash */
        QString fileSelectedPath;

        /* Algorith for hash */
        QString hashAlgorith;

        /* Hash result */
        QString hash;

        /* Save hash content */
        QString *contentFile;
};

#endif // MAINWINDOW_H
