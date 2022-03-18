#include "player.h"
#include "block.h"
#include "game.h"
#include "ball.h"

Player player;
Block* blocks[MAP_ROWS * MAP_COLLUMS];

int screenSizeX = 1280;
int screenSizeY = 720;
int score = 0;
int scorePerBlock = 100;
int maxBalls = 5;

vector<Ball> balls;

const char* LEVEL =
"................"
"................"
"................"
"................"
"................"
"................"
"################"
"#....#....#....#"
"#....#....#....#"
"#..............#"
"#..............#"
"................"
"................"
"................"
"................"
"................";

void LoadMap()
{
    Ball ball;
    ball.posX = player.posX + (player.sizeX / 2);
    ball.posY = player.posY - ball.circle.radius;
    balls.push_back(ball);

    for (int y = 0; y < MAP_ROWS; ++y)
    {
        for (int x = 0; x < MAP_COLLUMS; ++x, ++LEVEL)
        {
            if (*LEVEL != '#')
                continue;

            Block* block = new Block();
            block->posX = x * block->sizeX;
            block->posY = y * block->sizeY;

            blocks[y * MAP_COLLUMS + x] = block;
        }
    }
}