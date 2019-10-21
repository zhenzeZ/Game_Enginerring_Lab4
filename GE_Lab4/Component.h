#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

class Component {
public:
	Component() {};
	virtual ~Component() {};
};

class HealthComponent : public Component {
public :
	HealthComponent(int health) : m_health(health){}

	int getHealth() { return m_health; }
	void setHealth(int health) { this->m_health = health; }
private:
	int m_health;
};

class PositionComponent : public Component {
public :
	PositionComponent(SDL_Point position) : m_position(position) {}

	SDL_Point getPosition() { return m_position; }
	void setPosition(SDL_Point position) { this->m_position = position; }

private:
	SDL_Point m_position;
};

class InputComponent : public Component {
public:

	enum direction {
		Left,
		Right,
		Up,
		Down
	};
	InputComponent(){}

	void setState(direction state) {
		std::cout << state << std::endl;
		m_currentState = state;
	};

	direction getState() {
		return m_currentState;
	}
private:

	direction m_currentState;
};

class TextureComponent : public Component {
public:
	TextureComponent(SDL_Texture* texture, SDL_Renderer* renderer) : m_texture(texture), m_renderer(renderer){}

	void setTexture(SDL_Texture* texture) { this->m_texture = texture; }

	void draw(SDL_Point vecter) {
		dsrcrect.x = vecter.x;
		dsrcrect.y = vecter.y;

		SDL_RenderCopy(m_renderer, m_texture, &srcrect, &dsrcrect);
	}
private:
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;
	SDL_Rect srcrect = { 0,0,50,50 };
	SDL_Rect dsrcrect = { 0,0,50,50 };
};