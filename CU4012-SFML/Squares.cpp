#include "Squares.h"
#include "Level.h"
#include "Player.h"

Squares::Squares()
{
}

Squares::~Squares()
{
}

void Squares::update(float dt)
{
	move(velocity * dt);

	if (getPosition().x < 0)

	{
		setPosition(0, getPosition().y);
		velocity.x = -velocity.x; 


	}

	if (getPosition().x > 1200)
	{

		setPosition(1200, getPosition().y); 
		
		velocity.x = -velocity.x;

	}


}

void Squares::CollisionResponse(GameObject* collider)
{

	velocity.x = -velocity.x; 

}
