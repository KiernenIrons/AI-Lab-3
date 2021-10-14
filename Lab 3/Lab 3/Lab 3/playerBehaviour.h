#pragma once

#include "Behaviour.h"

class playerBehaviour : public Behaviour
{
public:
	playerBehaviour() {};
	~playerBehaviour() {};
	void update(Character* t_character, sf::Time t_deltaTime) override;
};