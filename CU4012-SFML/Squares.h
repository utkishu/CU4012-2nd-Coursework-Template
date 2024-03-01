#pragma once
#include "Framework/GameObject.h"
#include "Level.h"
#include "Player.h"

class Squares : public GameObject
{
public: 

	Squares(); 
	~Squares(); 

	void update(float dt); 

	void CollisionResponse(GameObject* collider); 


};

