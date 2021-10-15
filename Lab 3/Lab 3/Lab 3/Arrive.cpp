#include "Arrive.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
void Arrive::update(Character* t_character, sf::Time t_deltaTime)
{
	if (t_character && t_character->getTarget())
	{
		sf::Vector2f targetDir = t_character->getTarget()->getPosition() - t_character->getPosition();
		float turn = (t_character->getDirection().x * targetDir.y) - (t_character->getDirection().y * targetDir.x);

		if (turn < 0.0f)
		{
			t_character->rotateLeft(t_deltaTime);
		}
		else
		{
			t_character->rotateRight(t_deltaTime);
		}

		float const stopDist = (t_character->getSpeed() * t_character->getSpeed()) / (2.0f * t_character->getAcceleration()) + m_gap;
		float const magDir = sqrtf(targetDir.x * targetDir.x + targetDir.y * targetDir.y);

		if (magDir >= stopDist)
		{
			t_character->accelerate(t_deltaTime);
		}
		else
		{
			t_character->decelerate(t_deltaTime);
		}
	}
}