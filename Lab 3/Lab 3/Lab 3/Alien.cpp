#include "Alien.h"

Alien::Alien()
{
	//srand(time(nullptr));
	m_rotation = 180.0f;
	m_speed = 0.0f;
	m_angleRadians = 0.0f;
	m_turn = 0.0f;
	m_velocity = { 0,0 };
	m_character.setOrigin(50, 26.5);
	m_character.setPosition(rand() % G_SCREEN_WIDTH, rand() % G_SCREEN_HEIGHT);

	m_character.setOrigin(m_character.getGlobalBounds().width / 2, m_character.getGlobalBounds().height / 2);
}

void Alien::update(sf::Time t_deltaTime)
{
	processMovement();
}

void Alien::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_character);
}

void Alien::processMovement()
{
	m_angleRadians = m_rotation * (3.14 / 180);
	m_velocity.x = cosf(m_angleRadians) * m_speed;
	m_velocity.y = sinf(m_angleRadians) * m_speed;
	m_character.setRotation(m_rotation);
	m_coolDown--;

	if (m_coolDown <= m_timer)
	{
		if (m_direction == G_NORTH)
		{
			m_direction = ((rand() % 4) + 1);
		}
		if (m_direction == G_SOUTH)
		{
			m_direction = ((rand() % 4) + 1);
		}
		if (m_direction == G_WEST)
		{
			m_direction = ((rand() % 4) + 1);
		}
		if (m_direction == G_EAST)
		{
			m_direction = ((rand() % 4) + 1);
		}

		m_coolDown = 50;
	}
	if (m_direction == G_WEST)
	{
		if (m_speed < m_maxSpeed)
		{
			m_rotation -= m_speed;
		}
	}

	if (m_direction == G_EAST)
	{
		if (m_speed < m_maxSpeed)
		{
			m_rotation += m_speed;
		}
	}

	if (m_direction == G_NORTH)
	{
		if (m_speed < m_maxSpeed)
		{
			m_speed = m_speed + 0.05;
		}

		m_character.move(m_velocity);
	}
	else if (m_direction == G_SOUTH)
	{
		if (m_speed < m_maxSpeed)
		{
			m_speed = m_speed - 0.05;
		}

		m_character.move(m_velocity);
	}
	else if (m_speed >= 0)
	{
		m_speed = m_speed * 0.995;
		m_character.move(m_velocity);
	}
	else
	{
		m_speed = m_speed * 0.995;
		m_character.move(m_velocity);
	}
}

sf::Vector2f Alien::getPosition()
{
	return m_character.getPosition();
}

void Alien::setPosition(sf::Vector2f t_position)
{
	m_character.setPosition(t_position);
}

void Alien::handleWallWrap(sf::RenderWindow& t_window)
{
	if (m_character.getPosition().x <= -20)
	{
		m_character.setPosition(t_window.getSize().x + 20, m_character.getPosition().y);
	}
	else if (m_character.getPosition().x >= t_window.getSize().x + 20)
	{
		m_character.setPosition(-20, m_character.getPosition().y);
	}
	else if (m_character.getPosition().y <= -20)
	{
		m_character.setPosition(m_character.getPosition().x, t_window.getSize().y + 20);
	}
	else if (m_character.getPosition().y >= t_window.getSize().y + 20)
	{
		m_character.setPosition(m_character.getPosition().x, -20);
	}
}

void Alien::setType(int t_type)
{
	switch (t_type)
	{
	case 0:
		m_texture.loadFromFile("ASSETS\\IMAGES\\AlienShipOne.png");
		m_character.setTexture(m_texture);
	case 1:
		m_texture.loadFromFile("ASSETS\\IMAGES\\AlienShipTwo.png");
		m_character.setTexture(m_texture);
	case 2:
		m_texture.loadFromFile("ASSETS\\IMAGES\\AlienShipThree.png");
		m_character.setTexture(m_texture);
	case 3:
		m_texture.loadFromFile("ASSETS\\IMAGES\\AlienShipFour.png");
		m_character.setTexture(m_texture);
	}
}
