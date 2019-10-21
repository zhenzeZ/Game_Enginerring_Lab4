#pragma once
#include <SDL.h>
#include "Entity.h"
#include "Component.h"

class ControlSystem {
	std::vector<Entity*> entities;
public:
	void addEntity(Entity* e);
	void update(SDL_Keycode key);
};