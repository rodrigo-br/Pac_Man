#include "../header_files/SpriteComponent.hpp"

void SpriteComponent::setTexture(SDL_Texture* texture)
{
	this->_texture = texture;
	SDL_QueryTexture(	texture, nullptr, nullptr,
						&this->_texWidth,
						&this->_texHeight);
};

void SpriteComponent::draw(SDL_Renderer* renderer)
{
	if (this->_texture)
	{
		SDL_Rect rect;
		rect.h = static_cast<int>(this->_texHeight * this->_owner->getScale());
		rect.w = static_cast<int>(this->_texWidth * this->_owner->getScale());
		rect.x = static_cast<int>(this->_owner->getPosition().x - rect.w / 2);
		rect.y = static_cast<int>(this->_owner->getPosition().y - rect.h / 2);
	}

	SDL_RenderCopyEx(	renderer,
						this->texture,
						nullptr,
						&rect,
						-(this->_owner->getRotation() * 180.0f / M_PI),
						nullptr,
						SDL_FLIP_NONE
						);

};