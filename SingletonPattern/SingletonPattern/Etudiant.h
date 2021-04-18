#include "Analyse.h"

class Etudiant
{
public:
	Etudiant (string nom, int age) :
		nom_(nom)
		, age_(age)
	{}

	bool AnalyserPerformance()
	{
		return Analyse::getInstance()->programmeAnalyse();
	}

	const Analyse* verifierSigleton()
	{
		return Analyse::getInstance()->adresseSingleton();
	}

private:
	string nom_;
	int age_;
};
