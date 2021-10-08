#include "Audio.h"

Audio::Audio()
{
}

void Audio::backgroundMusicSetup()
{
	if (!backgroundMusicBuffer.loadFromFile("ASSETS\\AUDIO\\Asteroids.ogg"))          // If The sound doesnt load
	{
		std::cout << "problem loading song" << std::endl;                   // Says There Was A problem Loading The Audio only when there is a problem loading the audio
	}
	backgroundMusic.setBuffer(backgroundMusicBuffer);
	backgroundMusic.play();
	backgroundMusic.setLoop(true);
}

void Audio::shoot()
{
	if (!shootingBuffer.loadFromFile("ASSETS\\AUDIO\\Laser.ogg"))          // If The sound doesnt load
	{
		std::cout << "problem loading song" << std::endl;                   // Says There Was A problem Loading The Audio only when there is a problem loading the audio
	}
	shootingSound.setBuffer(shootingBuffer);
	if (shootingSound.getStatus() == sf::SoundSource::Stopped)
	{
		shootingSound.play();
	}
}