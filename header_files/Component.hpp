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
 * 				MEMBER FUNCTIONS							 				   *
 ******************************************************************************/
	public:
		virtual void	update(float deltaTime);
		int				getUpdateOrder() const;

/*******************************************************************************
 * 				PROTECTED MEMBERS							 				   *
 ******************************************************************************/
	protected:
		class Actor*	_owner;
		int				_updateOrder;
};

#endif