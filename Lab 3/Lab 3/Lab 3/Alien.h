#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <ctime>   // supports ctime function

class Alien
{
public:
	Alien();
	~Alien() {};
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processMovement();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f t_position);
	void handleWallWrap(sf::RenderWindow& t_window);
	void setType(int t_type);

private:

	sf::Vector2f m_velocity;
	sf::Texture m_texture;
	sf::Sprite m_character;

	float m_angleRadians;
	float m_speed;
	float m_turn;
	float m_rotation;
	float m_maxSpeed = 5.0f;
	int m_coolDown = 50;
	int m_timer = 0;
	int m_direction = 1;
};