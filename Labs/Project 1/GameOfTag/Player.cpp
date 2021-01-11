#include "Player.h"

float Player::s_radius = 25.0f;

Player::Player():
	m_startPosition(sf::Vector2f(0.0f,0.0f)),
	m_position(m_startPosition),
	m_name("Blank")
{
	m_body = sf::CircleShape(s_radius);
	m_body.setOrigin(s_radius, s_radius);
	m_body.setPosition(m_position);
}

sf::Vector2f Player::getPosition()
{
	return m_position;
}

sf::Vector2f Player::move()
{
	sf::Vector2f moveVector = sf::Vector2f(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveVector = sf::Vector2f(0.0f, -1.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		moveVector = sf::Vector2f(0.0f, 1.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveVector = sf::Vector2f(-1.0f, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveVector = sf::Vector2f(1.0f, 0.0f);
	}

	return moveVector;
}

sf::Vector2f Player::getStartPosition()
{
	return m_startPosition;
}

std::string Player::getName()
{
	return m_name;
}

void Player::update(sf::Time t_dt)
{
}

void Player::setColour(sf::Color t_colour)
{
	m_body.setFillColor(t_colour);
}

void Player::setName(std::string t_newName)
{
	m_name = t_newName;
}

void Player::setStartPosition(sf::Vector2f t_position)
{
	m_startPosition = t_position;
}

void Player::updatePosition(sf::Vector2f t_velocity)
{
	m_position += t_velocity;
	checkBoundry();
}

void Player::setPosition(sf::Vector2f t_newPosition)
{
	m_position = t_newPosition;
	m_body.setPosition(m_position);
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
}

void Player::checkBoundry()
{
	if (m_position.x - s_radius < 0)
	{
		m_position.x = s_radius;
	}

	else if (m_position.x + s_radius > 500)
	{
		m_position.x = 500 - s_radius;
	}

	if (m_position.y - s_radius < 0)
	{
		m_position.y = s_radius;
	}

	else if (m_position.y + s_radius > 500)
	{
		m_position.y = 500 - s_radius;
	}

	m_body.setPosition(m_position);
}