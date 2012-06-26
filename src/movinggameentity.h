#ifndef MOVING_GAME_ENTITY_H
#define MOVING_GAME_ENTITY_H 1

#include "gameentity.h"
#include "sprite.h"

class MovingGameEntity : public GameEntity
{
    protected:
        //The offsets
        Vector2D m_velocity;

        Vector2D m_heading;

        Vector2D m_perpVect;


        double m_mass;

        double m_maxSpeed;

        double m_maxForce;

        double m_maxTurnRate;

    public:
        //Initializes
        MovingGameEntity(
                Vector2D position,
                Vector2D velocity,
                Vector2D heading,
                double radius,
                double maxSpeed,
                double mass,
                double maxTurnRate,
                double maxForce 
                ): 
            GameEntity(position, radius),
            m_velocity(velocity),
            m_heading(heading),
            m_maxSpeed(maxSpeed),
            m_maxTurnRate(maxTurnRate),
            m_maxForce(maxForce),
            m_perpVect(heading.perp())
    { }

        inline void        setVelocity(const Vector2D& NewVel){m_velocity = NewVel;}
        inline void        setMaxSpeed(double new_speed){ m_maxSpeed = new_speed; }
        inline void        setMaxForce(double mf){ m_maxForce = mf; }
        inline void        setHeading(Vector2D new_heading) {m_heading = new_heading; m_perpVect = m_heading.perp();};
        inline void        setMaxTurnRate(double val){m_maxTurnRate = val;}

        inline Vector2D    velocity() const { return m_velocity; }
        inline Vector2D    heading() const { return m_heading; }
        inline Vector2D    side() const { return m_perpVect; }
        inline double      mass() const { return m_mass; }
        inline double      maxSpeed() const { return m_maxSpeed; }                       
        inline double      maxForce() const { return m_maxForce; }
        inline double      speed() { return m_velocity.length(); }
        inline double      speedSq() {return m_velocity.lengthSq();}
        inline double      maxTurnRate() { return m_maxTurnRate;}

        bool        isSpeedMaxedOut() { return m_maxSpeed*m_maxSpeed >= m_velocity.lengthSq(); }
        bool        rotateHeadingToFacePosition(Vector2D const &target);
};

bool MovingGameEntity::rotateHeadingToFacePosition(Vector2D const &target)
{
    Vector2D targetVector = target - m_position; 
    return false;
    
}
#endif
