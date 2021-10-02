#include <iostream>

using namespace std;
#include "Factory.h"





#include "Application.h"
int main(int argc, char* argv[]) {
    Application app;

    app.init(argc, argv);
    return app.run();
}
