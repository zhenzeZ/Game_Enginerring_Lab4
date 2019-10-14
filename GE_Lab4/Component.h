#pragma once
#include <SDL.h>

class Component {

};

class HealthComponent : public Component {
public :
	HealthComponent() : m_health(100){}

	int getHealth() { return m_health; }
	void setHealth(int health) { this->m_health = health; }
private:
	int m_health;
};

class PositionComponent : public Component {
public :
	PositionComponent() : m_position(SDL_Point{ 0,0 }) {}

	SDL_Point getPosition() { return m_position; }
	void setPosition(SDL_Point position) { this->m_position = position; }
private:
	SDL_Point m_position;
};

class InputComponent : public Component {
public:

};
