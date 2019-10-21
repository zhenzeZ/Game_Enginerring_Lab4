#include "AISystem.h"

void AISystem::addEntity(Entity* e)
{
	entities.push_back(e);
}

void AISystem::update()
{

	for (auto entity : entities) {
		for (Component* component : entity->getComponents()) {
			PositionComponent* position = dynamic_cast<PositionComponent*>(component);
			if (position != nullptr) {
				SDL_Point vecter = position->getPosition();

				vecter.x += rand() % 4 - 2;
				vecter.y += rand() % 4 - 2;

				if (vecter.x > 900) {
					vecter.x = 0;
				}
				else if (vecter.x < 0) {
					vecter.x = 900;
				}

				if (vecter.y > 600) {
					vecter.y = 0;
				}
				else if (vecter.y < 0) {
					vecter.y = 600;
				}

				position->setPosition(vecter);
			}
		}
	}
}
