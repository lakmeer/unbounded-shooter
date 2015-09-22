
#include <SDL2/SDL.h>


// Game

struct GameState {
  int running;
};


// Functions

void update () {

}

void draw (SDL_Renderer *renderer) {
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

SDL_Window *setup_window (int width, int height) {
  SDL_Window *screen = SDL_CreateWindow("Triangle Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
  return screen;
}

SDL_Renderer *setup_renderer (SDL_Window *screen, int width, int height) {
  SDL_Renderer *renderer = SDL_CreateRenderer(screen, -1, 0);
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
  SDL_RenderSetLogicalSize(renderer, 640, 480);
  SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
  return renderer;
}


// Main

int main(int argc, const char * argv[]) {

  // TODO: Work out which flags I actually need
  SDL_Init(SDL_INIT_EVERYTHING);

  GameState global_state;

  global_state.running = true;

  SDL_Event event;

  int screen_width = 640;
  int screen_height = 480;

  SDL_Window   *screen   = setup_window(screen_width, screen_height);
  SDL_Renderer *renderer = setup_renderer(screen, screen_width, screen_height);


  // Game Loop

  while (global_state.running) {

    // Time this frame
    const int start_time = SDL_GetTicks();

    // Handle input
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_KEYDOWN:
          if (event.key.keysym.sym == SDLK_ESCAPE) {
            global_state.running = false;
          }
          break;

        default:
          break;
      }
    }

    update();
    draw(renderer);

    const int elapsed_time = SDL_GetTicks() - start_time;

    // 60Hz
    SDL_Delay(1000/60 - elapsed_time);

    // Update everything
    //   Move Player
    //   Move Camera
    //   Spawn new ents
    //   Check collisions
    // Draw everything

  }

  SDL_Quit();

  return 0;
}

