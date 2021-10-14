#pragma once

#include "Behaviour.h"

class ArriveBehaviour : public Behaviour
{
public:
	ArriveBehaviour() = default;
	void update(Character* t_character, sf::Time t_deltaTime) override;
private:
	float m_gap = 48.0f;
};