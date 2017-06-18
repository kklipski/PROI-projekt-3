#include "Classes.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::attack(Entity *a, int x, int y, int isTooClose)
{

}

bool Entity::move(float a, float b)
{
	if ((fabs(a - x*50) <= (maxDistance * 50)) && (fabs(b - y*50) <= (maxDistance * 50))) return true;
	else return false;
}

Archer::Archer(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
	player = a;
	id = i;
	if (player == 1) entityTexture.loadFromFile("images/archer1.png");
	else entityTexture.loadFromFile("images/archer2.png");
	entitySprite.setTexture(entityTexture);
	squadAmount = b;
	unitHealth = c;
	squadHealth = d;
	powerOfAttack = e;
	maxDistance = f;
	x = g;
	y = h;
	attackDistance = j;
	entitySprite.setPosition(x*50, y*50);
}

Archer::~Archer()
{

}

void Archer::attack(Entity *a, int x, int y, int isTooClose)
{
	a->squadHealth = (a->squadHealth) - (squadAmount*powerOfAttack);
	int isDead = (a->squadHealth) % (a->unitHealth);
	a->squadAmount = (a->squadHealth) / (a->unitHealth);
	if (isDead > 0) (a->squadAmount) = (a->squadAmount) + 1;
}

Knight::Knight(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
	player = a;
	id = i;
	if (player == 1) entityTexture.loadFromFile("images/knight1.png");
	else entityTexture.loadFromFile("images/knight2.png");
	entitySprite.setTexture(entityTexture);
	squadAmount = b;
	unitHealth = c;
	squadHealth = d;
	powerOfAttack = e;
	maxDistance = f;
	x = g;
	y = h;
	attackDistance = j;
	entitySprite.setPosition(x * 50, y * 50);
}

Knight::~Knight()
{

}

void Knight::attack(Entity *a, int x, int y, int isTooClose)
{
	a->squadHealth = (a->squadHealth) - (squadAmount*powerOfAttack);
	int isDead = (a->squadHealth) % (a->unitHealth);
	a->squadAmount = (a->squadHealth) / (a->unitHealth);
	if (isDead > 0) (a->squadAmount) = (a->squadAmount) + 1;
}

Rider::Rider(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
	player = a;
	id = i;
	if (player == 1) entityTexture.loadFromFile("images/rider1.png");
	else entityTexture.loadFromFile("images/rider2.png");
	entitySprite.setTexture(entityTexture);
	squadAmount = b;
	unitHealth = c;
	squadHealth = d;
	powerOfAttack = e;
	maxDistance = f;
	x = g;
	y = h;
	attackDistance = j;
	entitySprite.setPosition(x * 50, y * 50);
}

Rider::~Rider()
{

}

void Rider::attack(Entity *a, int x, int y, int isTooClose)
{   
	int attackTemp = powerOfAttack;
	if ((x <= 5) && (y <= 5)) powerOfAttack = powerOfAttack;
	else if ((x <= 10) && (y <= 10)) powerOfAttack = powerOfAttack + 5;
	else if ((x <= 15) && (y <= 15)) powerOfAttack = powerOfAttack + 10;
	else powerOfAttack = powerOfAttack + 15;
	a->squadHealth = (a->squadHealth) - (squadAmount*powerOfAttack);
	int isDead = (a->squadHealth) % (a->unitHealth);
	a->squadAmount = (a->squadHealth) / (a->unitHealth);
	if (isDead > 0) (a->squadAmount) = (a->squadAmount) + 1;
	powerOfAttack = attackTemp;
}

Warrior::Warrior(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
	player = a;
	id = i;
	if (player == 1) entityTexture.loadFromFile("images/warrior1.png");
	else entityTexture.loadFromFile("images/warrior2.png");
	entitySprite.setTexture(entityTexture);
	squadAmount = b;
	unitHealth = c;
	squadHealth = d;
	powerOfAttack = e;
	maxDistance = f;
	x = g;
	y = h;
	attackDistance = j;
	entitySprite.setPosition(x * 50, y * 50);
}

Warrior::~Warrior()
{

}

void Warrior::attack(Entity *a, int x, int y, int isTooClose)
{
	a->squadHealth = (a->squadHealth) - (squadAmount*powerOfAttack);
	int isDead = (a->squadHealth) % (a->unitHealth);
	a->squadAmount = (a->squadHealth) / (a->unitHealth);
	if (isDead > 0) (a->squadAmount) = (a->squadAmount) + 1;
}

