#ifndef SETTING_H
#define SETTING_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QDebug>

class MediaSetting : public QObject
{
    Q_OBJECT
public:
    explicit MediaSetting(QObject *parent = nullptr);
    MediaSetting();
    ~MediaSetting();
    void load();
    void save();

    QString getCurrentPath() const;
    void setCurrentPath(const QString &value);

signals:

public slots:

private:
    QString currentPath;
    QSettings *settingPath;
};

#endif // SETTING_H
