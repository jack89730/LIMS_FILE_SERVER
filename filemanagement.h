#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <QObject>
#include <QList>
#include <QDir>
#include <QFileInfoList>
#include <QTcpSocket>


/**
 * @brief The FileManagement class
 * 管理当前工作目录的文件
 * 记录当前实验所需的文件列表
 */

class FileManagement : public QObject
{
    Q_OBJECT
public:
    static FileManagement* getInstance();
    QString getWorkDirectory();
    void setWorkDirectory(QString dir);
    void setSocket(int descriptionId);

private:
    static FileManagement *fileManagement;
    explicit FileManagement(QObject *parent = 0);
    QString workDir;
    QList<QString> currentFileList;

    QFileInfoList fileList;
    QFileInfoList getFileList(QString path);
    QString projectName;

signals:
    void workDirUpdated();

public slots:
};

#endif // FILEMANAGEMENT_H
