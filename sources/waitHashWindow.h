#ifndef WAITHASHWINDOW_H
#define WAITHASHWINDOW_H

#include <QtWidgets>
#include "mainWindow.h"

class waitHashWindow : public QDialog
{
    Q_OBJECT

    public:
        waitHashWindow(mainWindow *parent);
        void hashCalculator(); /* Launch hash calculator */

    private:
        mainWindow *parentLink; /* Main window link */
        QProgressBar *progressBar; /* Progress bar */
        QPushButton *cancelButton; /* Cancel button */
        QCryptographicHash *hasher; /* Hasher */
};

#endif // WAITHASHWINDOW_H
