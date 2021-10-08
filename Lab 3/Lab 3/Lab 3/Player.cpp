#include "Player.h"

Player::Player()
{
	m_texture.loadFromFile("ASSETS/IMAGES/blueship2.png");
	m_character.setTexture(m_texture);
	m_character.setOrigin(38, 20);
	m_rotation = 0.0f;
	m_speed = 0.0f;
	m_maxSpeed = 5.0f;
	m_turn = 3.0f;
	m_angleRadians = 0.0f;
	m_velocity = { 0,0 };
	m_character.setPosition(G_SCREEN_WIDTH / 2 - 100, G_SCREEN_HEIGHT / 2);
}

void Player::update(sf::Time t_deltaTime)
{
	processKeys();
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_character);
}

void Player::processKeys()
{
	m_character.setRotation(m_rotation);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		turnLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		turnRight();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_angleRadians = m_rotation * (PI / 180);
		m_velocity.x = cosf(m_angleRadians) * m_speed;
		m_velocity.y = sinf(m_angleRadians) * m_speed;
		if (m_speed <= m_maxSpeed)
		{
			m_speed = m_speed + 0.05;
		}

		m_character.move(m_velocity);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_velocity.x = cosf(m_angleRadians) * m_speed;
		m_velocity.y = sinf(m_angleRadians) * m_speed;
		if (m_speed > 0)
		{
			m_speed = m_speed - 0.05;
		}

		m_character.move(m_velocity);
	}
	else if (m_speed >= 0)
	{
		m_speed = m_speed * 0.995;
		m_velocity.x = cosf(m_angleRadians) * m_speed;
		m_velocity.y = sinf(m_angleRadians) * m_speed;
		m_character.move(m_velocity);
	}
}

sf::Vector2f Player::getPosition()
{
	return m_character.getPosition();
}

void Player::setPosition(sf::Vector2f t_position)
{
	m_character.setPosition(t_position);
}

void Player::handleWallWrap(sf::RenderWindow& t_window)
{
	if (m_character.getPosition().x > t_window.getSize().x + 50)
	{
		m_character.setPosition(0, m_character.getPosition().y);
	}
	if (m_character.getPosition().x < -50)
	{
		m_character.setPosition(t_window.getSize().x, m_character.getPosition().y);
	}
	if (m_character.getPosition().y > t_window.getSize().y + 26)
	{
		m_character.setPosition(m_character.getPosition().x, 0);
	}
	if (m_character.getPosition().y < -26)
	{
		m_character.setPosition(m_character.getPosition().x, t_window.getSize().y);
	}
}

void Player::turnLeft()
{
	m_rotation -= m_turn;
}

void Player::turnRight()
{
	m_rotation += m_turn;
}
