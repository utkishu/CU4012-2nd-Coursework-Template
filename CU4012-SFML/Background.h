#pragma once
#include "Framework/GameObject.h"
#include "Level.h"
#include "Player.h"
class Background : public GameObject
{
public:

	sf::View view;

	Background(); 
	~Background(); 

	void handleInput(float dt); 

};

