#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"

class Player
{
public:

	Player();
	~Player() {};
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processKeys();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f t_position);
	void handleWallWrap(sf::RenderWindow& t_window);

private:

	void turnLeft();
	void turnRight();

	sf::Texture m_texture;
	sf::Vector2f m_velocity;
	sf::Sprite m_character;

	float m_angleRadians;
	float m_turn;
	float m_rotation;
	float m_speed;
	float m_maxSpeed;
};

