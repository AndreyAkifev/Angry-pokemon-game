//-------------------------------------------------------------------------//

#pragma once

#include "CObject.hpp"

//-------------------------------------------------------------------------//

class CEnemy : public CObject
{
	float fSpeed;
public:
	CEnemy( float X, float Y, float fSpd );
	~CEnemy( );

	void Update( );
};

//-------------------------------------------------------------------------//


