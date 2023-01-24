#include "../header_files/AnimSpritesComponent.hpp"

void AnimeSpritesComponent::update(float deltaTime)
{
	SpriteComponent::update(deltaTime);

	if (this->_animTextures.size() > 0)
	{
		this->_currFrame += this->_animFPS * deltaTime;
		while (this->_currFrame >= this->_animTextures.size())
		{
			this->_currFrame -= this->_animTextures.size();
		}
		this->setTexture(this->_animTextures[static_cast<int>(this->_currFrame)]);
	}
};

float AnimeSpritesComponent::getAnimeFPS() const
{
	return this->_animFPS;
};

void AnimeSpritesComponent::setAnimFPS(float fps)
{
	this->_animFPS = fps;
};
