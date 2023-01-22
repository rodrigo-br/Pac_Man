#include "../header_files/defines.hpp"

int main(void)
{
	Game game;
	if (game.initialize())
	{
		game.runLoop();
	}
	game.shutdown();
	return 0;
}