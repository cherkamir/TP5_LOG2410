#pragma once

#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "Etat.h"

/**
 * L'application d�finit l'Interface d'int�r�t de l'utilisateur. Elle maintient �aglement
 * une r�f�rence � une instance d'un objet �tat qui repr�sente l'�tat actuel de l'application
 */
class Application
{
public:
	explicit Application(Etat *etat) : etat_(nullptr) {
		this->transitionVers(etat);
	}
	 
	~Application() { delete etat_; }
	/**
	* L'application nous permet de changer l'objet �tat � l'ex�cution
	*/
	void transitionVers(Etat *etat) { 

		
		if (etat_ != nullptr)
			delete etat_;
		etat_ = etat;
		etat_->setContexte(this);
		

	}

	/**
	* L'application d�l�gue une partie de son comportement � son �tat actuel
	*/

	// Requete1 de l'utilisateur qui est cens� lancer l'analyse de performance
	std::string Requete1()
	{
		return this->etat_->action1();
	}
	// Requete2 de l'utilisateur qui est cens� lancer le chargement d'une partition
	std::string  Requete2()
	{
		return this->etat_->action2();
	}

	// Retourne l'�tat actuel de l'application
	Etat& getEtat() const {
		return *etat_;
	}
private:
	Etat *etat_;
};


#endif // !APPLICATION_H_INCLUDED
