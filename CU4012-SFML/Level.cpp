#include "Level.h"
Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, World* w)
{
	window = hwnd;
	input = in;
	gameState = gs;
	world = w;
	
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "error loading font" << std::endl;
	};

	TileEditorText.setFont(font);
	TileEditorText.setCharacterSize(24);
	TileEditorText.setFillColor(sf::Color::Red);

	TileEditorText.setString(" Press E to edit tiles");
	TileEditorText.setPosition(0, 0);
	// initialise game objects
	p1.setPosition(100, 100);
	p1.setInput(input);

	e1.setPosition(500, 100);
	world->AddGameObject(p1);
	world->AddGameObject(e1);
	//world->AddGameObject(ground);

	tileManager.setInput(input);
	tileManager.setWindow(window);
	tileManager.setWorld(world);

	if (!tileManager.loadTiles())
	{
		std::cout << "Tiles not found\n";
	}
	else
	{
		std::cout << "Tiles loaded\n";
	}
	sf::Vector2f viewSize = sf::Vector2f(window->getSize().x, window->getSize().y);
	view.setSize(viewSize.x, viewSize.y);
	view.setCenter(viewSize.x / 2, viewSize.y/ 2);
}

Level::~Level()
{

}

void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}

	// Check if 'E' is pressed to toggle editing mode
	if (input->isKeyDown(sf::Keyboard::E))
	{
		// First, if we're in edit mode, we save the tiles
		if (editMode)
		{
			std::cout << "Exiting edit mode. Saving tiles...\n";
			tileManager.saveTiles(tileManager.getTiles(), tileManager.getFilePath());
		}
		// Then toggle the edit mode
		editMode = !editMode;
		input->setKeyUp(sf::Keyboard::E); // Acknowledge the key press
	}

	if (editMode)
	{
		// Handle moving the view or other edit-mode-specific logic
		moveView(dt);
		//tileManager.handleInput(dt); // tileManager might have its own logic for when editing is true
	}
	else
	{
		// Handle game logic when not in edit mode
		p1.handleInput(dt);
	}
}

// Update game objects
void Level::update(float dt)
{

	sf::Vector2f viewSize = sf::Vector2f(window->getSize().x, window->getSize().y);

	if (p1.CollisionWithTag("Enemy"))
	{
		std::cout << "Collision with enemy\n";
	}

	if (e1.CollisionWithTag("Wall"))
	{
		std::cout << "Collision with wall\n";
		e1.setVelocity(-e1.getVelocity());
	}

	if (editMode)
	{
		TileEditorText.setPosition(view.getCenter().x - viewSize.x / 2, view.getCenter().y - viewSize.y / 2);
		TileEditorText.setString("Editing mode\nPress B to set collider as a wall (allows bouncing) \nPress E to exit and Save");
		tileManager.handleInput(dt);
		tileManager.update(dt);
	}
	else
	{
		TileEditorText.setString("Press E to edit tiles");
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(TileEditorText);

	window->draw(p1);
	window->draw(p1.getDebugCollisionBox());


	window->draw(e1);
	window->draw(e1.getDebugCollisionBox());

	tileManager.render();
	endDraw();
}

void Level::moveView(float dt)
{

	if (input->isKeyDown(sf::Keyboard::W))
	{
		view.move(0, -100 * dt);
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		view.move(0, 100 * dt);
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		view.move(-100 * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		view.move(100 * dt, 0);
	}

	window->setView(view);

}

void Level::adjustViewToWindowSize(unsigned int width, unsigned int height) 
{
	sf::FloatRect visibleArea(0, 0, static_cast<float>(width), static_cast<float>(height));
	view.setSize(static_cast<float>(width), static_cast<float>(height));
	view.setCenter(static_cast<float>(width) / 2, static_cast<float>(height) / 2);
}