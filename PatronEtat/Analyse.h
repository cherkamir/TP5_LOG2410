#pragma once
#ifndef ANALYSE_H_INCLUDED
#define ANALYSE_H_INLCUDED

#include "Etat.h"
#include "Partition.h"

class Analyse: public Etat
{
public:
    void action1() override {
        std::cout << "L'analyse de la bande sonore de votre performance est en cours. Veuillez patienter...\t" << std::endl;
    }

    void action2() override { 
        std::cout << "Le systeme est maintenant en train d'analyser la progression de l'eleve sélectionne. Veuillez patienter...\t" << std::endl;
        std::cout << "L'analyse est terminé\n Vous avez selectionné : << Charger une nouvelle partition >>.\n L'application va entrer en mode Partition.\n";
        this->app_->transitionVers(new Partition);
    }
};


#endif // !ANALYSE_H_INCLUDED
