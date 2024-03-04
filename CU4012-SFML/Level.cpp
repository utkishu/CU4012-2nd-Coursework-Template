#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs)
{
	window = hwnd;
	input = in;
	gameState = gs;

	// initialise game objects
	// how to shoot
	// //add gravity
	// make collision with ground
	//moliere
	PlayerTex.loadFromFile("gfx/MinerMole.png");
	PlayerSprite.setCollisionBox(sf::FloatRect(0, 0, 40, 40));
	PlayerSprite.setTexture(&PlayerTex);
	PlayerSprite.setPosition(10, 30);
	PlayerSprite.setInput(input);
	PlayerSprite.setSize(sf::Vector2f(60, 60));

	BackgroundTex.loadFromFile("gfx/BackgroundDirt.jpg");
	bg.setTexture(&BackgroundTex);
	bg.setSize(sf::Vector2f(2210, 1100));
	bg.setInput(input);
	bg.setWindow(window);

	TerrainBackground.loadFromFile("gfx/Terrain.jpg");
	ter1.setCollisionBox(sf::FloatRect(0, 0, 80, 40));
	ter1.setPosition(0, 80);
	ter1.setTexture(&TerrainBackground);
	ter1.setSize(sf::Vector2f(500, 50));

	BatSprite.loadFromFile("gfx/BatLeft.png");
	Bat.setTexture(&BatSprite);
	Bat.setSize(sf::Vector2f(70, 60));
	Bat.setPosition(300, 30);

	BlunderB.loadFromFile("gfx/Blunderbuss.png");
	BBuss.setTexture(&BlunderB);
	BBuss.setSize(sf::Vector2f(60, 30));
	BBuss.setPosition(25, 65);
	BBuss.setInput(input);
	BBuss.setWindow(window);

	bulletTexture.loadFromFile("gfx/Beach_Ball.png");
	bullets.setTexture(&bulletTexture);
	bullets.setSize(sf::Vector2f(10, 10));

}

Level::~Level()
{
	

}

// handle user input
void Level::handleInput(float dt)
{
	PlayerSprite.handleInput(dt);

	BBuss.handleInput(dt);

	if (input->isLeftMouseDown())
	{
		//input->setLeftMouse(Input::MouseState::UP);
		//bullets.setPosition(BBuss.getPosition());
		bullets.shoot(dt);
	}
}

// Update game objects
void Level::update(float dt)
{

	BBuss.setPosition(PlayerSprite.getPosition().x, PlayerSprite.getPosition().y+30);
	if (Collision::checkBoundingBox(&PlayerSprite, &ter1))
	{
		PlayerSprite.CollisionResponse(&ter1);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(bg);
	window->draw(ter1);
	window->draw(Bat);
	window->draw(PlayerSprite);
	window->draw(BBuss);
	window->draw(bullets);

	endDraw();
}
