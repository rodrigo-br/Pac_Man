#ifndef GAME_HPP
# define GAME_HPP

# include <SDL2/SDL.h>
# include <vector>
# include <utility>
# include "defines.hpp"


class Game
{
	private:

		SDL_Window					*window;
		SDL_Renderer				*renderer;
		bool						running;
		Uint32						ticksCount;
		bool						updatingActors;
		std::vector<class Actor*>	actors;
		std::vector<class Actor*>	pendingActors;

	public:

		Game();

		bool initialize();
		void runLoop();
		void shutdown();
		void addActor(class Actor* actor);
		void removeActor(class Actor* actor);

	private:

		void		processInput();
		void		updateGame();
		void		generateOutput();
};


#endif