#include "Player.h"

Player::Player()
{
	health = 100;
	speed = 200;


	if (!texture.loadFromFile("gfx/Mushroom.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&texture);
	setSize(sf::Vector2f(100, 100));
	setCollisionBox(getPosition(), getSize());
	setMass(100.f);
	setTag("Player");
}

void Player::handleInput(float dt)
{
	velocity.x = 0.f;

	// Update velocity based on input
	if (input->isKeyDown(sf::Keyboard::A))
	{
		// Update only the horizontal component, preserving vertical velocity
		velocity.x = -speed;
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		// Update only the horizontal component, preserving vertical velocity
		velocity.x = speed;
	}
	
	if (input->isKeyDown(sf::Keyboard::Space) && canJump )
	{
		Jump(200.f);
	}
	// If left mouse button is pressed, create a projectile
	if (input->isLeftMouseDown())
	{
		//set Key up 
		input->setLeftMouse(Input::MouseState::UP); // Mark the mouse click as handled

		// Create a new projectile
		Projectiles* bullet = new Projectiles();
		sf::Vector2f BulletPos = getPosition()+sf::Vector2f(100,50);
		bullet->setPosition(BulletPos);

		// Calculate the position of the mouse
		sf::Vector2f MousePos = sf::Vector2f(input->getMouseX(), input->getMouseY());

		// Calculate the direction from the bullet's position to the mouse position
		sf::Vector2f direction = MousePos - getPosition();

		// Normalize the direction vector
		float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		sf::Vector2f normalizedDirection = direction / magnitude;

		// Set the velocity of the bullet to be in the direction of the mouse
		// Adjust the speed as needed by multiplying the normalized direction by the desired speed
		bullet->setVelocity(normalizedDirection * 1000.f); // You can adjust the speed by changing 1000.f

		// Add the bullet to the list of bullets
		bullets.push_back(bullet);

		// Add the bullet to the world
		world->AddGameObject(*bullet);
	}


}

void Player::update(float dt)
{

}
