#include "Wander.h"

void Wander::update(Character* t_character, sf::Time t_deltaTime)
{
	if (t_character)
	{
        if (rand() % 4 == 0)
        {
            if (rand() % 2 == 0)
                t_character->rotateLeft(t_deltaTime);
            else
                t_character->rotateRight(t_deltaTime);
        }
	}
}
