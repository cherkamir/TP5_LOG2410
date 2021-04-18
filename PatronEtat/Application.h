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

		std::cout << "Application: Transition vers " /*<< typeid(*etat_).name()*/ << ".\n";
		if (etat_ != nullptr)
			delete etat_;
		etat_ = etat;
		etat_->setContexte(this);
		

	}

	/**
	* L'application d�l�gue une partie de son comportement � son �tat actuel
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
