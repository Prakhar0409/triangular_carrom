#pragma once

#include "piece.h"
#include "renderstate.h"
#define COINS 4


class gamestate_t 
{
  public: 
    carrompiece_t striker;
    carrompiece_t coin;
    carrompiece_t coin2[COINS];
    
    gamestate_t();
    void update();
    void idle();
    void render_game();
    void loopstep();
    static void c_loopstep();
};

void piececol(carrompiece_t* coin3, carrompiece_t* striker);



