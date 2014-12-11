//-------------------------------------------------------------------------//

#pragma once

#include <SFML/Graphics.hpp>

//-------------------------------------------------------------------------//

class CObject
{
public:
	CObject( );
	virtual ~CObject( );

	virtual void Update( ) { };
	void Draw( sf::RenderWindow *w_Wnd );

	sf::Sprite* s_Spr;
	sf::Rect<float> sfr;
	float x, y;
};

//-------------------------------------------------------------------------//



