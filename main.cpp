#include "TileMap.h"
#include "Game.h"

int main()
{
    Game game;

    // Game Loop
    while (game.running())
    {
        // Update
        game.update();
        // Render
        game.render();

    }

    return 0;
}