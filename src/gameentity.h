#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H 1

/**
 *  @file
 *  @author:  Stian Lode
 *  @date: 22-06-2012
 *  
 *  @section DESCRIPTION
 *  GameEntity serves as a basis for all game entities,
 *  both moveable and stationary, user-controlled and 
 *  autonomous.
 */

#include "telegram.h"
#include "vector2d.h"

class GameEntity 
{
    public:
        GameEntity ():
            m_id(getNextValidId()),
            m_position(Vector2D()),
            m_boundingRadius(0.0)
        {} 

        GameEntity (Vector2D pos, double rad):
            m_id(getNextValidId()),
            m_position(pos),
            m_boundingRadius(rad)
        {} 
        virtual ~GameEntity () {};

        virtual void update(double time_elapsed) {};

        virtual void render() {};

        virtual bool handleMessage(const Telegram &msg) { return false; }

        int ID() const { return m_id; }

    protected:
        Vector2D m_position;

        double m_boundingRadius;


    private:
        int m_id;

        int getNextValidId()
        {
            static int iNextId = 0;
            return iNextId++;
        }

        Vector2D getPos() const { return m_position; }
        void setPos(const Vector2D & newPos) { m_position = newPos; }

};



#endif
