#ifndef COMPONENT_HPP
# define COMPONENT_HPP

class Component
{
/*******************************************************************************
 * 				CONSTRUCTOR AND DESTRUCTOR									   *
 ******************************************************************************/
	public:
		Component(class Actor *owner, int updateOrder = 100);
		virtual ~Component();

/*******************************************************************************
 * 				MEMBER FUNCTIONS								 				   *
 ******************************************************************************/
		virtual void	update(float deltaTime);
		int				getUpdateOrder() const;

/*******************************************************************************
 * 				PRIVATE MEMBERS								 				   *
 ******************************************************************************/
	protected:
		class Actor*	_owner;
		int				_updateOrder;

};

#endif