#include <iostream>
#include <cstdlib>

#include "maincontroller.h"

using namespace std;

int main()
{
    cout << "Application started." << endl;
    //QCoreApplication a();

//    mainController.start();
    mainController *main = new mainController("mainController");

    main->start();
    main->stop();

    //return a.exec;
    return 1;
}
