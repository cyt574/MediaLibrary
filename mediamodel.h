#ifndef MEDIAMODEL_H
#define MEDIAMODEL_H

#include <QObject>

class MediaModel : public QObject
{
    Q_OBJECT
public:
    explicit MediaModel(QObject *parent = nullptr);

signals:

public slots:

private:
    int mediaId;
    QString mediaName;
    int mediaImageId;
};

#endif // MEDIAMODEL_H
