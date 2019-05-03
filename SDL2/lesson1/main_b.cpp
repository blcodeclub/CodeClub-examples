#include <SDL2/SDL.h>

class Box {
    public:
        SDL_Point velocity = {0, 0};
        SDL_Rect rectangle = {0, 0, 1, 1};
        SDL_Color colour = { 0xff, 0xff, 0xff, 0xff };

        Box(SDL_Rect rect, SDL_Point vel, SDL_Color col) {
            this->rectangle = rect;
            this->velocity = vel;
            this->colour = col;
        }

        void draw(SDL_Renderer* ren) {
            SDL_SetRenderDrawColor(ren, this->colour.r, this->colour.g, this->colour.b, this->colour.a);
            SDL_RenderFillRect(ren, &(this->rectangle));
        }
};

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

    //make a Box to draw.
    Box box1 = Box({400, 300, 50, 50}, {0, 0}, {0xff, 0x00, 0x00, 0xff});

    box1.draw(renderer);

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
