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


TEST_CASE("L'action1 exécute bien l'analyse de la performance")
{
    Application* app = new Application(new Analyse);
    Etat& etatActuel = app->getEtat();
    //cout << etatActuel.action1() << endl;
    REQUIRE(etatActuel.action1() == "L'analyse de la bande sonore de votre performance est en cours. Veuillez patienter...\t\n");
}

TEST_CASE("L'action2 exécute bien le scan de la partition prise en photo")
{
    Application* app = new Application(new Partition);
    Etat& etatActuel = app->getEtat();
    cout << etatActuel.action2() << endl;
    REQUIRE(etatActuel.action2() == "Le systeme va maintenant scanner la partition musicale prise en photo. Veuillez patienter... \t\n");
}