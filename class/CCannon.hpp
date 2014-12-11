//-------------------------------------------------------------------------//

#pragma once

#include "CObject.hpp"

//-------------------------------------------------------------------------//

class CCannon : public CObject
{
	const float fSpeed = 7;
public:
	CCannon( );
	~CCannon( );
	void Update( );

	const sf::RenderWindow* w_Wnd;
};

//-------------------------------------------------------------------------//
