#include <SDL.h>
#include <iostream>
#include <vector>

// Define the grid size and tile size
const int TILE_SIZE = 40;
const int GRID_WIDTH = 10;
const int GRID_HEIGHT = 10;

// Window and renderer
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

// Initialize SDL
bool init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("sokoban", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              GRID_WIDTH * TILE_SIZE, GRID_HEIGHT * TILE_SIZE, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

// Close SDL resources
void close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// Entity class to represent player, boxes, and storage points
struct Entity {
    int x, y;
    SDL_Color color;

    Entity(int x, int y, SDL_Color color) : x(x), y(y), color(color) {}

    void render() const {
        SDL_Rect rect = {x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, &rect);
    }
};

// Game entities (player, boxes, and storage points)
std::vector<Entity> entities;

// Handle keyboard input
void handle_input(SDL_Event& e, bool& quit) {
    if (e.type == SDL_QUIT) {
        quit = true;
    }

    if (e.type == SDL_KEYDOWN) {
        // Move the player based on arrow keys
        switch (e.key.keysym.sym) {
            case SDLK_UP:
                // Check if player can move up (empty space or box to move)
                break;
            case SDLK_DOWN:
                // Check if player can move down
                break;
            case SDLK_LEFT:
                // Check if player can move left
                break;
            case SDLK_RIGHT:
                // Check if player can move right
                break;
            case SDLK_z:
                // Undo last move (you can implement a stack of game states for undo functionality)
                break;
            case SDLK_r:
                // Reset game to initial state
                break;
            default:
                break;
        }
    }
}

// Update the game state (e.g., check win conditions)
void update_game() {
    // For now, we have no game logic, but you could check player movement, win conditions, etc.
}

// Render game entities (player, boxes, storage points)
void render_game() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black background
    SDL_RenderClear(renderer);

    // Render all entities (e.g., player, boxes, storage points)
    for (const auto& entity : entities) {
        entity.render();
    }

    SDL_RenderPresent(renderer);  // Present the rendered frame
}

int main() {  // Removed unused parameters
    if (!init()) {
        std::cerr << "Failed to initialize SDL!" << std::endl;
        return 1;
    }

    bool quit = false;
    SDL_Event e;

    // Initialize the game entities (player, box, and storage points)
    entities.push_back(Entity(2, 2, {255, 0, 0, 255}));  // Red player
    entities.push_back(Entity(4, 4, {0, 255, 0, 255}));  // Green box
    entities.push_back(Entity(6, 6, {0, 0, 255, 255}));  // Blue storage

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            handle_input(e, quit);
        }

        update_game();
        render_game();
    }

    close();
    return 0;
}
