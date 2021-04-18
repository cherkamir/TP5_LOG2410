#pragma once

#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "Etat.h"

/**
 * L'application définit l'Interface d'intérêt de l'utilisateur. Elle maintient éaglement
 * une référence à une instance d'un objet État qui représente l'état actuel de l'application
 */
class Application
{
public:
	explicit Application(Etat *etat) : etat_(nullptr) {
		this->transitionVers(etat);
	}
	 
	~Application() { delete etat_; }
	/**
	* L'application nous permet de changer l'objet état à l'exécution
	*/
	void transitionVers(Etat *etat) { 

		std::cout << "Application: Transition vers " /*<< typeid(*etat_).name()*/ << ".\n";
		if (etat_ != nullptr)
			delete etat_;
		etat_ = etat;
		etat_->setContexte(this);
		

	}

	/**
	* L'application délègue une partie de son comportement à son état actuel
	*/
	void analyserperformance()
	{
		this->etat_->action1();
	}
	void scannerPartition()
	{
		this->etat_->action2();
	}

private:
	Etat *etat_;
};


#endif // !APPLICATION_H_INCLUDED
