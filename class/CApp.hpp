//-------------------------------------------------------------------------//

#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <string>

#include "CObject.hpp"
#include "CCannon.hpp"
#include "CBullet.hpp"
#include "CEnemy.hpp"

//-------------------------------------------------------------------------//

class CApp
{
public:
    CApp( );
    ~CApp( );

private:
	void Run( ); // main game cycle is here
    void OpenWindow( );

    bool LoadResources( );
    bool LoadTexture( std::string sPath );

    bool FrameFunc( ); // app halts when false returned
    void RenderFunc( );

    void AddEnemy( int x, int y, float fSpeed );
    void AddBullet( float fDirX, float fDirY );

	//-----------------------------------------//

	float fSpawnTimer;
	int iLife;

    sf::RenderWindow w_Window;
    std::list< sf::Texture > t_Texture;
	std::list< sf::Sprite > s_Sprite;

    std::list< CObject* > o_Object;

    CCannon o_Cannon;
};

//-------------------------------------------------------------------------//
