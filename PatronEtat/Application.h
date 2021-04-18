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

		
		if (etat_ != nullptr)
			delete etat_;
		etat_ = etat;
		etat_->setContexte(this);
		

	}

	/**
	* L'application délègue une partie de son comportement à son état actuel
	*/

	// Requete1 de l'utilisateur qui est censé lancer l'analyse de performance
	std::string Requete1()
	{
		return this->etat_->action1();
	}
	// Requete2 de l'utilisateur qui est censé lancer le chargement d'une partition
	std::string  Requete2()
	{
		return this->etat_->action2();
	}

	// Retourne l'état actuel de l'application
	Etat& getEtat() const {
		return *etat_;
	}
private:
	Etat *etat_;
};


#endif // !APPLICATION_H_INCLUDED
