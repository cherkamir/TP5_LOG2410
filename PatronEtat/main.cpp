#define CATCH_CONFIG_MAIN  //  This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "Etat.h"
#include "Application.h"
#include <iostream>

using namespace std;

class Partition : public Etat
{
public:
    void action1() override;

    void action2() override
    {

        std::cout << "Le systeme va maintenant scanner la partition musicale prise en photo. Veuillez patienter... \t" << std::endl;

    }
};


class Analyse : public Etat
{
public:
    void action2() override
    {

        std::cout << "L'analyse est terminé\n Vous avez selectionné : << Charger une nouvelle partition >>.\n L'application va entrer en mode Partition.\n";
        this->app_->transitionVers(new Partition);
    }

    void action1() override
    {

        std::cout << "L'analyse de la bande sonore de votre performance est en cours. Veuillez patienter...\t" << std::endl;
        std::cout << "L'analyse est terminé\n Vous avez selectionné : << Charger une nouvelle partition >>.\n L'application va entrer en mode Partition.\n";
        this->app_->transitionVers(new Partition);
    }
};

void Partition::action1() 
{
    this->app_->transitionVers(new Analyse);
    std::cout << "Vous avez sélectionné << Analyser la partition musicale et ses note>> . Veuillez patienter...\t" << std::endl;

}

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