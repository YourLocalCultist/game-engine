#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include "entity.cpp"

class Game
{
    private:

    //int x = 2;
    //int y = 2;

    SDL_Event event;
    SDL_Joystick *joystick;
    #define BUTTONNUM 16
    bool controller[BUTTONNUM];

    Entity player;

    public:

    void init()
    {
        controllerInit();
        player.init(32,32);
    }

    void update()
    {
        controllerUpdate();

        player.update(controller);
        player.draw();

        /*x = int(rand() % 8);
        y = int(rand() % 8);

        glColor3f(1,1,1);
        glPointSize(10);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();

        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(4,4);
        glVertex2i(0,4);
        glVertex2i(0,0);
        glVertex2i(4,0);
        glEnd();*/


    }

    void controllerInit()
    {
        if (SDL_Init( SDL_INIT_JOYSTICK ) < 0)
        {
            fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
            exit(1);
        }

        SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS,"1");

        printf("%i joysticks were found.\n\n", SDL_NumJoysticks() );
        printf("The names of the joysticks are:\n");

        for(int i=0; i < SDL_NumJoysticks(); i++ )
        {
            printf("    %s\n", SDL_JoystickName(SDL_JoystickOpen(i)));
        }
        SDL_JoystickEventState(SDL_ENABLE);
        joystick = SDL_JoystickOpen(0);

        for (int i = 0; i <= BUTTONNUM; i++)
        {
            controller[i] = 0;
        }
    }

    void controllerUpdate()
    {
        SDL_JoystickUpdate();
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                    printf("eeee");
                break;
                case SDL_JOYBUTTONDOWN:
                    controller[event.jbutton.button] = 1;
                    //printf("button pressed: %d\n", event.jbutton.button);
                    for (int i = 0; i <= BUTTONNUM; i++)
                    {
                        printf("%d", controller[i]);
                    }
                    printf("\n");
                break;
                case SDL_JOYBUTTONUP:
                    controller[event.jbutton.button] = 0;
                    //printf("button released: %d\n", event.jbutton.button);
                    for (int i = 0; i <= BUTTONNUM; i++)
                    {
                        printf("%d", controller[i]);
                    }
                    printf("\n");
                break;
            }
        }
    }

};
