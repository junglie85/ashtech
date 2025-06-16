#include "ashtech_app.hxx"

#include <SDL3/SDL.h>

#include <iostream>

namespace ashtech
{
void do_something()
{
    std::cout << "Hello, ashtech!!!" << std::endl;

    SDL_Init(SDL_INIT_VIDEO);
}
} // namespace ashtech
