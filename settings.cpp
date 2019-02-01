#include "settings.h"
#define SETTING_PATH_DEFAULT "D:\\MediaLibrary.ini"
#define SETTING_PATH_DEFAULT "E:\\MediaLibrary.ini"



MediaSetting::MediaSetting(QObject *parent) : QObject(parent), currentPath(), settingPath()
{
    load();
}

MediaSetting::~MediaSetting()
{
    delete settingPath;
}


void MediaSetting::load()
{
    if(QFile::exists(SETTING_PATH_DEFAULT))
    {
        settingPath = new QSettings(SETTING_PATH_DEFAULT, QSettings::IniFormat);
        currentPath = settingPath->value("PATH/SETTING_PATH").toString();
        qDebug()<< "#######################" << currentPath << "########################" ;
    }
    else
    {

        qDebug()<< "#######################" << "Not at all."<< "########################" ;
    }
}

void MediaSetting::save()
{
   // currentPath = QDir::currentPath();

}

QString MediaSetting::getCurrentPath() const
{
    return currentPath;
}

void MediaSetting::setCurrentPath(const QString &value)
{
    currentPath = value;
}
