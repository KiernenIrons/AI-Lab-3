#include "playerBehaviour.h"

void playerBehaviour::update(Character* t_character, sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		t_character->accelerate(t_deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		t_character->decelerate(t_deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		t_character->rotateLeft(t_deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		t_character->rotateRight(t_deltaTime);
	}
}