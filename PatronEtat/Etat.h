#pragma once

#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED

#include <string>
#include <typeinfo>
#include <iostream>
#include <memory>

class Application;

/**
 * The base State class declares methods that all Concrete State should
 * implement and also provides a backreference to the Context object, associated
 * with the State. This backreference can be used by States to transition the
 * Context to another State.
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


