#ifndef BROWSER_H
#define BROWSER_H
#include <QDir> //����� QDir ������������ ������ � ���������� ��������� � �� �����������
#include <QFileInfo> //QFileInfo ������������� ���������� �� ����� ����� � ������� (����) � �������� �������, ��� ������ ������� � � ���,
                      // �������� �� �� ��������� ��� ������������� ������� � �.�.
#include <QTextStream>
#include <QDebug>

class IBrowser
{
public:
    virtual void browser(const QString& path) = 0;
    virtual ~IBrowser() {}
};

class Browser
{
private:
    IBrowser *b;
public:
    explicit Browser(IBrowser* l) : b(l) {}
    void browser(const QString& path)
    {
        b->browser(path);
    }
    void setStrategy(IBrowser* strategy) { b = strategy; }
};

#endif // BROWSER_H
