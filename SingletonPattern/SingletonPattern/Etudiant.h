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
		return Analyse::getInstance()->analyseDePerformance();
	}

	const Analyse* verifierSigleton()
	{
		return Analyse::getInstance()->verficiationSingleton();
	}

private:
	string nom_;
	int age_;
};
