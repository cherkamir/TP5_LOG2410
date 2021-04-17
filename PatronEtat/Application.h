#pragma once

#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "Etat.h"

/**
 * The Context defines the interface of interest to clients. It also maintains a
 * reference to an instance of a State subclass, which represents the current
 * state of the Context.
 */
class Application
{
public:
	explicit Application() : etat_(nullptr) {
		this->transitionVers(etat_);
	}
	 
	/**
	* The Context allows changing the State object at runtime.
	*/
	void transitionVers(Etat *etat) { 
		std::cout << "Application: Transition vers " << typeid(*etat_).name() << ".\n";
		if (etat_ != nullptr)
			delete etat_;
		etat_ = etat;
		etat_->setContexte(this);
	}

	/**
	* The Context delegates part of its behavior to the current State object.
	*/
	void Requete1()
	{
		this->etat_->action1();
	}
	void Requete2()
	{
		this->etat_->action2();
	}

private:
	Etat *etat_;
};


#endif // !APPLICATION_H_INCLUDED
