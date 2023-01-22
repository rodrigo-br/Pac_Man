#include "../header_files/Game.hpp"

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

void deleteDeadActors(std::vector<Actor*>& actors)
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

void updatingActorsCaller(std::vector<Actor*>& actors, float deltaTime, bool &updating)
{
	updating = true;
	for (auto actor : actors)
	{
		actor->update(deltaTime);
	}
	updating = false;
};

void updatingPendingActorsCaller(std::vector<Actor*>& actors, std::vector<Actor*>&pending)
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

void find_and_pop(Actor* actor, std::vector<Actor*>& actors)
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
