#pragma once
#include "ShapeEntity.hh"
#include "IShapeManager.hh"
#include <SFML/Graphics.hpp>

class CircleEntity :
	public ShapeEntity
{
public:
	CircleEntity();
	
	virtual void Draw(IShapeManager*) override;
	virtual void Update() override;
	virtual std::string& Serialize() override;

	sf::CircleShape* GetCircle() const;
	void SetCircle(float, std::size_t, sf::Color);

	~CircleEntity();
};
