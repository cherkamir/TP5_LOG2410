#include <iostream>
using namespace std;

class Analyse
{
public:

	static Analyse* getInstance()
	{
		if (instance_ == nullptr)
		{
			instance_ = new Analyse();
		}
		return instance_;
	}

	bool programmeAnalyse()
	{
		cout << "L'analyse est en cours... \nAnalyse terminee." << endl;
		return true;
	}

	const Analyse* adresseSingleton()
	{
		return instance_;
	}

	~Analyse() {
		delete instance_;
		instance_ = nullptr;
	}

private:

	static Analyse* instance_;
	Analyse() = default;
};

Analyse* Analyse::instance_ = nullptr;




