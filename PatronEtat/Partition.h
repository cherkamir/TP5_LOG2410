#pragma once
#ifndef PARTITION_H_INCLUDED
#define PARTITION_H_INCLUDED

#include <string>
#include <iostream>
#include "Etat.h"
#include "Application.h"


class Analyse;
class Partition: public Etat
{
public:
    void action1() override
    {
        this->app_->transitionVers(new Analyse);
        std::cout << "Vous avez sélectionné << Analyser la partition musicale et ses note>> . Veuillez patienter...\t" << std::endl;
        
    }

    void action2() override
    {
       
        std::cout << "Le systeme va maintenant scanner la partition musicale prise en photo. Veuillez patienter... \t" << std::endl;
        
    }
};
#endif // !PARTITION_H_INCLUDED