Wizard::Wizard(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
	player = a;
	id = i;
	if (player == 1) entityTexture.loadFromFile("images/wizard1.png");
	else entityTexture.loadFromFile("images/wizard2.png");
	entitySprite.setTexture(entityTexture);
	squadAmount = b;
	unitHealth = c;
	squadHealth = d;
	powerOfAttack = e;
	maxDistance = f;
	x = g;
	y = h;
	attackDistance = j;
	entitySprite.setPosition(x * 50, y * 50);
}

Wizard::~Wizard()
{

}

void Wizard::attack(Entity *a, int x, int y, int isTooClose)
{
	if (!isTooClose)
	{
		a->squadHealth = (a->squadHealth) - (squadAmount*powerOfAttack);
		int isDead = (a->squadHealth) % (a->unitHealth);
		a->squadAmount = (a->squadHealth) / (a->unitHealth);
		if (isDead > 0) (a->squadAmount) = (a->squadAmount) + 1;
	}
}

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("medievalFont.otf"))
	{
		return;
	}

	menu[0].setFont(font);
	menu[0].setCharacterSize(100);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setOutlineColor(sf::Color::Black);
	menu[0].setStyle(sf::Text::Bold);
	menu[0].setString("New game");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2.0f, menu[0].getLocalBounds().height / 2.0f);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setCharacterSize(100);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setOutlineColor(sf::Color::Black);
	menu[1].setStyle(sf::Text::Bold);
	menu[1].setString("Load game");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2.0f, menu[1].getLocalBounds().height / 2.0f);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setCharacterSize(100);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setOutlineColor(sf::Color::Black);
	menu[2].setStyle(sf::Text::Bold);
	menu[2].setString("Exit");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2.0f, menu[2].getLocalBounds().height / 2.0f);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (NUMBER_OF_ITEMS + 1) * 3));
}
Menu::~Menu()
{

}
void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::moveUp()
{
	if (((NUMBER_OF_ITEMS - 1) <= (selectedItemIndex + 1)) && ((selectedItemIndex + 1) <= NUMBER_OF_ITEMS))
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (((NUMBER_OF_ITEMS - 2) <= (selectedItemIndex + 1)) && ((selectedItemIndex + 1) <= (NUMBER_OF_ITEMS - 1)))
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

int Menu::getSelectedItemIndex()
{
	return selectedItemIndex;
}

newGame::newGame(float width, float height)
{
	backlight.loadFromFile("images/backlight.png");
	sBacklight.setTexture(backlight);
	sBacklight.setPosition(-100, -100);
	try
	{
		ifstream data("newGame.txt");
		if (data.is_open())
		{
			int a, b, c, d, e, f, g, h, i, j;
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Archer * archer1_1 = new Archer(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(archer1_1);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Archer * archer1_2 = new Archer(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(archer1_2);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Archer * archer1_3 = new Archer(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(archer1_3);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Knight * knight1_1 = new Knight(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(knight1_1);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Knight * knight1_2 = new Knight(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(knight1_2);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Rider * rider1 = new Rider(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(rider1);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Warrior * warrior1_1 = new Warrior(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(warrior1_1);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Warrior * warrior1_2 = new Warrior(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(warrior1_2);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Warrior * warrior1_3 = new Warrior(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(warrior1_3);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Wizard * wizard1 = new Wizard(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(wizard1);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Archer * archer2_1 = new Archer(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(archer2_1);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Archer * archer2_2 = new Archer(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(archer2_2);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Archer * archer2_3 = new Archer(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(archer2_3);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Knight * knight2_1 = new Knight(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(knight2_1);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Knight * knight2_2 = new Knight(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(knight2_2);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Rider * rider2 = new Rider(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(rider2);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Warrior * warrior2_1 = new Warrior(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(warrior2_1);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Warrior * warrior2_2 = new Warrior(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(warrior2_2);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Warrior * warrior2_3 = new Warrior(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(warrior2_3);
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			Wizard * wizard2 = new Wizard(a, b, c, d, e, f, g, h, i, j);
			entities.push_back(wizard2);
		}
		else throw 1;
		data.close();
	}
	catch (int e)
	{
		cout<< "An exception occurred. Exception Nr. " << e << '\n';
	}
}

newGame::~newGame()
{

}

void newGame::moveUp()
{
	if (((sBacklight.getPosition().x) == -100) && ((sBacklight.getPosition().y) == -100))
	{
		sBacklight.setPosition(0, 0);
	}
	if ((sBacklight.getPosition().y) != 0) sBacklight.setPosition(sBacklight.getPosition().x, sBacklight.getPosition().y - 50);
}

void newGame::moveDown()
{
	if (((sBacklight.getPosition().x) == -100) && ((sBacklight.getPosition().y) == -100))
	{
		sBacklight.setPosition(0, 0);
	}
	if ((sBacklight.getPosition().y) != 950) sBacklight.setPosition(sBacklight.getPosition().x, sBacklight.getPosition().y + 50);
}

void newGame::moveLeft()
{
	if (((sBacklight.getPosition().x) == -100) && ((sBacklight.getPosition().y) == -100))
	{
		sBacklight.setPosition(0, 0);
	}
	if ((sBacklight.getPosition().x) != 0) sBacklight.setPosition(sBacklight.getPosition().x - 50, sBacklight.getPosition().y);
}

void newGame::moveRight()
{
	if (((sBacklight.getPosition().x) == -100) && ((sBacklight.getPosition().y) == -100))
	{
		sBacklight.setPosition(0, 0);
	}
	if ((sBacklight.getPosition().x) != 950) sBacklight.setPosition(sBacklight.getPosition().x + 50, sBacklight.getPosition().y);
}

void newGame::run(sf::RenderWindow &window, sf::Sprite &sprite, state &newState)
{
	while (window.isOpen())
	{
		processEvents(window, newState);
		update();
		render(window, sprite);
	}
}

void newGame::processEvents(sf::RenderWindow &window, state &newState)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			newState = state(4);
			window.close();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
			{
				newState = state(1);
				window.close();
				break;
			}
			case sf::Keyboard::F1:
			{
				try
				{
					fstream data;
					data.open("savedGame.txt", ios::out | ios::trunc);
					if (data.is_open())
					{
						int check = 1, repair = 0;
						for (auto k : entities)
						{
							if ((k->id) != check)
							{
								repair = (k->id) - check;
								for (repair; repair > 0; repair--)
								{
									data << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << endl;
									check++;
								}
								data << k->player << " " << k->squadAmount << " " << k->unitHealth << " " << k->squadHealth << " " << k->powerOfAttack << " " << k->maxDistance << " " << k->x << " " << k->y << " " << k->id << " " << k->attackDistance << endl;
							}
							else
							{
								data << k->player << " " << k->squadAmount << " " << k->unitHealth << " " << k->squadHealth << " " << k->powerOfAttack << " " << k->maxDistance << " " << k->x << " " << k->y << " " << k->id << " " << k->attackDistance << endl;
								check++;
							}
						}
						if (((entities.back())->id) != 20)
						{
							repair = 20 - ((entities.back())->id);
							for (repair; repair > 0; repair--)
							{
								data << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << endl;
							}
						}
						data << move;
						data.close();
						break;
					}
					else throw 3;
				}
				catch (int e)
				{
					cout << "An exception occurred. Exception Nr. " << e << '\n';
				}
			}
			case sf::Keyboard::Up:
			{
				moveUp();
				break;
			}
			case sf::Keyboard::Down:
			{
				moveDown();
				break;
			}
			case sf::Keyboard::Left:
			{
				moveLeft();
				break;
			}
			case sf::Keyboard::Right:
			{
				moveRight();
				break;
			}
			case sf::Keyboard::Return:
			{
				if (chooseSquad == 1)
				{
					for (auto k : entities)
					{
						if ((sBacklight.getPosition().x == k->x * 50) && (sBacklight.getPosition().y == k->y * 50) && (k->player == move))
						{
							sBacklight.setPosition(-100, -100);
							chooseSquad = 0;
							moveSquad = 1;
							theChosenOne = k;
							break;
						}
					}
				}
				else if (moveSquad == 1)
				{
					int isCollide = 0;
					for (auto k : entities)
					{
						if ((k->x * 50 == sBacklight.getPosition().x) && (k->y * 50 == sBacklight.getPosition().y))
						{
							isCollide = 1;
							break;
						}
					}
					if (isCollide) break;
					else
					{
						if (theChosenOne->move(sBacklight.getPosition().x, sBacklight.getPosition().y))
						{
							for (auto k : entities)
							{
								if ((k->id) == theChosenOne->id)
								{
									dx = fabs(k->x * 50 - sBacklight.getPosition().x) / 50;
									dy = fabs(k->y * 50 - sBacklight.getPosition().y) / 50;
									k->x = sBacklight.getPosition().x / 50;
									k->y = sBacklight.getPosition().y / 50;
									theChosenOne = k;
									break;
								}
							}
							sBacklight.setPosition(-100, -100);
							moveSquad = 0;
							attackEnemy = 1;
							int isAttackPossible = 0;
							for (auto k : entities)
							{
								if ((k->player != theChosenOne->player) && ((fabs((theChosenOne->x) - (k->x)) <= theChosenOne->attackDistance) && (fabs((theChosenOne->y) - (k->y)) <= theChosenOne->attackDistance))) isAttackPossible = 1;
							}
							if (isAttackPossible == 0)
							{
								if (move == 1) move = 2;
								else move = 1;
								sBacklight.setPosition(-100, -100);
								chooseSquad = 1;
								attackEnemy = 0;
								dx = 0;
								dy = 0;
							}
						}
					}
				}
				else
				{
					for (auto k : entities)
					{
						if (k->player != theChosenOne->player)
						{
							if ((k->x * 50 == sBacklight.getPosition().x) && (k->y * 50 == sBacklight.getPosition().y) && ((fabs((theChosenOne->x) - (k->x)) <= theChosenOne->attackDistance) && (fabs((theChosenOne->y) - (k->y)) <= theChosenOne->attackDistance)))
							{
								int isTooClose = 0;
								for (auto l : entities)
								{
									if ((((k->x) - (l->x)) <= 2) || (((k->y) - (l->y)) <= 2))
									{
										isTooClose = 1;
										break;
									}
								}
								theChosenOne->attack(k, dx, dy, isTooClose);
								for (auto i = entities.begin(); i != entities.end();)
								{
									Entity *e = *i;
									if (e->squadHealth <= 0) { i = entities.erase(i); delete e; }
									else i++;
								}
								if (move == 1) move = 2;
								else move = 1;
								sBacklight.setPosition(-100, -100);
								chooseSquad = 1;
								attackEnemy = 0;
								dx = 0;
								dy = 0;
								int checkIfLose1 = 0, checkIfLose2 = 0;
								for (auto i : entities)
								{
									if (i->player == 1)
									{
										if (i->squadHealth > 0) checkIfLose1 = 1;
									}
									else
									{
										if (i->squadHealth > 0) checkIfLose2 = 1;
									}
									if ((checkIfLose1 != 0) && (checkIfLose2 != 0)) break;
								}
								if ((checkIfLose1 == 0) || (checkIfLose2 == 0))
								{
									newState = state(1);
									window.close();
									break;
								}
								break;
							}
						}
					}
				}
				break;
			}
			}
		}
	}
}

void newGame::update()
{

}

void newGame::render(sf::RenderWindow &window, sf::Sprite &sprite)
{
	window.clear();
	window.draw(sprite);
	for (auto i : entities)
	{
		window.draw(i->entitySprite);
		i->entitySprite.setPosition(i->x * 50, i->y * 50);
	}
	window.draw(sBacklight);
	window.display();
}

loadGame::loadGame(float width, float height)
{
	backlight.loadFromFile("images/backlight.png");
	sBacklight.setTexture(backlight);
	sBacklight.setPosition(-100, -100);
	try
	{
		ifstream data("savedGame.txt");
		if (data.is_open())
		{
			int a, b, c, d, e, f, g, h, i, j;
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Archer * archer1_1 = new Archer(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(archer1_1);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Archer * archer1_2 = new Archer(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(archer1_2);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Archer * archer1_3 = new Archer(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(archer1_3);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Knight * knight1_1 = new Knight(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(knight1_1);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Knight * knight1_2 = new Knight(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(knight1_2);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Rider * rider1 = new Rider(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(rider1);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Warrior * warrior1_1 = new Warrior(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(warrior1_1);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Warrior * warrior1_2 = new Warrior(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(warrior1_2);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Warrior * warrior1_3 = new Warrior(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(warrior1_3);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Wizard * wizard1 = new Wizard(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(wizard1);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Archer * archer2_1 = new Archer(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(archer2_1);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Archer * archer2_2 = new Archer(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(archer2_2);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Archer * archer2_3 = new Archer(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(archer2_3);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Knight * knight2_1 = new Knight(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(knight2_1);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Knight * knight2_2 = new Knight(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(knight2_2);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Rider * rider2 = new Rider(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(rider2);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Warrior * warrior2_1 = new Warrior(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(warrior2_1);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Warrior * warrior2_2 = new Warrior(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(warrior2_2);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Warrior * warrior2_3 = new Warrior(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(warrior2_3);
			}
			data >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
			if (a != 0)
			{
				Wizard * wizard2 = new Wizard(a, b, c, d, e, f, g, h, i, j);
				entities.push_back(wizard2);
			}
			data >> move;
		}
		else throw 2;
		data.close();
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << e << '\n';
	}
}

loadGame::~loadGame()
{

}

void loadGame::moveUp()
{
	if (((sBacklight.getPosition().x) == -100) && ((sBacklight.getPosition().y) == -100))
	{
		sBacklight.setPosition(0, 0);
	}
	if ((sBacklight.getPosition().y) != 0) sBacklight.setPosition(sBacklight.getPosition().x, sBacklight.getPosition().y - 50);
}

void loadGame::moveDown()
{
	if (((sBacklight.getPosition().x) == -100) && ((sBacklight.getPosition().y) == -100))
	{
		sBacklight.setPosition(0, 0);
	}
	if ((sBacklight.getPosition().y) != 950) sBacklight.setPosition(sBacklight.getPosition().x, sBacklight.getPosition().y + 50);
}

void loadGame::moveLeft()
{
	if (((sBacklight.getPosition().x) == -100) && ((sBacklight.getPosition().y) == -100))
	{
		sBacklight.setPosition(0, 0);
	}
	if ((sBacklight.getPosition().x) != 0) sBacklight.setPosition(sBacklight.getPosition().x - 50, sBacklight.getPosition().y);
}

void loadGame::moveRight()
{
	if (((sBacklight.getPosition().x) == -100) && ((sBacklight.getPosition().y) == -100))
	{
		sBacklight.setPosition(0, 0);
	}
	if ((sBacklight.getPosition().x) != 950) sBacklight.setPosition(sBacklight.getPosition().x + 50, sBacklight.getPosition().y);
}

void loadGame::run(sf::RenderWindow &window, sf::Sprite &sprite, state &newState)
{
	while (window.isOpen())
	{
		processEvents(window, newState);
		update();
		render(window, sprite);
	}
}

void loadGame::processEvents(sf::RenderWindow &window, state &newState)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			newState = state(4);
			window.close();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
			{
				newState = state(1);
				window.close();
				break;
			}
			case sf::Keyboard::F1:
			{
				try
				{
					fstream data;
					data.open("savedGame.txt", ios::out | ios::trunc);
					if (data.is_open())
					{
						int check = 1, repair = 0;
						for (auto k : entities)
						{
							if ((k->id) != check)
							{
								repair = (k->id) - check;
								for (repair; repair > 0; repair--)
								{
									data << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << endl;
									check++;
								}
								data << k->player << " " << k->squadAmount << " " << k->unitHealth << " " << k->squadHealth << " " << k->powerOfAttack << " " << k->maxDistance << " " << k->x << " " << k->y << " " << k->id << " " << k->attackDistance << endl;
							}
							else
							{
								data << k->player << " " << k->squadAmount << " " << k->unitHealth << " " << k->squadHealth << " " << k->powerOfAttack << " " << k->maxDistance << " " << k->x << " " << k->y << " " << k->id << " " << k->attackDistance << endl;
								check++;
							}
						}
						if (((entities.back())->id) != 20)
						{
							repair = 20 - ((entities.back())->id);
							for (repair; repair > 0; repair--)
							{
								data << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << endl;
							}
						}
						data << move;
						data.close();
						break;
					}
					else throw 3;
				}
				catch (int e)
				{
					cout << "An exception occurred. Exception Nr. " << e << '\n';
				}
			}
			case sf::Keyboard::Up:
			{
				moveUp();
				break;
			}
			case sf::Keyboard::Down:
			{
				moveDown();
				break;
			}
			case sf::Keyboard::Left:
			{
				moveLeft();
				break;
			}
			case sf::Keyboard::Right:
			{
				moveRight();
				break;
			}
			case sf::Keyboard::Return:
			{
				if (chooseSquad == 1)
				{
					for (auto k : entities)
					{
						if ((sBacklight.getPosition().x == k->x*50) && (sBacklight.getPosition().y == k->y*50) && (k->player == move))
						{
							sBacklight.setPosition(-100, -100);
							chooseSquad = 0;
							moveSquad = 1;
							theChosenOne = k;
							break;
						}
					}
				}
				else if (moveSquad == 1)
				{
					int isCollide = 0;
					for (auto k : entities)
					{
						if ((k->x*50 == sBacklight.getPosition().x) && (k->y*50 == sBacklight.getPosition().y))
						{
							isCollide = 1;
							break;
						}
					}
					if (isCollide) break;
					else
					{
						if (theChosenOne->move(sBacklight.getPosition().x, sBacklight.getPosition().y))
						{
							for (auto k : entities)
							{
								if ((k->id) == theChosenOne->id)
								{
									dx = fabs(k->x * 50 - sBacklight.getPosition().x) / 50;
									dy = fabs(k->y * 50 - sBacklight.getPosition().y) / 50;
									k->x = sBacklight.getPosition().x/50;
									k->y = sBacklight.getPosition().y/50;
									theChosenOne = k;
									break;
								}
							}
							sBacklight.setPosition(-100, -100);
							moveSquad = 0;
							attackEnemy = 1;
							int isAttackPossible = 0;
							for (auto k : entities)
							{
								if ((k->player != theChosenOne->player) && ((fabs((theChosenOne->x) - (k->x)) <= theChosenOne->attackDistance) && (fabs((theChosenOne->y) - (k->y)) <= theChosenOne->attackDistance))) isAttackPossible = 1;
							}
							if (isAttackPossible == 0)
							{
								if (move == 1) move = 2;
								else move = 1;
								sBacklight.setPosition(-100, -100);
								chooseSquad = 1;
								attackEnemy = 0;
								dx = 0;
								dy = 0;
							}
						}
					}
				}
				else
				{
					for (auto k : entities)
					{
						if (k->player != theChosenOne->player)
						{
							if ((k->x*50 == sBacklight.getPosition().x) && (k->y*50 == sBacklight.getPosition().y))
							{
								int isTooClose = 0;
								for (auto l : entities)
								{
									if ((((k->x) - (l->x)) <= 2) || (((k->y) - (l->y)) <= 2))
									{
										isTooClose = 1;
										break;
									}
								}
								theChosenOne->attack(k, dx, dy, isTooClose);
								for (auto i = entities.begin(); i != entities.end();)
								{
									Entity *e = *i;
									if (e->squadHealth <= 0) { i = entities.erase(i); delete e; }
									else i++;
								}
								if (move == 1) move = 2;
								else move = 1;
								sBacklight.setPosition(-100, -100);
								chooseSquad = 1;
								attackEnemy = 0;
								dx = 0;
								dy = 0;
								int checkIfLose1 = 0, checkIfLose2=0;
								for (auto i : entities)
								{
									if (i->player == 1)
									{
										if (i->squadHealth > 0) checkIfLose1 = 1;
									}
									else
									{
										if (i->squadHealth > 0) checkIfLose2 = 1;
									}
									if ((checkIfLose1 != 0) && (checkIfLose2 != 0)) break;
								}
								if ((checkIfLose1 == 0) || (checkIfLose2 == 0))
								{
									newState = state(1);
									window.close();
									break;
								}
								break;
							}
						}
					}
				}
				break;
			}
			}
		}
	}
}

void loadGame::update()
{

}

void loadGame::render(sf::RenderWindow &window, sf::Sprite &sprite)
{
	window.clear();
	window.draw(sprite);
	for (auto i : entities)
	{
		i->entitySprite.setPosition(i->x * 50, i->y * 50);
		window.draw(i->entitySprite);
	}
	window.draw(sBacklight);
	window.display();
}