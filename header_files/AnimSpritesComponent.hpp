#ifndef ANIMSPRITECOMPONENT_HPP
# define ANIMSPRITECOMPONENT_HPP

# include "SpriteComponent.hpp"

class AnimSpritesComponent : public SpriteComponent
{
	public:
		AnimSpritesComponent(class Actor* owner, int drawOrder = 100);
		~AnimSpritesComponent();

		void	update(float deltaTime) override;
		void	setAnimTextures(const std::vector<SDL_Texture*>& textures);
		float	getAnimeFPS() const;
		void	setAnimFPS(float fps);

	private:
		std::vector<SDL_Texture*>	_animTextures;
		float						_animFPS;
		float						_currFrame;

};


#endif