#ifndef SPRITE_H
#define SPRITE_H 1

#include "vector2d.h"

class Sprite {
public:
    Sprite ();
    ~Sprite ();
    void render(const Vector2D  &pos, double heading);

private:
    int type;
};

Sprite::Sprite()
{}

void Sprite::render(const Vector2D &pos, double heading)
{
    glLoadIdentity();
    //Move to offset
    glTranslatef( pos.x, pos.y, 0 );

    //Start quad
    glBegin( GL_TRIANGLES );

        //Set color to white
        glColor4f( 1.0, 1.0, 1.0, 1.0 );

        //Draw triangle
        glVertex3f( 0,            5,            0 );
        glVertex3f( -5,           -5,           0 );
        glVertex3f( 5,            -5,           0 );

    //End quad
    glEnd();

    glRotatef( heading, pos.x, pos.y, 0.0 );

    //Reset
    glLoadIdentity();
}

#endif
