#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameState.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Background.h"
#include "Level.h"
#include "Enemy.h"


class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	// Default variables for level class.

	//Player 
	Player Player; 

	sf::Texture PlayerTex; 

	//AABB 
	

	//Background 

	Background bg; 
	sf::Texture backgroundTex; 

	//Enemy 
	Enemy Enemy1; 
	Enemy Enemy2; 


	sf::Texture e1; 
	sf::Texture e2;

	// sf::Vector2f move, move1; 
};