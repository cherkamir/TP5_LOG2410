#pragma once
#ifndef ANALYSEETPARTITION_H_INCLUDED
#define ANALYSEETPARTITION_H_INCLUDED
#include <iostream>
#include <string>
#include "Etat.h"
#include "Application.h"

/**
 * Les états dits concrets implémente les comportements de l'application
 */

// Partition de musique à scanner et enregistrer
class Partition : public Etat
{
public:
    inline void action1() override;

    void action2() override
    {

        std::cout << "Le systeme va maintenant scanner la partition musicale prise en photo. Veuillez patienter... \t" << std::endl;

    }
};

// Analyse de la performance de l'élève ou de sa progression
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

void Partition::action1() {
    
     this->app_->transitionVers(new Analyse);
     std::cout << "Vous avez sélectionné << Analyser la partition musicale et ses note>> . Veuillez patienter...\t" << std::endl;

}
#endif