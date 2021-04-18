#pragma once
#ifndef ANALYSE_H_INCLUDED
#define ANALYSE_H_INLCUDED

#include "Etat.h"
#include "Partition.h"
#include "Application.h"

class Analyse: public Etat
{
public:
    void action2() override {
        
        std::cout << "L'analyse est terminé\n Vous avez selectionné : << Charger une nouvelle partition >>.\n L'application va entrer en mode Partition.\n";
        this->app_->transitionVers(new Partition);
    }

    void action1() override { 
        
        std::cout << "L'analyse de la bande sonore de votre performance est en cours. Veuillez patienter...\t" << std::endl;
        std::cout << "L'analyse est terminé\n Vous avez selectionné : << Charger une nouvelle partition >>.\n L'application va entrer en mode Partition.\n";
        
    }
};


#endif // !ANALYSE_H_INCLUDED
