#define CATCH_CONFIG_MAIN  //  This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Application.h"
#include "Etat.h"
#include "AnalyseEtPartition.h"

using namespace std;


void Client()
{
    Application* app = new Application(new Analyse);
    app->Requete1();
    app->Requete2();
    delete app;
}


TEST_CASE("La Requete1 exécute bien l'analyse de la performance")
{

}