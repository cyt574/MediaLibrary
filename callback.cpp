#include "callback.h"


QStringList findFiles(const QString &startPath, QStringList filter)
{
    QStringList names;
    QDir dir(startPath);
    foreach(QString file, dir.entryList(filter, QDir::Files))
    {
        names += startPath + "\\" + file;
    }
    foreach(QString file, dir.entryList(filter, QDir::AllDirs | QDir::NoDotAndDotDot))
    {
        names += findFiles(startPath + "\\" + file, filter);
    }
    return names;
}
