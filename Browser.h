#ifndef BROWSER_H
#define BROWSER_H
#include <QDir> //Класс QDir обеспечивает доступ к структурам каталогов и их содержимому
#include <QFileInfo> //QFileInfo предоставляет информацию об имени файла и позиции (пути) в файловой системе, его правах доступа и о том,
                      // является ли он каталогом или символической ссылкой и т.д.
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
