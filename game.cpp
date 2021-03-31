#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include "ent_player.cpp"
#include "ent_wall.cpp"
#include "entity.h"
#include <iostream>
#include <vector>
#include <memory>

class Game
{
    private:

    SDL_Event event;
    SDL_Joystick *joystick;
    #define BUTTONNUM 20
    bool controller[BUTTONNUM];

    std::vector<std::unique_ptr<Entity> > entList;

    public:

    void init()
    {
        controllerInit();
        entList.push_back( std::unique_ptr<Entity>(new EntPlayer()));
        entList.at(0)->init(32,32);
        entList.push_back( std::unique_ptr<Entity>(new EntWall()));
        entList.at(1)->init(64,64);

    }

    void update()
    {
        controllerUpdate();

        bool *ctrlPointer;
        ctrlPointer = controller;

        for (unsigned int i = 0; i < entList.size(); i++)
        {
            entList.at(i)->update(ctrlPointer);
        }

        for (unsigned int i = 0; i < entList.size(); i++)
        {
            entList.at(i)->draw();
        }

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
                case SDL_JOYBUTTONDOWN:
                    controller[event.jbutton.button+4] = 1;
                break;
                case SDL_JOYBUTTONUP:
                    controller[event.jbutton.button+4] = 0;
                break;
                case SDL_JOYHATMOTION:
                    for (int i = 0; i < 4; i++)
                    {
                        int b = 1 << i;
                        int value = event.jhat.value & b;
                        controller[i] = value;
                    }
                break;
            }
        }
    }
};
