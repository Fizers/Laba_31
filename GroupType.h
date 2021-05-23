#ifndef GROUPTYPE_H
#define GROUPTYPE_H
#include "Browser.h"

class GroupType : public IBrowser
{
public:
    explicit GroupType() = default;
    virtual ~GroupType() = default;
    void browser(const QString& path);
private:
    void getTypeSize(const QString& path, QMap<QString, qint64>& TypeList);
    QMap<QString, double> getTypePercent(qint64& totalSize, QMap<QString, qint64>& TypeList) const;
    QList<QPair<double, QString>> sortPercent(const QMap<QString, double>& TypePercant);
    void PrintTypeAllInf(const QMap<QString, qint64>& FileTypesList, const QList<QPair<double, QString>> TypePercant) const;
};

#endif // GROUPTYPE_H
