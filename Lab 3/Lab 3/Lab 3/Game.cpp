#include "Game.h"
#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode{ G_SCREEN_WIDTH, G_SCREEN_HEIGHT, 32 }, "AI Lab 3" },
	m_exitGame{ false } //when true game will exit
{
	init(); // load font

	m_characters.push_back(new Character(new playerBehaviour()));
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

		//m_player.handleWallWrap(m_window);
	}

	walletText.setString("Materials: " + std::to_string(wallet));
}

void Game::render()
{
	m_window.clear();

	if (current == Gamemode::MenuScreen)
	{

	}
	if (current == Gamemode::Gameplay)
	{
		m_window.draw(walletText);
	}

	m_window.display();
}

void Game::init()
{
	font.loadFromFile("ASSETS\\FONTS\\ethnocentric.ttf");
	walletText.setFont(font);
	walletText.setFillColor(sf::Color::White);
	walletText.setCharacterSize(20);

	m_audio.backgroundMusicSetup();
}