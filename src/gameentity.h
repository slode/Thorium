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
class GameEntity 
{
    public:
        GameEntity ():
            m_Id(getNextValidId()),
            pos(Vector2D()),
            m_dBoundingRadius(0.0)
        {} 

        virtual ~GameEntity () {};

        virtual void update(double time_elapsed) {};

        virtual void render() {};

        virtual bool handleMessage(const Telegram &msg) { return false; }

        int ID() const { return m_Id; }

    protected:
        Vector2D pos;

        double m_dBoundingRadius;


    private:
        int m_Id;

        void getNextValidId()
        {
            static int iNextId = 0;
            return iNextId++;
        }
};



#endif
