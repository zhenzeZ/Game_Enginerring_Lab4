#pragma once
#include <SDL.h>
#include "Entity.h"
#include "Component.h"

class RenderSystem {
	std::vector<Entity*> entities;
public:
	void addEntity(Entity* e);
	void render();
};