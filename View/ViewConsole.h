#ifndef UNTITLED_VIEWCONSOLE_H
#define UNTITLED_VIEWCONSOLE_H

#include "../Controller/Controller.h"

using namespace std;

class ViewConsole
{
private:
    Controller controller;

    void dialog();
    void showData();
    void addData();
    void deleteData();
    void editData();

public:
    ViewConsole();
};


#endif //UNTITLED_VIEWCONSOLE_H
