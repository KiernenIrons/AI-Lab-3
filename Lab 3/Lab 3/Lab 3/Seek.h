#pragma once

#include "Behaviour.h"

class Seek : public Behaviour
{
public:
	Seek() = default;
	void update(Character* t_character, sf::Time t_deltaTime) override;
private:
	float m_gap = 48.0f;
};