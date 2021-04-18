#define CATCH_CONFIG_MAIN  //  This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "Etat.h"
#include "Application.h"
#include "Partition.h"
#include "Analyse.h"
#include <iostream>

using namespace std;


void Client()
{
    Application *app = new Application(new Analyse);
    app->analyserperformance();
    app->scannerPartition();
    delete app;
}

int main()
{
    Client();
    return 0;
}