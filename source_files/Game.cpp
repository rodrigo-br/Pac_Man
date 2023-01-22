#include "../header_files/Game.hpp"

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