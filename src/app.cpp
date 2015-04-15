#include "app.h"
#include "appconfig.h"
#include "engine/engine.h"
#include "app_state/game.h"

#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

App::App()
{
}


void App::run()
{
    //inicjalizacja SDL i utworzenie okan
    SDL_Window* m_window;

    if(SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        m_window = SDL_CreateWindow("TANKS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    AppConfig::windows_width, AppConfig::windows_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

        is_running = true;

        Engine& engine = Engine::getEngine();
        engine.initModules();

        engine.getRenderer()->loadTexture(m_window);

        m_app_state = new Game;

        //char buffer [2];
        //itoa(i%35+1, buffer, 10);
        double FPS;
        Uint32 time1, time2, dt, fps_time = 0, fps_count = 0, delay = 15;
        time1 = SDL_GetTicks();
        while(is_running)
        {
            time2 = SDL_GetTicks();
            dt = time2 - time1;
            time1 = time2;

            eventProces();

            m_app_state->draw();
            m_app_state->update(dt);

            SDL_Delay(delay);

            //FPS
            fps_time += dt; fps_count++;
            if(fps_time > 200)
            {
                FPS = (double)fps_count / fps_time * 1000;
                if(FPS > 60) delay++;
                else if(delay > 0) delay--;
                fps_time = 0; fps_count = 0;
                 //std::cout << dt << " " << FPS << " "  <<delay<< std::endl;
            }
        }

        engine.destroyModules();
    }

    SDL_DestroyWindow(m_window); m_window = nullptr;
    SDL_Quit();
}

void App::eventProces()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
        case SDL_QUIT:
            is_running = false;
         break;

       case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                is_running = false;
                break;
            }
            break;
        case SDL_WINDOWEVENT:
            switch(event.window.event)
            {
                case SDL_WINDOWEVENT_RESIZED:
                    AppConfig::windows_width = event.window.data1;
                    AppConfig::windows_height = event.window.data2;
                    Engine::getEngine().getRenderer()->setScale((float)AppConfig::windows_width / AppConfig::map_width,
                                                                (float)AppConfig::windows_height / AppConfig::map_height);
                break;
            }
            break;
        }
        m_app_state->eventProces(&event);
    }
}