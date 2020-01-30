#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QtWidgets>
#include "mainWindow.h"

class helpWindow : public QDialog
{
    Q_OBJECT

    public:
        helpWindow(mainWindow *parent);
        void closeEvent(QCloseEvent *event);
};

#endif // HELPWINDOW_H
