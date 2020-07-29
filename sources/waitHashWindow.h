#ifndef WAITHASHWINDOW_H
#define WAITHASHWINDOW_H

#include <QtWidgets>
#include "mainWindow.h"
#include "hashThread.h"

class waitHashWindow : public QDialog
{
    Q_OBJECT

    public:
        waitHashWindow(mainWindow *parent);

    private:
        mainWindow *parentLink; /* Main window link */
        QLabel *waitMessage; /* Wait message */
        QProgressBar *progressBar; /* Progress bar */
        QPushButton *cancelButton; /* Cancel button */
        hashThread *thread; /* Thread for hash calculator */

    private slots:
        void newValue(int); /* Update progress bar value */
        void endProcess(); /* End of the hash calculation process */
};

#endif // WAITHASHWINDOW_H
