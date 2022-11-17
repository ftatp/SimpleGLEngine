#include <iostream>

#include "Screen.h"
#include "glad.h"

Screen* Screen::Instance()
{
    static Screen* screen = new Screen;
    return screen;
}

bool Screen::Initialize()
{
    if(SDL_Init(SDL_INIT_EVERYTHING))
    {
        std::cout << "Error Initializing SDL" << std::endl;
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    _window = SDL_CreateWindow("Graphics Engine", 
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
            1280, 720, SDL_WINDOW_OPENGL);
    
    _context = SDL_GL_CreateContext(_window);
    if(!_context)
    {
        std::cout << "Error creating SDL window" << std::endl;
        return false;
    }


    if(!gladLoadGL()){
        std::cout << "Glad loading error" << std::endl;
    }

    return true;
}

void Screen::ClearScreen()
{

    glClear(GL_COLOR_BUFFER_BIT);
}

void Screen::Present()
{
    SDL_GL_SwapWindow(_window);
}

void Screen::Shutdown()
{
    SDL_GL_DeleteContext(_context);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

Screen::Screen()
{
    _window = nullptr;
    _context = nullptr;
}
