#include "RenderSystem.h"

void RenderSystem::addEntity(Entity* e)
{
	entities.push_back(e);
}


void RenderSystem::render() 
{
	for (auto entity : entities) {
		for (Component* component : entity->getComponents()) {

			TextureComponent* texture = dynamic_cast<TextureComponent*>(component);
			if (texture != nullptr) {
				for (Component* component2 : entity->getComponents()) {
					PositionComponent* position = dynamic_cast<PositionComponent*>(component2);
					if (position != nullptr)
					{
						texture->draw(position->getPosition());
					}
				}
			}
		}
	}

}