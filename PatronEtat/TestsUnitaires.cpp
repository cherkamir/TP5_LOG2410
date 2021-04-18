#define CATCH_CONFIG_MAIN  //  This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Application.h"
#include "Etat.h"
#include "AnalyseEtPartition.h"

using namespace std;


Etat& Client()
{
    Application *app;
    char requete;
    cout << "Entrez l'etat initial.\t(a)Analyse ou (b)Partition." << endl;
    cin >> requete;
    switch (requete)
    {
    case 'a':
        app = new Application(new Analyse);
        cout <<app->getEtat().action2() << endl;
        return app->getEtat();
        delete app;
        break;
    case 'b':
        app = new Application(new Partition);
        cout <<app->getEtat().action1() << endl;
        return app->getEtat();
        delete app;
        break;
    }
}


TEST_CASE("L'action1 de l'état Analyse exécute bien l'analyse de la performance")
{
    Application *app = new Application(new Analyse);
    Etat& etatActuel = app->getEtat();
    //cout << etatActuel.action1() << endl;
    REQUIRE(etatActuel.action1() == "L'analyse de la bande sonore de votre performance est en cours. Veuillez patienter...\t\n");
    delete app;
}

TEST_CASE("L'action2 de l'état Partition exécute bien le scan de la partition prise en photo")
{
    Application *app = new Application(new Partition);
    Etat& etatActuel = app->getEtat();
    cout << etatActuel.action2() << endl;
    REQUIRE(etatActuel.action2() == "Le systeme va maintenant scanner la partition musicale prise en photo. Veuillez patienter... \t\n");
    delete app;
}

TEST_CASE("L'exécution de l'action2 par l'Analyse change l'état courant en Partition")
{
    Application *app = new Application(new Partition);
    Etat& typeEtatCourant = Client();
    REQUIRE(typeid(typeEtatCourant).name() == typeid(Partition).name());
}

TEST_CASE("L'exécution de l'action1 par Partition change l'état courant en Analyse")
{
    Application* app = new Application(new Analyse);
    Etat& typeEtatCourant = Client();
    REQUIRE(typeid(typeEtatCourant).name() == typeid(Analyse).name());
}