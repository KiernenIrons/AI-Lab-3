#include "Game.h"
#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode{ G_SCREEN_WIDTH, G_SCREEN_HEIGHT, 32 }, "AI Lab 3" },
	m_exitGame{ false } //when true game will exit
{
	init(); // load font

	m_characters.push_back(new Character(new PlayerBehaviour()));
	m_characters.push_back(new Character(new Seek(), 10.0f, 0.0f, 150.0f, 1.0f));
	m_characters.push_back(new Character(new Wander(), 10.0f, 0.0f, 150.0f, 1.0f));
	m_characters.push_back(new Character(new Arrive(), 10.0f, 0.0f, 150.0f, 1.0f));

	m_characters.at(0)->setType(0); // Player
	m_characters.at(1)->setType(1); // Seek
	m_characters.at(2)->setType(2); // Wander
	m_characters.at(3)->setType(3); // Arrive

	m_characters.at(1)->setTarget(m_characters.at(0));
	m_characters.at(3)->setTarget(m_characters.at(0));
}

Game::~Game()
{
}

void Game::run()
{	
	(srand(static_cast<unsigned>(time(NULL))));
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps

	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();

		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}

		render(); // as many as possible
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	if (current == Gamemode::MenuScreen)
	{
		std::cout << "Main Menu Screen Active" << std::endl;
	}
	if (current == Gamemode::Gameplay)
	{
		std::cout << "Gameplay Screen Active" << std::endl;

		for (Character* character : m_characters)
		{
			character->update(t_deltaTime);
			character->handleWallWrap(m_window);
		}
	}
}

void Game::render()
{
	m_window.clear();

	if (current == Gamemode::MenuScreen)
	{

	}
	if (current == Gamemode::Gameplay)
	{
		for (Character* character : m_characters)
		{
			m_window.draw(*character);
		}
	}

	m_window.display();
}

void Game::init()
{

	m_audio.backgroundMusicSetup();
}