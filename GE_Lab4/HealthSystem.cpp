#include "HealthSystem.h"

void HealthSystem::addEntity(Entity* e)
{
	entities.push_back(e);
}

void HealthSystem::update()
{

	for (auto entity : entities) {
		for (Component* component : entity->getComponents()) {
			HealthComponent* health = dynamic_cast<HealthComponent*>(component);
			if (health != nullptr) {
				int currentHealth = health->getHealth();
				std::cout << "health: " << currentHealth << std::endl;
			}
		}
	}

}
