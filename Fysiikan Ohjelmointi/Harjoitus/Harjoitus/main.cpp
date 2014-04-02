#include <iostream>
#include <SFML/Graphics.hpp>

#include "SceneHandler.h"

using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(1200,720), "Hello World!");
	SceneHandler::init();
	Scene::windowSize = window.getSize();
	cout << "Debug works!" << endl;
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			switch (event.type)
			{
			//window closed
			case sf::Event::Closed:
				window.close();
				break;

			//Shut down window by pressing escape
			case sf::Event::KeyPressed:
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
				break;

			case sf::Event::GainedFocus:
				cout << "Gained focus." << endl;
				break;

			case sf::Event::LostFocus:
				cout << "Lost focus." << endl;
				break;

			case sf::Event::Resized:
				cout << "New width: "<< event.size.width << endl;
				cout << "New heigth: "<< event.size.height << endl;
				break;

			case sf::Event::TextEntered:
				if (event.text.unicode < 128)
					cout << "Letter: " << static_cast<char>(event.text.unicode) << endl;
				break;

			default:

				break;

			}
		}
			sf::Time t = clock.restart();
			SceneHandler::update(t.asSeconds());

			window.clear();
			SceneHandler::draw(window);
			window.display();
	}
	SceneHandler::deinit();

	return 0;
}
