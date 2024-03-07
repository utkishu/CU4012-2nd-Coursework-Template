#include "BossLevel.h"






BossLevel::BossLevel(sf::RenderWindow* hwnd, Input* in, GameState* gs)
{
	bossBgTex.loadFromFile("gfx/BackgroundDirt.jpg");
	bossBg.setTexture(&bossBgTex);
	bossBg.setSize(sf::Vector2f(2210, 1100));
	bossBg.setInput(input);
	bossBg.setWindow(window);
}

BossLevel::~BossLevel()
{
}

void BossLevel::handleInput(float dt)
{
}

void BossLevel::update(float dt)
{
}

void BossLevel::render()
{
	beginDraw();
	window->draw(bossBg);
	endDraw();
}
