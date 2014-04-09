#include "SceneHandler.h"
#include "BallDropScene.h"
#include "ThrowBallScene.h"
#include "BallCollisionScene.h"

Scene* SceneHandler::curScene = 0;
int SceneHandler::lastScene = -1;
sf::Text* SceneHandler::text = 0;
sf::Font* SceneHandler::font = 0;
float SceneHandler::time = 0.0f;

void SceneHandler::init()
{
	//luodaan fontti ja texti
	font = new sf::Font();
	text = new sf::Text();
	//ladataan fonttitiedosto
	if(!font->loadFromFile("font.ttf"))
	{
		std::cout << "Could not read font file!" << std::endl;
	}
	//asetetaan tekstille arvoja
	text->setFont(*font);
	text->setCharacterSize(24);
	text->setColor(sf::Color::White);
}

void SceneHandler::deinit()
{
	delete text;
	delete font;
}

void SceneHandler::update(double dt)
{
	//Skeneä vaihdetaan F nappeja painamalla, ja teksti vaihtuu skenejen mukana
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F1) && lastScene != 1) || lastScene == -1)
	{
		curScene = new BallDropScene();
		text->setString("Press key to change scene: [F1]  F2   F3          Pallon putoaminen"); 
		lastScene = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F2) && lastScene != 2)
	{
		curScene = new ThrowBallScene();
		text->setString("Press key to change scene:  F1  [F2]  F3          Pallon heitto"); 
		lastScene = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F3) && lastScene != 3)
	{
		curScene = new BallCollisionScene();
		text->setString("Press key to change scene:  F1   F2  [F3]         Pallon tormays"); 
		lastScene = 3;
	}
	//SPACE näppäin hidastaa aikaa
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		dt /= 10;
	const float timestep = 0.01f;
	time += dt;
	if (time >= timestep)
	{
		//pakotetaan sovellus pyörimään halutulla nopeudella
		time = 0.0f;
		curScene->Update(timestep);
	}
}

void SceneHandler::draw(sf::RenderWindow &window)
{
	//piirretään skene ruudulle
	curScene->Draw(window);
	//ja teksti
	window.draw(*text);
}

