#pragma once

#include "Behaviour.h"

class Wander : public Behaviour
{
public:
	Wander() = default;
	void update(Character* t_character, sf::Time t_deltaTime) override;
};