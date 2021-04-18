#include <iostream>
using namespace std;

class Analyse
{
public:
	/*
	getInstance() va nous assurer d'avoir une seule instance de la meme classe.
	*/
	static Analyse* getInstance()
	{
		if (instance_ == nullptr)
		{
			instance_ = new Analyse();
		}
		return instance_;
	}
	/*
	Cette methode va simplement nous permettre de verifier que les eleves instancies
	par la classe Etudiant ont bien acces a la methode programmeAnalyse de Analyse.
	*/
	bool programmeAnalyse()
	{
		cout << "L'analyse est en cours... \nAnalyse terminee." << endl;
		return true;
	}
	
	/*
	Cette methode va nous renvoyer l'adresse de l'instance de la classe Analyse
	On pourra s'en servir pour verifier que chaque methode utilise la methode d'analyse 
	de performance de la meme classe.
	*/
	const Analyse* adresseSingleton()
	{
		return instance_;
	}
	// Destructeur de Analyse.
	~Analyse() {
		delete instance_;
		instance_ = nullptr;
	}

private:
	/* Nous mettons l'attribut instance_ et le constructeur de Analyse en private
	pour creer une classe Singleton
	*/
	static Analyse* instance_;
	Analyse() = default;
};

Analyse* Analyse::instance_ = nullptr;




