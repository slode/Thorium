#ifndef VEHICLE_H
#define VEHICLE_H 1

#include "movinggameentity.h"
#include "sprite.h"

#include "SDL/SDL.h"

class Vehicle : public MovingGameEntity {
    private:
        Sprite * m_sSprite;

        GameWorld * m_gWorld;
    public:
        Vehicle(GameWorld * wrld);
        //Handles key presses

        void handle_input(const SDL_Event &event);
        void update();
        void render();
};

Vehicle::Vehicle(GameWorld * wrld)
    :m_gWorld(wrld)
{
    m_sSprite = new Sprite();
}

void Vehicle::handle_input(const SDL_Event &event)
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: m_vVel.y -= 1; break;
            case SDLK_DOWN: m_vVel.y += 1; break;
            case SDLK_LEFT: m_vVel.x -= 1; break;
            case SDLK_RIGHT: m_vVel.x += 1; break;
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
    }
}

void Vehicle::update()
{
    //Move the square left or right
    m_vPos.x += m_vVel.x;

    //If the square went too far
    if( ( m_vPos.x < 0 ) || ( m_vPos.x + 10 > m_gWorld->width() ) )
    {
        //Move back
        m_vPos.x -= m_vVel.x;
    }

    //Move the square up or down
    m_vPos.y += m_vVel.y;

    //If the square went too far
    if( ( m_vPos.y < 0 ) || ( m_vPos.y + 10 >  m_gWorld->height() ) )
    {
        //Move back
        m_vPos.y -= m_vVel.y;
    }
    m_vHeading = m_vVel;
    m_vHeading.normalize();
}

void Vehicle::render()
{
    m_sSprite->render(m_vPos, m_vHeading.angle());
}
#endif
