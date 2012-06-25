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
            id(getNextValidId()),
            pos(Vector2D()),
            boundingRadius(0.0)
        {} 

        virtual ~GameEntity () {};

        virtual void update(double time_elapsed) {};

        virtual void render() {};

        virtual bool handleMessage(const Telegram &msg) { return false; }

        int ID() const { return id; }

    protected:
        Vector2D pos;

        double boundingRadius;


    private:
        int id;

        int getNextValidId()
        {
            static int iNextId = 0;
            return iNextId++;
        }

        Vector2D getPos() const { return pos; }
        void setPos(const Vector2D & newPos) { pos = newPos; }

};



#endif
