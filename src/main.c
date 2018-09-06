#include <SDL2/SDL.h>
#include <stdio.h>

#include "engine_utils.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(void) {
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        engine_log("Could not initialize SDL2", 'e');
        fprintf(stderr, "Could not initialize SDL2: %s\n", SDL_GetError());
        return 1;
    }
    engine_log("SDL Video was initialized", 'i');

    window = SDL_CreateWindow(
      version(),
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH, SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN
    );
    engine_log("SDL Window was created", 'i');

    if(window == NULL) {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xBB, 0xFF));
    SDL_UpdateWindowSurface(window);
    engine_log("Successfully drew to window surface", 's');
    SDL_Delay(500);
    engine_log("Starting cleanup process", 'i');
    SDL_DestroyWindow(window);
    engine_log("SDL Window destroyed", 'i');
    SDL_Quit();
    engine_log("SDL quit", 's');

    return 0;
}
