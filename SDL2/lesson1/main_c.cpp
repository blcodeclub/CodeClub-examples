#include <SDL2/SDL.h>
#include <vector>

class Box {
    public:
        SDL_Point velocity = {1, 0};
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

        void update() {
            if(this->rectangle.x >= (800 - this->rectangle.w) | this->rectangle.x < 0) {
                this->velocity.x = -(this->velocity.x);
                this->rectangle.x += this->velocity.x;
            }
            if(this->rectangle.y > (600 - this->rectangle.h) | this->rectangle.y < 0) {
                this->velocity.y = -(this->velocity.y);
                this->rectangle.y += this->velocity.y;
            }
            this->rectangle.x += this->velocity.x;
            this->rectangle.y += this->velocity.y;
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

    //make a Box to draw.
    std::vector<Box*> boxes;
    boxes.push_back(new Box({50,  50,  75, 75}, {1, 0}, {0x00, 0x00, 0x00, 0xff}));
    boxes.push_back(new Box({100, 100, 75, 75}, {-1, 0}, {0xff, 0x00, 0x00, 0xff}));
    boxes.push_back(new Box({150, 150, 75, 75}, {1, 0}, {0x00, 0xff, 0x00, 0xff}));
    boxes.push_back(new Box({200, 200, 75, 75}, {-1, 0}, {0xff, 0xff, 0x00, 0xff}));
    boxes.push_back(new Box({250, 250, 75, 75}, {1, 0}, {0x00, 0x00, 0xff, 0xff}));
    boxes.push_back(new Box({300, 300, 75, 75}, {-1, 0}, {0xff, 0x00, 0xff, 0xff}));
    boxes.push_back(new Box({350, 350, 75, 75}, {1, 0}, {0x00, 0xff, 0xff, 0xff}));
    boxes.push_back(new Box({400, 400, 75, 75}, {-1, 0}, {0xff, 0xff, 0xff, 0xff}));

    int i;
    SDL_Event e;

    while(true) {
        //this is the background colour, and clear.
        SDL_SetRenderDrawColor(renderer, 0x99, 0x99, 0x99, 0xff);
        SDL_RenderClear(renderer);

        for(i = 0; i < boxes.size(); i++) {
            boxes[i]->draw(renderer);
            boxes[i]->update();
        }

        //draw the renderer to the window.
        SDL_RenderPresent(renderer);
        SDL_Delay(16);

        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                boxes.clear();
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();

                return 0;
            }
        }
    }
}
