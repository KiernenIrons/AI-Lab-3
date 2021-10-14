#pragma once

#include <SFML/Graphics.hpp>

class Character;

class Behaviour
{
public:
	Behaviour() = default;
	virtual ~Behaviour() { };
	virtual void update(Character* t_character, sf::Time t_deltaTime) = 0;
};

#include "Character.h"