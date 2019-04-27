#include <string>
#include <iostream>
#include <SDL.h>
#include <vector>
#include <random>

class Box {
    public:
        Box(int x, int y, int w, int h) {
            this->rect.x = x;
            this->rect.y = y;
            this->rect.w = w;
            this->rect.h = h;
        }
        SDL_Point velocity = { 1, 1 };
        SDL_Rect rect;
        SDL_Color colour = { 0x00, 0xff, 0x00, 0xff};

        void update() {
            this->rect.x += this->velocity.x;
            this->rect.y += this->velocity.y;

            if(this->rect.x > (1024 - this->rect.w)) {
                this->velocity.x = -this->velocity.x;
            }
            if(this->rect.x < 0) {
                this->velocity.x = -this->velocity.x;
            }
            if(this->rect.y > (768 - this->rect.h)) {
                this->velocity.y = -this->velocity.y;
            }
            if(this->rect.y < 0) {
                this->velocity.y = -this->velocity.y;
            }

        }
};

int main( int argc, char * argv[] )
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Goldthorpe Code Club Screensaver ( ͡° ͜ʖ ͡°) ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_OPENGL);

    SDL_Surface* surface = SDL_GetWindowSurface(window);

    std::vector<Box> boxes;

    for(int i = 0; i < 100; i++) {
        boxes.push_back(Box(rand() % 1024 - 15, rand() % 768 - 15, 15, 15));
        boxes.back().velocity = {(rand() % 10) - 5, (rand() % 10) - 5 };
        if(boxes.back().velocity.x == 0) { boxes.back().velocity.x = (rand() % 10) - 5; }
        boxes.back().colour = {rand() % 0xff, rand() % 0xff, rand() % 0xff, 0xff};
    }

    while(true) {
        SDL_FillRect(surface, NULL, SDL_MapRGB( surface->format, rand() % 255, 0x00, 0x00 ));
        for(int i = 0; i < 100; i++) {
            boxes[i].update();
            SDL_FillRect(surface, &boxes[i].rect, SDL_MapRGB(surface->format, boxes[i].colour.r, boxes[i].colour.g, boxes[i].colour.b));
        }

        //SDL_FillRect(surface, &box, SDL_MapRGB( surface->format, 0x00, 0xFF, 0x00 ));
        //SDL_FillRect(surface, &box2, SDL_MapRGB( surface->format, 0x00, 0x00, 0xFF ));


        SDL_UpdateWindowSurface( window );
        }
return 0;
}
