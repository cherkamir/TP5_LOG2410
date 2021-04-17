#pragma once

#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED

#include <string>
#include <typeinfo>
#include <iostream>
#include <memory>

class Application;
class Etat
{
public:
	Etat() = default;
	virtual ~Etat() {

	}

	void setContexte(Application *app) {
		appli_ = app;
	}

	virtual void action1() = 0;
	virtual void action2() = 0;
protected:
	Application *appli_;
};


#endif // !ETAT_H_INCLUDED


