#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "IShapeManager.hh"
#include "ShapeEntity.hh"
#include "CircleEntity.hh"


CircleEntity::CircleEntity()
	: ShapeEntity()
{
}

void CircleEntity::Draw(IShapeManager* manager)
{
	sf::Shape* s = GetShape();
	sf::RenderWindow* window = manager->GetWindow();
	window->draw(*s);
}

void CircleEntity::Update()
{
}

std::string & CircleEntity::Serialize()
{
	std::string ret = "CircleEntity";
	return ret;
}

sf::CircleShape * CircleEntity::GetCircle() const
{
	sf::Shape* s = GetShape();
	return dynamic_cast<sf::CircleShape*>(s);
}

void CircleEntity::SetCircle(float radius, std::size_t pointCount = 30, sf::Color color = sf::Color::Black)
{
	sf::CircleShape* shape = new sf::CircleShape(radius, pointCount);
	shape->setFillColor(color);
	SetShape(shape);
}

CircleEntity::~CircleEntity()
{
}
