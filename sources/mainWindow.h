#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class mainWindow : public QWidget
{
    Q_OBJECT

    public:
    	mainWindow();

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



        /* Call help window */
        void showHelpWindow();

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
};

#endif // MAINWINDOW_H
