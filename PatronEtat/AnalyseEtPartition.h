#pragma once
#ifndef ANALYSEETPARTITION_H_INCLUDED
#define ANALYSEETPARTITION_H_INCLUDED
#include <iostream>
#include <string>
#include "Etat.h"
#include "Application.h"

/**
 * Les �tats dits concrets impl�mente les comportements de l'application
 */

// Partition de musique � scanner et enregistrer
class Partition : public Etat
{
public:
    inline std::string action1() override;

    // Scan de la partition musicale et retour d'une string indiquant que le scan est en cours
    std::string action2() override
    {

        return "Le systeme va maintenant scanner la partition musicale prise en photo. Veuillez patienter... \t\n";

    }
};

// Analyse de la performance de l'�l�ve ou de sa progression
class Analyse : public Etat
{
public:
    // L'analye de l'action1 est termin�, maintenant on veut charger une vouvelle partition
    // l'�tat courant chhange de Analyse � Partition
    std::string action2() override
    {

        std::string message = "L'analyse est termin�\n Vous avez selectionn� : << Charger une nouvelle partition >>.\n L'application va entrer en mode Partition.\n";
        this->app_->transitionVers(new Partition);
        return message;
    }

    // L'action s'occupe d'analyse la bande sonore d'une performance et retourne une string confirmant qu'elle a lieu
    std::string action1() override
    {

        return "L'analyse de la bande sonore de votre performance est en cours. Veuillez patienter...\t\n";
    }
};

/// @brief Transfert de responsabilit� de la Partition vers l'Analyse apr�s que l'on ai choisi d'en conduire
//         une de la partition musicale
/// @return string 
std::string Partition::action1() {
    
     this->app_->transitionVers(new Analyse);
     return "Vous avez s�lectionn� << Analyser la partition musicale et ses note>> . Veuillez patienter...\t\n";

}
#endif