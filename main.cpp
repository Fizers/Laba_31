#include <iostream>
#include "Browser.h"
#include "GroupFolder.h"
#include "GroupType.h"

int main()
{
    IBrowser* sf = new GroupFolder();
    IBrowser* st = new GroupType();
    Browser* b = new Browser(sf);
    b->browser("C:/Games");
    b->setStrategy(st);
    b->browser("C:/Games");
    delete sf;
    delete st;
    delete b;
}
