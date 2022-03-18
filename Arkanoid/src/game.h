#pragma once
#include "player.h"
#include "block.h"
#include <vector>
#include "ball.h"
using namespace std;
#define MAP_ROWS 16
#define MAP_COLLUMS 16

extern Player player;
extern Block* blocks[];
extern int screenSizeX;
extern int screenSizeY;
extern int score;
extern int scorePerBlock;
extern int maxBalls;

extern vector<Ball> balls;

void LoadMap();