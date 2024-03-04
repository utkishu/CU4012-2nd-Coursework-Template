#include "Level.h"
#include "Player.h"
#include "Squares.h"
#include "Background.h" 
#include "Enemy.h"


Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs)
{


	window = hwnd;
	input = in;
	gameState = gs;

	// initialise game objects

	//Player 
	PlayerTex.loadFromFile("gfx/Player.png");

	Player.setTexture(&PlayerTex); 
	Player.setSize(sf::Vector2f(100, 100));
	Player.setPosition(sf::Vector2f(100, 100));
	Player.setVelocity(250, 250); 
	Player.setInput(input);

	

	// Background 

	backgroundTex.loadFromFile("gfx/Background.png"); 

	bg.setTexture(&backgroundTex); 
	bg.setSize(sf::Vector2f(11038, 675)); 
	bg.setInput(input); 
	bg.setWindow(window); 


	//Enemy 
	e1.loadFromFile("gfx/Enemy.png");

	Enemy1.setTexture(&e1);
	Enemy1.setSize(sf::Vector2f(100, 100)); 
	Enemy1.setPosition(500, 500); 
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//To make the player move. 
	Player.handleInput(dt);
	//To make background move.
	bg.handleInput(dt); 
}

// Update game objects
void Level::update(float dt)
{
	
}

// Render level
void Level::render()
{
	beginDraw();
	//Background rendered 
	window->draw(bg);
	//Player rendered
	window->draw(Player);
	//Enemy 1
	window->draw(Enemy1);


	endDraw();
}
