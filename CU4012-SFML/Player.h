#pragma once
#include "Framework/GameObject.h"
#include "Projectiles.h"
#include "Framework/World.h"
#include<vector>
#include <iostream>
class Player : public GameObject
{
	int health;
	float speed;
	sf::Texture texture;
	std::vector<Projectiles*> bullets;

	World* world;
public:
	Player();

	void handleInput(float dt);
	void update(float dt);

	void setWorld(World* world) { this->world = world; }	

	std::vector<Projectiles*>& getBullets() { return bullets; }
};

