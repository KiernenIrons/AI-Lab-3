#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Globals.h"

class Behaviour;

class Character : public sf::Drawable
{
public:
	Character(Behaviour* t_behaviour, 
				   float t_acceleration = 50.0f, 
				   float t_rotation = 0.0f,
				   float t_speed = 0.0f,
				   float t_rotationSpeed = 1.0f);

	virtual ~Character();
	virtual void update(sf::Time t_deltaTime);
	void accelerate(sf::Time t_deltaTime);
	void decelerate(sf::Time t_deltaTime);
	void rotateLeft(sf::Time t_deltaTime);
	void rotateRight(sf::Time t_deltaTime);
	void setRotation(float t_rotation);
	void setType(int t_type);

	sf::Vector2f getDirection() const;
	float getSpeed() const;
	Character* getTarget() const;
	void setTarget(Character* t_target);
	void setMaxSpeed(float t_maxSpeed);
	sf::Vector2f getPosition() const;
	float getAcceleration() const;

	void handleWallWrap(sf::RenderWindow& t_window);

	void circleSetup();

private:
	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_state) const;

	float m_acceleration;
	float m_rotation;
	float m_speed;
	float m_rotationSpeed;
	float m_maxSpeed = 400.0f;
	bool m_active;

	sf::Vector2f m_velocity;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	Behaviour* m_behaviour;
	Character* m_target;
	sf::CircleShape m_circle;

	sf::Font m_font;
	sf::Text m_name;
};

#include "Behaviour.h"