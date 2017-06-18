#include "SFML/Graphics.hpp"
#include "Classes.h"
#include <iostream>

using namespace std;

int main()
{
	state newState = state(1);
	while (newState != state(4))
	{
		switch (newState)
		{
		case MENU:
		{
			sf::RenderWindow window(sf::VideoMode(1000, 1000), "GAME", sf::Style::Titlebar | sf::Style::Close);
			window.setFramerateLimit(60);
			window.setMouseCursorVisible(false);
			sf::Texture background;
			background.loadFromFile("images/grass.jpg");
			background.setRepeated(true);
			sf::Sprite sBackground(background);
			sBackground.setTextureRect({ 0, 0, 1000, 1000 });
			Menu menu(window.getSize().x, window.getSize().y);
			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						window.close();
						break;
					case sf::Event::KeyPressed:
						switch (event.key.code)
						{
						case sf::Keyboard::Up:
							menu.moveUp();
							break;
						case sf::Keyboard::Down:
							menu.moveDown();
							break;
						case sf::Keyboard::Return:
							switch (menu.getSelectedItemIndex())
							{
							case 0:
								newState = state(2);
								window.close();
								break;
							case 1:
								newState = state(3);
								window.close();
								break;
							case 2:
								newState = state(4);
								window.close();
								break;
							}
						}
					}
				}
				window.clear();
				window.draw(sBackground);
				menu.draw(window);
				window.display();
			}
			break;
		}
		case NEW_GAME:
		{
			sf::RenderWindow window(sf::VideoMode(1000, 1000), "GAME", sf::Style::Titlebar | sf::Style::Close);
			window.setFramerateLimit(60);
			window.setMouseCursorVisible(false);
			sf::Texture background;
			background.loadFromFile("images/grass.jpg");
			background.setRepeated(true);
			sf::Sprite sBackground(background);
			sBackground.setTextureRect({ 0, 0, 1000, 1000 });
			newGame game(window.getSize().x, window.getSize().y);
			game.run(window, sBackground, newState);
			break;
		}
		case LOAD_GAME:
		{
			sf::RenderWindow window(sf::VideoMode(1000, 1000), "GAME", sf::Style::Titlebar | sf::Style::Close);
			window.setFramerateLimit(60);
			window.setMouseCursorVisible(false);
			sf::Texture background;
			background.loadFromFile("images/grass.jpg");
			background.setRepeated(true);
			sf::Sprite sBackground(background);
			sBackground.setTextureRect({ 0, 0, 1000, 1000 });
			loadGame game(window.getSize().x, window.getSize().y);
			game.run(window, sBackground, newState);
			break;
		}
		}
	}
	return 0;
}