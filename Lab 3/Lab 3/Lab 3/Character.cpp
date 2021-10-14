#include "Character.h"

Character::Character(Behaviour* t_behaviour, 
					 float t_acceleration, 
					 float t_rotation, 
					 float t_speed, 
					 float t_rotationSpeed) :
m_acceleration(t_acceleration),
m_rotation(t_rotation),
m_speed(t_speed),
m_rotationSpeed(t_rotationSpeed),
m_behaviour(t_behaviour),
m_target(nullptr),
m_active(true)
{
	m_sprite.setPosition(400.0f, 300.0f);
	setRotation(t_rotation);
}

Character::~Character()
{
}

void Character::update(sf::Time t_deltaTime)
{
	if (m_active)
	{
		if (m_behaviour)
		{
			m_behaviour->update(this, t_deltaTime);
		}
	}
}

void Character::accelerate(sf::Time t_deltaTime)
{
	m_velocity += (m_velocity / getSpeed()) *
				   m_acceleration * t_deltaTime.asSeconds();

	if (getSpeed() > m_maxSpeed)
	{
		m_velocity = (m_velocity / getSpeed()) * m_maxSpeed;
	}
}

void Character::decelerate(sf::Time t_deltaTime)
{
	float decelerate = m_acceleration * t_deltaTime.asSeconds();

	if (getSpeed() >= decelerate)
	{
		m_velocity -= (m_velocity / getSpeed());
	}
	else
	{
		m_velocity = { 0.0f, 0.0f };
	}
}

void Character::rotateLeft(sf::Time t_deltaTime)
{
	setRotation(m_sprite.getRotation() - getSpeed() * m_rotationSpeed * t_deltaTime.asSeconds());
}

void Character::rotateRight(sf::Time t_deltaTime)
{
	setRotation(m_sprite.getRotation() + getSpeed() * m_rotationSpeed * t_deltaTime.asSeconds());
}

void Character::draw(sf::RenderTarget& t_target, sf::RenderStates t_state) const
{
	if (m_active)
	{
		t_target.draw(m_sprite, t_state);
	}
}

void Character::setRotation(float t_rotation)
{
	float speed = getSpeed();
	m_velocity.x = cosf(t_rotation * (PI / 180.0f));
	m_velocity.y = sinf(t_rotation * (PI / 180.0f));
	m_velocity *= speed;
	m_sprite.setRotation(t_rotation);
}

void Character::setType(int t_type)
{
	if (t_type > -1 && t_type < 5)
	{
		switch (t_type)
		{
		case 0:
			m_texture.loadFromFile("../ASSETS/IMAGES/player.png");
			break;
		case 1:
			m_texture.loadFromFile("../ASSETS/IMAGES/AlienShipOne.png");
			break;
		case 2:
			m_texture.loadFromFile("../ASSETS/IMAGES/AlienShipTwo.png");
			break;
		case 3:
			m_texture.loadFromFile("../ASSETS/IMAGES/AlienShipThree.png");
			break;
		case 4:
			m_texture.loadFromFile("../ASSETS/IMAGES/AlienShipFour.png");
			break;
		default:
		}

		m_sprite.setTexture(m_texture);
	}
}

sf::Vector2f Character::getDirection() const
{
	return m_velocity / getSpeed();
}

float Character::getSpeed() const
{
	return sqrtf(m_velocity.x * m_velocity.x +
				 m_velocity.y * m_velocity.y);
}

Character* Character::getTarget() const
{
	return m_target;
}

sf::Vector2f Character::getPosition() const
{
	return m_sprite.getPosition();
}

float Character::getAcceleration() const
{
	return m_acceleration;
}

void Character::handleWallWrap(sf::RenderWindow& t_window)
{
	if (m_sprite.getPosition().x > t_window.getSize().x + 50)
	{
		m_sprite.setPosition(0, m_sprite.getPosition().y);
	}
	if (m_sprite.getPosition().x < -50)
	{
		m_sprite.setPosition(t_window.getSize().x, m_sprite.getPosition().y);
	}
	if (m_sprite.getPosition().y > t_window.getSize().y + 26)
	{
		m_sprite.setPosition(m_sprite.getPosition().x, 0);
	}
	if (m_sprite.getPosition().y < -26)
	{
		m_sprite.setPosition(m_sprite.getPosition().x, t_window.getSize().y);
	}
}