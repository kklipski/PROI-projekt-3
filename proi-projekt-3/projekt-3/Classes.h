#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include <list>
#define NUMBER_OF_ITEMS 3

using std::string;

enum state { MENU = 1, NEW_GAME = 2, LOAD_GAME = 3, EXIT = 4 };

class Entity
{
public:
	Entity();
	~Entity();
	virtual void attack(Entity *a, int x, int y, int isTooClose);
	bool move(float a, float b);
	sf::Texture entityTexture;
	sf::Sprite entitySprite;
	int id, player, squadAmount, unitHealth, squadHealth, powerOfAttack, maxDistance, x, y, attackDistance;
};

class Archer : public Entity
{
public:
	Archer(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
	~Archer();
	void attack(Entity *a, int x, int y, int isTooClose);
};

class Knight : public Entity
{
public:
	Knight(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
	~Knight();
	void attack(Entity *a, int x, int y, int isTooClose);
};

class Rider : public Entity
{
public:
	Rider(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
	~Rider();
	void attack(Entity *a, int x, int y, int isTooClose);
};

class Warrior : public Entity
{
public:
	Warrior(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
	~Warrior();
	void attack(Entity *a, int x, int y, int isTooClose);
};

class Wizard : public Entity
{
	public:
	Wizard(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
	~Wizard();
	void attack(Entity *a, int x, int y, int isTooClose);
};

class Menu
{
public:
	Menu(float width, float height);
	~Menu();
	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int getSelectedItemIndex();
private:
	sf::Font font;
	sf::Text menu[NUMBER_OF_ITEMS];
	int selectedItemIndex = 0;
};

class newGame
{
public:
	newGame(float width, float height);
	~newGame();
	void run(sf::RenderWindow &window, sf::Sprite &sprite, state &newState);
	std::list<Entity*> entities;
	int move=1;
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	sf::Texture backlight;
	sf::Sprite sBacklight;
private:
	void processEvents(sf::RenderWindow &window, state &newState);
	void update();
	void render(sf::RenderWindow &window, sf::Sprite &sprite);
	int chooseSquad = 1, moveSquad = 0, attackEnemy = 0;
	Entity *theChosenOne;
	int dx = 0, dy = 0;
};

class loadGame
{
public:
	loadGame(float width, float height);
	~loadGame();
	void run(sf::RenderWindow &window, sf::Sprite &sprite, state &newState);
	std::list<Entity*> entities;
	int move=1;
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	sf::Texture backlight;
	sf::Sprite sBacklight;
private:
	void processEvents(sf::RenderWindow &window, state &newState);
	void update();
	void render(sf::RenderWindow &window, sf::Sprite &sprite);
	int chooseSquad = 1, moveSquad = 0, attackEnemy = 0;
	Entity *theChosenOne;
	int dx = 0, dy = 0;
};