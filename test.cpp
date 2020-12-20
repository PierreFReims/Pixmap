#include <iostream>
#include <SDL2/SDL.h>
#include "pixmap.hpp"

const int WIN_LAR= 800;
const int WIN_HAU = 480;

int main(int argc, char ** argv)
{
    (void)argc;
    (void)argv;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow("PIXMAP TEST",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIN_LAR,WIN_HAU,SDL_WINDOW_SHOWN);
    if (window == NULL) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        return 1;
    }
    SDL_Renderer* ren = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_Texture * texture = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC,WIN_LAR,WIN_HAU);
    
    Pixmap P(640,480,0xFF0003F);
    int texture_lar, texture_hau;
    SDL_QueryTexture(texture,NULL,NULL,&texture_lar, &texture_hau);
    P.blit_on_texture_centered(texture, texture_lar, texture_hau);
    SDL_RenderCopy(ren, texture, NULL,NULL);
    SDL_RenderPresent(ren);
    bool quit = false;                                      
    SDL_Event e;                                            
    while (!quit) {                                         
        while (SDL_PollEvent(&e)) {                         
            if (e.type == SDL_QUIT) {                       
                quit = true;                                
            }                                               
        }                                                   
    } 
    // Cleanup.
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
