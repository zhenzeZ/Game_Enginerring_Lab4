#pragma once
#include <SDL.h>
#include "Entity.h"
#include "Component.h"

class HealthSystem {
	std::vector<Entity*> entities;
public:
	void addEntity(Entity* e);
	void update();
};