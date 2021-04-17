#define CATCH_CONFIG_MAIN
#include "Etudiant.h"
#include "catch.hpp"
#include <memory>

TEST_CASE("L'analyse de performance des eleves fonctionne correctement")
{
	unique_ptr<Etudiant> premierEtudiant = make_unique<Etudiant>("Stephane", 20);
	unique_ptr<Etudiant> deuxiemeEtudiant = make_unique<Etudiant>("Amir", 21);

	REQUIRE(premierEtudiant->AnalyserPerformance() == true);
	REQUIRE(deuxiemeEtudiant->AnalyserPerformance() == true);
}

TEST_CASE("Deux eleves font appel au meme objet Analyse pour l'analyse de performance")
{
	unique_ptr<Etudiant> premierEtudiant = make_unique<Etudiant>("Stephane", 20);
	unique_ptr<Etudiant> deuxiemeEtudiant = make_unique<Etudiant>("Amir", 21);

	REQUIRE(premierEtudiant->verifierSigleton() == deuxiemeEtudiant->verifierSigleton());
}


