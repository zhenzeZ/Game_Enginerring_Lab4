#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Entity.h"
#include "Component.h"
#include "AIsystem.h"
#include "ControlSystem.h"
#include "HealthSystem.h"
#include "RenderSystem.h"

using namespace std;

class Game {

public:
	Game();
	~Game();

	void run();
private:

	void processEvents();
	void update();
	void render();

	bool m_exitGame;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	Entity player;
	Entity alien;
	Entity dog;
	Entity cat;

	AISystem aISystem;
	ControlSystem controlSystem;
	HealthSystem healthSystem;
	RenderSystem renderSystem;

	SDL_Texture* playerTexture;
	SDL_Texture* alienTexture;
	SDL_Texture* dogTexture;
	SDL_Texture* catTexture;
};