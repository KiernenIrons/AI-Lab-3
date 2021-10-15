#pragma once

#include "Behaviour.h"

class PlayerBehaviour : public Behaviour
{
public:
	PlayerBehaviour() {};
	~PlayerBehaviour() {};
	void update(Character* t_character, sf::Time t_deltaTime) override;
};