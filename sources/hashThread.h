#ifndef HASHTHREAD_H
#define HASHTHREAD_H

#include <QtWidgets>
#include "mainWindow.h"

class hashThread : public QThread
{
    Q_OBJECT

    public:
        hashThread(mainWindow *parent);

    public slots:
        void run();

    signals:
        void changeValue(int); /* Update progress bar value */
        void complete(); /* End of the hash calculation process */

    private:
        mainWindow *parentLink; /* Link to the parent window */
        QCryptographicHash *hasher; /* Hasher */
};

#endif // HASHTHREAD_H
