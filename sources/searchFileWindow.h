#ifndef SEARCHFILEWINDOW_H
#define SEARCHFILEWINDOW_H

#include <QtWidgets>
#include "mainWindow.h"

class searchFileWindow : public QFileDialog
{
    Q_OBJECT

    public:
        searchFileWindow(mainWindow *parent);
};

#endif // SEARCHFILEWINDOW_H
