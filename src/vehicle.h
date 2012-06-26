#ifndef VEHICLE_H
#define VEHICLE_H 1

#include "movinggameentity.h"
#include "sprite.h"

#include "SDL/SDL.h"

class Vehicle : public MovingGameEntity {
    protected:
        Sprite * m_sprite;

        GameWorld * m_world;
    public:

        Vehicle(
                GameWorld *world,
                Vector2D position,
                Vector2D velocity,
                Vector2D heading,
                double radius,
                double maxSpeed,
                double mass,
                double maxTurnRate,
                double maxForce 
                ): 
            MovingGameEntity(
                    position,
                    velocity,
                    heading,
                    radius,
                    maxSpeed,
                    mass,
                    maxTurnRate,
                    maxForce),
            m_world(world)
    { 
        m_sprite = new Sprite();
    }
        
        //Handles key presses

        void handle_input(const SDL_Event &event);
        void update(double time_elapsed);
        void render();
};


void Vehicle::handle_input(const SDL_Event &event)
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: m_velocity.y -= 1; break;
            case SDLK_DOWN: m_velocity.y += 1; break;
            case SDLK_LEFT: m_velocity.x -= 1; break;
            case SDLK_RIGHT: m_velocity.x += 1; break;
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
    }
}

void Vehicle::update(double time_elapsed)
{
    //Move the square left or right
    m_position.x += m_velocity.x;

    //If the square went too far
    if( ( m_position.x < 0 ) || ( m_position.x + 10 > m_world->width() ) )
    {
        //Move back
        m_position.x -= m_velocity.x;
    }

    //Move the square up or down
    m_position.y += m_velocity.y;

    //If the square went too far
    if( ( m_position.y < 0 ) || ( m_position.y + 10 >  m_world->height() ) )
    {
        //Move back
        m_position.y -= m_velocity.y;
    }
    m_heading = m_velocity;
    m_heading.norm();
}

void Vehicle::render()
{
    m_sprite->render(m_position, m_heading.angle());
}
#endif
