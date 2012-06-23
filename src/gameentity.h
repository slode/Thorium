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
        GameEntity () 
        {
        }
        virtual ~GameEntity () {};

        virtual void update()=0;

        int ID() const { return m_Id; }

    private:
        int m_Id;

        static int m_iNextValidId;

        void setId(int id)
        {
            if (id >= m_iNextValidId) {
                m_Id = id;
                m_iNextValidId = id+1;
            }
        }
};



#endif
