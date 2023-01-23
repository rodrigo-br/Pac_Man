#include "../header_files/Game.hpp"

SDL_Texture* Game::loadTexture(const char *fileName)
{
	SDL_Surface* surface = IMG_Load(fileName);
	if (!surface)
	{
		SDL_Log("Failed to load texture file %s", fileName);
		return nullptr;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
	if (!texture)
	{
		SDL_Log("Failed to convert surface to texture for %s", fileName);
		return nullptr;
	}
	return texture;
}

void Game::loadData()
{
	// ...
}

bool Game::initialize()
{
	IMG_Init(IMG_INIT_PNG);
	loadTexture("assets/capybara.png");

	loadData();

	return true;
}

float Game::updateDeltaTime()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), this->ticksCount + 16))
		;

	float deltaTime = (SDL_GetTicks() - this->ticksCount) / 1000.0f;

	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}
	this->ticksCount = SDL_GetTicks();

	return deltaTime;
};

static void deleteDeadActors(std::vector<Actor*>& actors)
{
	std::vector<Actor *> deadActors;

	for (auto actor : actors)
	{
		if (actor->getState() == Actor::DEAD)
		{
			deadActors.emplace_back(actor);
		}
	}
	for (auto actor : deadActors)
	{
		delete actor;
	}
};

static void updatingActorsCaller(std::vector<Actor*>& actors, float deltaTime, bool &updating)
{
	updating = true;
	for (auto actor : actors)
	{
		actor->update(deltaTime);
	}
	updating = false;
};

static void updatingPendingActorsCaller(std::vector<Actor*>& actors, std::vector<Actor*>&pending)
{
	for (auto actor : pending)
	{
		actors.emplace_back(actor);
	}
	pending.clear();
};

void Game::updateGame()
{
	float deltaTime = updateDeltaTime();

	updatingActorsCaller(this->actors, deltaTime, this->updatingActors);
	updatingPendingActorsCaller(this->actors, this->pendingActors);
	deleteDeadActors(this->actors);
};

void Game::addActor(Actor* actor)
{
	if (this->updatingActors)
	{
		this->pendingActors.emplace_back(actor);
	}
	else
	{
		this->actors.emplace_back(actor);
	}
};

void Game::addSprite(class SpriteComponent* sprite)
{
	int myDrawOrder = sprite->getDrawOrder();
	auto iter = this->sprites.begin();
	for (; iter != this->sprites.end(); ++iter)
	{
		if (myDrawOrder < (*iter)->getDrawOrder())
		{
			break;
		}
	}
	this->sprites.insert(iter, sprite);
}

static void clearOutput(SDL_Renderer *renderer)
{
	if (SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255) != 0)
	{
		SDL_Log("Failed to set renderer color: %s", SDL_GetError());
	}
	if (SDL_RenderClear(renderer) != 0)
	{
		SDL_Log("Failed to clear renderer: %s", SDL_GetError());
	}
};

static void drawSpritesCaller(std::vector<SpriteComponent*>& sprites, SDL_Renderer *renderer)
{
	for (auto sprite : sprites)
	{
		sprite->draw(renderer);
	}
};

void Game::generateOutput()
{
	clearOutput(this->renderer);

	drawSpritesCaller(this->sprites, this->renderer);

	SDL_RenderPresent(this->renderer);
};

static void find_and_pop(Actor* actor, std::vector<Actor*>& actors)
{
	auto iter = std::find(actors.begin(), actors.end(), actor);

	if (iter != actors.end())
	{
		std::iter_swap(iter, actors.end() - 1);
		actors.pop_back();
	}
};

void Game::removeActor(Actor* actor)
{
	find_and_pop(actor, this->actors);
	find_and_pop(actor, this->pendingActors);
};

void Game::shutdown()
{
	while (!this->actors.empty())
	{
		delete this->actors.back();
	}
}
