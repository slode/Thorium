#ifndef MOVING_GAME_ENTITY_H
#define MOVING_GAME_ENTITY_H 1

#include "gameentity.h"
#include "sprite.h"

class MovingGameEntity : public GameEntity
{
    protected:
        //The offsets
        Vector2D m_vPos;
        
        Vector2D m_vVel;
        
        Vector2D m_vHeading;

        Vector2D m_vPerp;


        double m_dMass;

        double m_dMaxSpeed;

        double m_dMaxForce;

        double m_dMaxTurnRate;

    public:
        //Initializes
        MovingGameEntity();

};

MovingGameEntity::MovingGameEntity() 
{ }

#endif
