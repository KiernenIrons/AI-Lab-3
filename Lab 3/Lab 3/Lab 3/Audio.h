#pragma once

#include  <SFML/Audio.hpp>
#include <iostream>

class Audio
{
	sf::SoundBuffer backgroundMusicBuffer;
	sf::Sound backgroundMusic;
	sf::SoundBuffer shootingBuffer;
	sf::Sound shootingSound;
public:
	Audio();

	void backgroundMusicSetup();
	void shoot();
};

