#pragma once

#include "piece.h"
#include "gamestate.h"

//me
#include<GL/glut.h>
#define COINS 4

class renderstate_t 
{
  private:
    carrompiece_t p1, p2,p3[COINS];
    
    void draw_coin(carrompiece_t& piece);
    void draw_board();
//me
    void draw_text(const char* text,int length,int x,int y);    

  public:
    void render();
    void copy_state();
};

