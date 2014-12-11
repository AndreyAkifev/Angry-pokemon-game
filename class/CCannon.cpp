//-------------------------------------------------------------------------//

#include <SFML/Graphics.hpp>
#include <cmath>

#include "CCannon.hpp"
#include <SFML/Graphics.hpp>

//-------------------------------------------------------------------------//

CCannon::CCannon( )
{
	x = 100;
	y = 400;
}

//-------------------------------------------------------------------------//

CCannon::~CCannon( )
{

}

//-------------------------------------------------------------------------//

void CCannon::Update( )
{
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
        y += fSpeed;

    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
        y -= fSpeed;

	if( y < -10 )
		y = 800;
	if( y > 810 )
		y = 0;
}

//-------------------------------------------------------------------------//

