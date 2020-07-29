#include "hashThread.h"

/* Hash Thread Constructor */
hashThread::hashThread(mainWindow *parent) : QThread()
{
    parentLink = parent;
}

/* Run the thread */
void hashThread::run()
{
    QFile file(parentLink->getFileSelectedPath());

    if(file.open(QIODevice::ReadOnly))
    {
        int partFile = (file.size()) / 1024;

        int loop = 1;

        int percent = 0;

        if(parentLink->getHashAlgorith() == "Md4")
        {
            hasher = new QCryptographicHash(QCryptographicHash::Md4);
        }
        else if(parentLink->getHashAlgorith() == "Md5")
        {
            hasher = new QCryptographicHash(QCryptographicHash::Md5);
        }
        else if(parentLink->getHashAlgorith() == "Sha1")
        {
            hasher = new QCryptographicHash(QCryptographicHash::Sha1);
        }
        else if(parentLink->getHashAlgorith() == "Sha256")
        {
            hasher = new QCryptographicHash(QCryptographicHash::Sha256);
        }

        while(!file.atEnd())
        {
            hasher->addData(file.read(1024));
            if(partFile > 0)
            {
                percent = (loop * 100) / partFile;
                emit changeValue(percent);
                loop++;
            }
            else
            {
                emit changeValue(100);
            }
        }

        parentLink->setHash(hasher->result().toHex());
        file.close();
    }

    emit complete();
}
