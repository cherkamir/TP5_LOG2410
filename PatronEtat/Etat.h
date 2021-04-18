#pragma once

#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED

#include <string>
#include <typeinfo>
#include <iostream>
#include <memory>

class Application;

/**
 * La classe de base Etat d�clare des m�thodes virtuelles pures que toutes 
 * ses classes d�riv�es doivent impl�menter et procure aussi une backreference
 * vers l'objet Application. Cette backreference peut �tre utilis�e par les diff�rents
 * �tats pour transitionner de l'�tat courant de l'application vers un autre �tat 
 */
class Etat
{
public:
	explicit Etat() : app_(nullptr) {}
	virtual ~Etat() {

	}

	void setContexte(Application *app) {
		app_ = app;
	}

	virtual void action1() = 0;
	virtual void action2() = 0;
protected:
	Application *app_;
};


#endif // !ETAT_H_INCLUDED


