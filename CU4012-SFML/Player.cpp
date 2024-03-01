#include "Player.h"

Player::Player()
{
 

	


}

Player::~Player()
{



}

void Player::update(float dt)
{



}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		
		move(0, -0.1);

	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		
		move(0, 0.1);

	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		
		move(-0.1, 0);

	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		
		move(0.1, 0);

	}

}



void Player::CollisionResponse(GameObject* collider)
{
	velocity.x = -velocity.x; 

}
