#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

GameObject* player;
GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initalized!..." << std::endl;
		window= SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window) {
			std::cout << "Window Created!" << std::endl;
		}

		renderer == SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!" << std::endl;
		}

		isRunning = true;
	}
	/*else {
		isRunning = false;
	}*/

	player = new GameObject("Assets/Player.png", 0, 0);
	enemy = new GameObject("Assets/enemy.png", 50, 50);
	map = new Map();
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::update()
{
	player->update();
	enemy->update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//aqui es donde vamos a agregar cosas para renderear
	map->DrawMap();
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
