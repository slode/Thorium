/**
 *  @file
 *  @author:  Stian Lode
 *  @date: 22-06-2012
 *  
 *  @section DESCRIPTION
 *  Basic sandbox environment for testing game implementation concepts.
 */

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "timer.h"
#include "gameworld.h"
#include "vehicle.h"

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 60;

//The attributes of the square
const int SQUARE_WIDTH = 1;
const int SQUARE_HEIGHT = 1;

//Event handler
SDL_Event event;

//The timer

bool init_GL()
{
    //Set clear color
    glClearColor( 0, 0, 0, 0 );

    //Set projection
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, -1, 1 );

    //Initialize modelview matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //If there was any errors
    if( glGetError() != GL_NO_ERROR )
    {
        return false;
    }

    //If everything initialized
    return true;
}

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        return false;
    }

    //Create Window
    if( SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_OPENGL ) == NULL )
    {
        return false;
    }

    //Initialize OpenGL
    if( init_GL() == false )
    {
        return false;
    }

    //Set caption
    SDL_WM_SetCaption( "OpenGL Test", NULL );

    return true;
}

void clean_up()
{
    //Quit SDL
    SDL_Quit();
}


#undef main
int main( int argc, char *argv[] )
{
    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    GameWorld gw(SCREEN_HEIGHT, SCREEN_WIDTH);
    //Our square object
    Vehicle player(
            &gw,
            Vector2D(50, 50),
            Vector2D(1,1),
            Vector2D(1,1),
            2.0,
            2.0,
            2.0,
            2.0,
            2.0
            );
    //The frame rate regulator
    Timer fps;

	//Wait for user exit
	while( quit == false )
	{
        //Start the frame timer
        fps.start();

        //While there are events to handle
		while( SDL_PollEvent( &event ) )
		{
            //Handle key presses
            player.handle_input(event);

			if( event.type == SDL_QUIT )
			{
                quit = true;
            }
		}

	    //Move the square
	    player.update(0.0);

	    //Clear the screen
	    glClear( GL_COLOR_BUFFER_BIT );


	    //Show the square
	    player.render();

	    //Update screen
	    SDL_GL_SwapBuffers();

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
	}

	//Clean up
	clean_up();

	return 0;
}
