#define CATCH_CONFIG_MAIN  //  This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Application.h"
#include "Etat.h"
#include "AnalyseEtPartition.h"

using namespace std;


void Client()
{
    Application* app = new Application(new Analyse);
    app->analyserperformance();
    app->scannerPartition();
    delete app;
}

