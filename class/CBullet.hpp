//-------------------------------------------------------------------------//

#pragma once

#include <SFML/Graphics.hpp>

#include "CObject.hpp"

//-------------------------------------------------------------------------//

class CBullet : public CObject
{
	const float fSpeed = 10;
	float fAngle;
public:
	CBullet( float X, float Y );
	~CBullet( );

	void Update( );
};

//-------------------------------------------------------------------------//

