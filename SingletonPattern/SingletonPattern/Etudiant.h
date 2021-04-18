#include "Analyse.h"

class Etudiant
{
public:
	//Constructeur d'Etudiant
	Etudiant (string nom, int age) :
		nom_(nom)
		, age_(age)
	{}
	
	/*
	Methode qui appelle la methode ProgrammeAnalyse() de Analyse
	pour analyser la performance jouee par l'etudiant
	*/
	bool AnalyserPerformance()
	{
		return Analyse::getInstance()->programmeAnalyse();
	}
	/*
	Cette methode va nous servir dans les tests untiaires, verifier
	que chaque instance d'etudiant utilise la meme classe Analyse pour
	analyser la performance.
	*/
	const Analyse* verifierSigleton()
	{
		return Analyse::getInstance()->adresseSingleton();
	}

private:
	string nom_;
	int age_;
};
