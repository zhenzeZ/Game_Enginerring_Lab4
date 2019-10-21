#include "Game.h"

Game::Game()
{
	m_window = SDL_CreateWindow("SDL WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 600, SDL_WINDOW_OPENGL);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;

	if (IMG_Init(imgFlags) != imgFlags)
	{
		cout << "Error: " << IMG_GetError() << endl;
	}
	else {
		playerTexture = IMG_LoadTexture(m_renderer, "ASSETS\\player.png");
		alienTexture = IMG_LoadTexture(m_renderer, "ASSETS\\alien.png");
		dogTexture = IMG_LoadTexture(m_renderer, "ASSETS\\dog.png");
		catTexture = IMG_LoadTexture(m_renderer, "ASSETS\\cat.png");
	}

	//player
	player.addComponent(new InputComponent());
	player.addComponent(new HealthComponent(100));
	player.addComponent(new PositionComponent(SDL_Point{ 200, 200 }));
	player.addComponent(new TextureComponent(playerTexture, m_renderer));

	//alien
	alien.addComponent(new HealthComponent(70));
	alien.addComponent(new PositionComponent(SDL_Point{ 300,300 }));
	alien.addComponent(new TextureComponent(alienTexture, m_renderer));

	//dog
	dog.addComponent(new HealthComponent(50));
	dog.addComponent(new PositionComponent(SDL_Point{ 400,400 }));
	dog.addComponent(new TextureComponent(dogTexture, m_renderer));

	//cat
	cat.addComponent(new PositionComponent(SDL_Point{ 500,500 }));
	cat.addComponent(new TextureComponent(catTexture, m_renderer));

	//AI system
	aISystem.addEntity(&alien);
	aISystem.addEntity(&dog);
	aISystem.addEntity(&cat);

	//control system
	controlSystem.addEntity(&player);

	//health system
	healthSystem.addEntity(&player);
	healthSystem.addEntity(&alien);
	healthSystem.addEntity(&dog);

	//render system
	renderSystem.addEntity(&player);
	renderSystem.addEntity(&alien);
	renderSystem.addEntity(&dog);
	renderSystem.addEntity(&cat);
}

Game::~Game()
{
}

void Game::run()
{
	const Uint32 fps = 60;
	const Uint32 minimumFrameTime = 1000 / fps;

	Uint32 frameTime;
	Uint32 lastFrameTime = 0;
	Uint32 deltaTime = 0;

	while (!m_exitGame) {

		processEvents();
		frameTime = SDL_GetTicks();
		deltaTime = frameTime - lastFrameTime;
		lastFrameTime = frameTime;

		update();
		render();

		if ((SDL_GetTicks() - frameTime) < minimumFrameTime)
			SDL_Delay(minimumFrameTime - (SDL_GetTicks() - frameTime));
	}

	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Game::processEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_exitGame = true;
			break;
		case SDL_KEYDOWN:
			controlSystem.update(event.key.keysym.sym);
			if (event.key.keysym.sym == SDLK_ESCAPE)
				m_exitGame = true;
			break;
		}
	}
}

void Game::update()
{
	aISystem.update();
	healthSystem.update();
}

void Game::render()
{
	if (m_renderer == nullptr)
	{
		SDL_Log("Could not create a renderer: %s", SDL_GetError());
	}

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

	SDL_RenderClear(m_renderer);

	renderSystem.render();

	SDL_RenderPresent(m_renderer);

}