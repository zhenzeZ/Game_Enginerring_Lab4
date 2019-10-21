#include "ControlSystem.h"

void ControlSystem::addEntity(Entity* e)
{
	entities.push_back(e);
}

void ControlSystem::update(SDL_Keycode event)
{
	//Loop through Entites with HealthComponents and update TBI

	for (auto entity : entities) {
		for (Component* component : entity->getComponents()) {
			PositionComponent* position = dynamic_cast<PositionComponent*>(component);
			if (position != nullptr) {
				SDL_Point vecter = position->getPosition();

				for (Component* component2 : entity->getComponents()) {
					InputComponent* input = dynamic_cast<InputComponent*>(component2);
					if (input != nullptr) {
						switch (event)
						{
						case SDLK_UP:
							input->setState(input->direction::Up);
							vecter.y -= 10;
							cout << "up" << endl;
							break;
						case SDLK_LEFT:
							input->setState(input->direction::Left);
							vecter.x -= 10;
							cout << "left" << endl;
							break;
						case SDLK_RIGHT:
							input->setState(input->direction::Right);
							vecter.x += 10;
							cout << "right" << endl;
							break;
						case SDLK_DOWN:
							input->setState(input->direction::Down);
							vecter.y += 10;
							cout << "down" << endl;
							break;
						default:
							break;
						}

						position->setPosition(vecter);
					}
				}
			}
		}
	}
}
