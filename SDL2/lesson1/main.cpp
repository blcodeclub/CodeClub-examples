#include <SDL2/SDL.h>

int main( int argc, char * argv[]) {

    //Initialise all SDL systems.
    SDL_Init(SDL_INIT_EVERYTHING);

    //get a window and renderer pointer.
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    //create the window and renderer.
    window = SDL_CreateWindow("SDL_Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //this is the background colour, and clear.
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);

    //make a rectangle to draw.
    SDL_Rect rectangle = {300, 400, 50, 50};

    //set rectangle draw colour.
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);

    //draw the rectangle to the renderer.
    SDL_RenderDrawRect(renderer, &rectangle);

    //draw the renderer to the window.
    SDL_RenderPresent(renderer);

    //wait and then quit SDL.
    SDL_Delay(5000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    //exit program.
    return 0;

}
