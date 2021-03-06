#pragma once

typedef struct pos_t 
{
  double x;
  double y;
} pos_t;

typedef struct velocity_t 
{
  double dx;
  double dy;
} vel_t;

enum piece_type_t {STRIKER, BLACK, WHITE,QUEEN};

class carrompiece_t 
{
  public: 
   // for gamestate
    pos_t pos;			// position of piece
    vel_t vel;			// velocity of piece
    piece_type_t type;	// type of piece
  
    // for renderstate
    bool is_visible;

//me
 /*   carrompiece_t operator dotpos(const carrompiece_t a)
	{
		carrompiece_t b;
		b.pos	
	}
*/
    void collision();
double distance1();
double distance2();
double distance3();
void pocketfall();
void friction();

    carrompiece_t();		//coonstructor.....i.e. default values.
};

