//-------------------------------------------------------------------------//

#include "CApp.hpp"

//-------------------------------------------------------------------------//

CApp::CApp( )
{
    fSpawnTimer = 0.0f;
    iLife = 10;
    OpenWindow( );
    Run( );
}

//-------------------------------------------------------------------------//

CApp::~CApp( )
{
    for( auto it : o_Object )
        delete &( *it );
}

//-------------------------------------------------------------------------//

void CApp::OpenWindow( )
{
    char cTmp[20];
    sprintf( cTmp, "Lifes: %d", iLife );
    w_Window.create( sf::VideoMode( 800, 600 ), cTmp, sf::Style::Close );
    w_Window.setMouseCursorVisible( true );
    w_Window.setFramerateLimit( 60 );
    if( !LoadResources( ) )
        exit(1);
}

//-------------------------------------------------------------------------//

bool CApp::LoadTexture( std::string sPath )
{
    sf::Texture t_Tmp;
    if( !t_Tmp.loadFromFile( sPath.c_str( ) ) )
        return false;
    t_Texture.push_back( t_Tmp );

    sf::Sprite s_Tmp;
    s_Tmp.setTexture( t_Texture.back( ) );
    s_Sprite.push_back( s_Tmp );

    return true;
}

bool CApp::LoadResources( )
{
    t_Texture.clear( );
    s_Sprite.clear( );

    if( !LoadTexture( "cannon.png" ) )
        return false;
    if( !LoadTexture( "enemy.png" ) )
        return false;
    if( !LoadTexture( "bullet.png" ) )
        return false;
    if( !LoadTexture( "bg.jpg" ) )
        return false;

    o_Cannon.s_Spr = &( s_Sprite.front( ) );
    o_Cannon.s_Spr->setOrigin( 60, 64 );
    o_Cannon.s_Spr->setPosition( o_Cannon.x, o_Cannon.y );
    o_Cannon.w_Wnd = &w_Window;
    o_Object.push_back( &o_Cannon );

    return true;
}

//-------------------------------------------------------------------------//

void CApp::Run( )
{
    while( w_Window.isOpen( ) )
    {
        sf::Event event;
        while( w_Window.pollEvent( event ) )
        {
            switch( event.type )
            {
            case sf::Event::Closed:
            {
                w_Window.close( );
                break;
            }
            }
        }

        if( !FrameFunc( ) )
            break;
        RenderFunc( );
        w_Window.display( );
    }
}

//-------------------------------------------------------------------------//

bool CApp::FrameFunc( )
{
    if( iLife <= 0 )
    {
        w_Window.setTitle( "Game Over" );
    }
    else
    {
        fSpawnTimer += 0.1f;
        if( fSpawnTimer >= 10 )
        {
            fSpawnTimer = rand( ) % 800 / 100;
            AddEnemy( 900, 100 + rand( ) % 500, 2.5f + float( ( rand( ) % 30 ) ) / 10.0f );
        }

        for( auto it : o_Object )
        {
            it->Update( );
            if( it->x < 0 )
            {
                o_Object.remove( it );
                iLife--;
                char cTmp[20];
                sprintf( cTmp, "Lifes: %d", iLife );
                w_Window.setTitle( cTmp );
                break;
            }
            if( it->x > 950 )
            {
                o_Object.remove( it );
                break;
            }

            bool bDeleted = false;
            for( auto it2 : o_Object )
            {
                if( it->sfr.intersects( it2->sfr ) && it->sfr != it2->sfr )
                {
                    o_Object.remove( it2 );
                    bDeleted = true;
                    break;
                }
            }
            if( bDeleted )
            {
                o_Object.remove( it );
                break;
            }
        }
    }

    static float fReload = 0;

    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) && fReload <= 0 )
    {
        AddBullet( sf::Mouse::getPosition( ).x, sf::Mouse::getPosition( ).y );
        fReload = 1.5f;
    }

    fReload -= 0.1f;

    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
        return false;
    return true;
}

void CApp::AddEnemy( int x, int y, float fSpeed )
{
    CEnemy* e_Tmp = new CEnemy( x, y, fSpeed );
    e_Tmp->s_Spr = &( *( ++s_Sprite.begin( ) ) );

    o_Object.push_back( e_Tmp );
}

void CApp::AddBullet( float fDirX, float fDirY )
{
    CBullet* b_Tmp = new CBullet( o_Object.front( )->x, o_Object.front( )->y );
    b_Tmp->s_Spr = &( *( ++( ++s_Sprite.begin( ) ) ) );

    o_Object.push_back( b_Tmp );
}

//-------------------------------------------------------------------------//

void CApp::RenderFunc( )
{
    w_Window.clear();

    w_Window.draw( s_Sprite.back( ) );

    for( auto it : o_Object )
        it->Draw( &w_Window );

    o_Object.front( )->Draw( &w_Window );
}

//-------------------------------------------------------------------------//
