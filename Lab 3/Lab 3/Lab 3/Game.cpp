#include "Game.h"
#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT, 32 }, "AI Lab 3" },
	m_exitGame{ false } //when true game will exit
{
	init(); // load font

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

		m_player.update(t_deltaTime);
		m_player.processWalls(m_window);

		for (Alien* alien : m_alien)
		{
			alien->update(t_deltaTime);
			alien->processWalls(m_window);
		}
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
		m_player.render(m_window);

		for (Alien* alien : m_alien)
		{
			alien->render(m_window);
		}

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

	m_alienCount = 5;

	for (int i = 0; i < m_alienCount; i++)
	{
		m_alien.push_back(new Alien);
	}

	m_alien.at(0)->setType(0);
	m_alien.at(1)->setType(1);
	m_alien.at(2)->setType(2);
	m_alien.at(3)->setType(2);
	m_alien.at(4)->setType(3);

	m_audio.backgroundMusicSetup();
}