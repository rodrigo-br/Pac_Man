#ifndef ACTOR_HPP
# define ACTOR_HPP

#include "defines.hpp"

class Actor
{
/*******************************************************************************
 * 				PUBLIC MEMBERS												   *
 ******************************************************************************/
	public:
		enum State
		{
			ACTIVE,
			PAUSED,
			DEAD
		};

/*******************************************************************************
 * 				CONSTRUCTOR AND DESTRUCTOR									   *
 ******************************************************************************/
	public:
		Actor(class Game* game);
		virtual ~Actor();

		void			update(float deltaTime);
		void			updateComponents(float deltaTime);
		virtual void	updateActor(float deltaTime);

/*******************************************************************************
 * 				GETTERS AND SETTERS								 			   *
 ******************************************************************************/
	public:
		State			getState() const;
// ...

/*******************************************************************************
 * 				ADD/REMOVE COMPONENTS								 		   *
 ******************************************************************************/
	public:
		void			addComponent(class Component* component);
		void			removeComponent(class Component* component);

/*******************************************************************************
 * 				PROTECTED MEMBERS							 				   *
 ******************************************************************************/
	protected:
		State							_state;
		Vec2							_position;
		float							_scale;
		float							_rotation;
		class Game* 					_game;
		std::vector<class Component*>	_components;

};

#endif