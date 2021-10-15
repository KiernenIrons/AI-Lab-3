#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Audio.h"
#include "playerBehaviour.h"
#include "Seek.h"
#include "Wander.h"
#include "Arrive.h"

class Game
{
public:
	Game();
	~Game();
	void run();
	Audio m_audio;

	Gamemode current = Gamemode::Gameplay;

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void init();

	std::vector<Character*> m_characters;
	
	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game
};
#endif // !GAME