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
	InitialiseTileManager();
	
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
}

// Update game objects
void Level::update(float dt)
{
	sf::Vector2f viewSize = sf::Vector2f(window->getSize().x, window->getSize().y);
	EditMode(dt, viewSize);
}

// Render level
void Level::render()
{
	beginDraw();
	DrawEditModeText();
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
void Level::EditMode(float dt, sf::Vector2f viewSize)
{
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
		TileEditorText.setPosition(view.getCenter().x - viewSize.x / 2, view.getCenter().y - viewSize.y / 2);
		TileEditorText.setString("Editing mode\nLeft Mouse Button to place tile\nPress B to set collider as a wall (allows bouncing)\nPress C to make it a collectable\nPress P to make it a Platform\nPress E to exit and Save");
		tileManager.handleInput(dt);
		tileManager.update(dt);
		moveView(dt);
	}
	else
	{
		TileEditorText.setString("Press E to edit tiles");
	}
}
void Level::DrawEditModeText()
{
	window->draw(TileEditorText);
	tileManager.render(editMode);
	if (editMode) window->draw(TileEditorText);
}
void Level::InitialiseTileManager()
{
	TileEditorText.setFont(font);
	TileEditorText.setCharacterSize(24);
	TileEditorText.setFillColor(sf::Color::Red);

	TileEditorText.setString(" Press E to edit tiles");
	TileEditorText.setPosition(0, 0);

	// Set up tile manager
	tileManager.setCollectableTexture("gfx/Collectable.png");
	tileManager.setPlatformTexture("gfx/Platform.png");
	tileManager.setInput(input);
	tileManager.setWindow(window);
	tileManager.setWorld(world);
	tileManager.ShowDebugCollisionBox(true);

	if (!tileManager.loadTiles())
	{
		std::cout << "Tiles not found\n";
	}
	else
	{
		std::cout << "Tiles loaded\n";
	}
}
void Level::adjustViewToWindowSize(unsigned int width, unsigned int height) 
{
	sf::FloatRect visibleArea(0, 0, static_cast<float>(width), static_cast<float>(height));
	view.setSize(static_cast<float>(width), static_cast<float>(height));
	view.setCenter(static_cast<float>(width) / 2, static_cast<float>(height) / 2);
}