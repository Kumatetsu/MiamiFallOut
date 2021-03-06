// MiamiFallOut.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Scene.hh"
#include <SFML/Graphics.hpp>
#include "EntityFactory.hh"
#include "TimeManager.hh"
#include "CircleEntity.hh"

// dev
#include <thread>
#include <chrono>

int main()
{
	// Création d'une window, j'aurais bien fais ca dans Scene,
	// mais si j'ai besoin d'un pointeur ayant une durée de vie globale
	sf::RenderWindow window(sf::VideoMode(1100, 700), "Miami Fall Out !");

	// factory pur les entités de bases
	EntityFactory* factory = new EntityFactory();
	// Le timer
	TimeManager& tm = TimeManager::GetInstance();
	// La scene porte la window et observe les entitées
	Scene* scene = new Scene(&window);
	// Un CircleEntity est une entité de base (AbstractEntity et ShapeEntity)
	CircleEntity* circle = dynamic_cast<CircleEntity*>(factory->Create("CircleEntity"));
	circle->SetCircle(100.f, 30, sf::Color::Cyan);
	// la scene observe le cerlce
	circle->AddObserver(scene);

	// la scene possède l'entité Circle comme une AbstractEntity
	scene->AddEntity(circle);

	// on start la boucle
	tm.Start();
	// début d'utilisation des constantes clavier
	std::cout << "\nKeyboard input constants: " << VK_BACK;
	// désormais on récupère la window avec un GetWindow
	while (scene->GetWindow()->isOpen())
	{
		// Boucle de jeu avec frames réglées sur 60...
		// Tout se fait au travers du pattern observer,
		// changer x ou y déclenche l'update de la scene
		// elle reconstruit son background et redessine
		// le cercle...
		tm.Update();
		unsigned int elapsedTime = tm.GetStartedTime();
		if (elapsedTime > 60) {
			tm.Start();
			circle->SetX(circle->GetX() + 1);
			circle->SetY(circle->GetY() + 1);
			circle->SetCoordonates();
			std::cout << "\nFPS: " << elapsedTime;
		}
	}
	
	return 0;
}
