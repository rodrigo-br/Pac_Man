#ifndef SPRITECOMPONENT_HPP
# define SPRITECOMPONENT_HPP

# include "Game.hpp"
# include "Component.hpp"

class SpriteComponent : public Component
{
	public:
		SpriteComponent(class Actor* owner, int drawOrder = 100);
		~SpriteComponent();
		virtual void draw(SDL_Renderer* renderer);
		virtual void setTexture(SDL_Texture* texture);

		int getDrawOrder() const { return this->_drawOrder; }
		int getTexWidth() const { return this->_texWidth; }
		int getTexHeight() const { return this->_texHeight; }

	protected:
		SDL_Texture*	_texture;
		int				_drawOrder;
		int				_texWidth;
		int				_texHeight;
};


#endif