#pragma once

#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED

#include <string>
#include <typeinfo>
#include <iostream>
#include <memory>

class Application;

/**
 * La classe de base Etat déclare des méthodes virtuelles pures que toutes 
 * ses classes dérivées doivent implémenter et procure aussi une backreference
 * vers l'objet Application. Cette backreference peut être utilisée par les différents
 * états pour transitionner de l'état courant de l'application vers un autre état 
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


