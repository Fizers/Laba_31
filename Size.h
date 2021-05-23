#ifndef SIZE_H
#define SIZE_H
#include <QDir>
#include <QFileInfo>
#include <QTextStream>

namespace Total
{
    inline qint64 getAllSize(const QString& path)
    {
        qint64 AllSize = 0;
        QDir myDir(path);
        for (const auto& s : myDir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot
                                                | QDir::Hidden, QDir::Name | QDir::Type | QDir::Size))
                if (s.isDir() && !s.isSymLink())
                {
                    AllSize += getAllSize(s.absoluteFilePath());
                }
                else AllSize += s.size();
        return AllSize;
    }
    inline qint64 GiveSize(const QMap<QString, qint64> Sizes)
    {
        qint64 AllSize = 0;
        foreach(qint64 size, Sizes.values())
            AllSize += size;
        return AllSize;
    }
}
#endif // SIZE_H
