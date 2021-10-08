#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Alien.h"
#include "Audio.h"

class Game
{
public:
	Game();
	~Game();
	void run();
	Player m_player;
	std::vector<Alien*> m_alien;
	Audio m_audio;

	Gamemode current = Gamemode::Gameplay;

	sf::Font font;
	sf::Text walletText;

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void init();
	
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	bool m_exitGame; // control exiting game
	int m_alienCount;
	int wallet = 0;
};
#endif // !GAME