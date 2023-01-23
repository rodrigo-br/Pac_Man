#ifndef GAME_HPP
# define GAME_HPP

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <vector>
# include <utility>
# include "defines.hpp"


class Game
{
/*******************************************************************************
 * 					PRIVATE MEMBER VARIABLES								   *
 ******************************************************************************/
	private:
		SDL_Window							*window;
		SDL_Renderer						*renderer;
		bool								running;
		Uint32								ticksCount;
		bool								updatingActors;
		std::vector<class Actor*>			actors;
		std::vector<class Actor*>			pendingActors;
		std::vector<class SpriteComponent*>	sprites;

/*******************************************************************************
 * 					CONSTRUCTOR AND DESTRUCTOR								   *
 ******************************************************************************/
	public:
		Game();

/*******************************************************************************
 * 					PUBLIC MEMBER FUNCTIONS									   *
 ******************************************************************************/
	public:
		bool initialize();
		void runLoop();
		void shutdown();
		void addActor(class Actor* actor);
		void addSprite(class SpriteComponent* sprite);
		void removeActor(class Actor* actor);


/*******************************************************************************
 * 					PRIVATE MEMBER FUNCTIONS								   *
 ******************************************************************************/
	private:
		void			processInput();
		void			updateGame();
		void			generateOutput();
		float			updateDeltaTime();
		SDL_Texture*	loadTexture(const char *fileName);
		void			loadData();
};


#endif