#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "gamestate.h"
#include "renderstate.h"



//i included these
#include <iostream>
#include <cmath>
#include<GL/glut.h>
#define MASS1 30
#define MASS2 30
using namespace std;


//i declared
  bool flag=true;
int o=0,score=0;bool f1=true,f2=true,f3=true,f4=true,f=true,fw=true,ff=true;
//double d1,d2,d3;
//double c1,c2,c3;


extern renderstate_t g_rstate;
extern gamestate_t g_gstate;



gamestate_t::gamestate_t() 
{
  srand (time(NULL));
  double delta = rand()/(double)RAND_MAX;
  double force = (rand() % 25)+60;// (rand() % 25)+30;
  
  striker.pos.x = -0.65 + delta;
  striker.pos.y = -0.8;
  striker.type = STRIKER;
  striker.is_visible = true;
  
  delta = rand()/(double)RAND_MAX;
  coin.pos.x = 0;//delta*0.1;
  coin.pos.y = -0.26;//-1*delta*0.4;
  coin.vel.dx = 0.0;
  coin.vel.dy = 0.0;
  coin.type = QUEEN;
  coin.is_visible = true;
    
  striker.vel.dx = (coin.pos.x - striker.pos.x)/force;
  striker.vel.dy = (coin.pos.y - striker.pos.y)/force;

//me
  coin2[0].type=BLACK;
  coin2[1].type=BLACK;
  coin2[2].type=WHITE;
  coin2[3].type=WHITE;

  coin2[0].pos.x=0.07;
  coin2[0].pos.y=-0.33;

  coin2[1].pos.x=-0.07;
  coin2[1].pos.y=-0.19;

  coin2[2].pos.x=-0.07;
  coin2[2].pos.y=-0.33;

  coin2[3].pos.x=0.07;
  coin2[3].pos.y=-0.19;
/*
 		
  for(int i=1;i<COINS;i++)
  {
	coin2[i].pos.x=(delta)*0.1+0.09*i;
	coin2[i].pos.y = -1*(delta)*0.4+0.06*i;
  }
*/
}



void gamestate_t::update()
{
  // TODO: 
  // find out next position (using velocity)
  // detect collision of striker and coin (may assume perfect collision)
  // detect collision with the board, and make the coin bounce off the board
  // NOTE: After the striker has collided with the coin, set 'is_visible' of striker to false
  //      This will make the striker disappear from the board

  // Example code to move the striker
  // Begin Example (code)

/****************************************************************/
//for striker

 striker.pos.x += striker.vel.dx;
  striker.pos.y += striker.vel.dy;
//	std::cout<<abs(striker.pos.x)<<"\t"<<coin.pos.x<<"\t";
//	std::cout<<striker.pos.y<<"\t"<<coin.pos.y<<"\n";

//detecting collision between striker and board


   striker.collision();
 //  striker.pocketfall();
   striker.friction();

	if(striker.is_visible)glClearColor(1.0f,0.0f,0.0f,1.0f);
/****************************************************************/
//for coin and striker  

	for(int i=0;i<COINS;i++)
	{
		for(int j=0;j<i;j++)
		{
			piececol(&coin2[i],&coin2[j]);
		}
		piececol(&coin2[i],&striker);
		piececol(&coin2[i],&coin);
	}
	piececol(&coin,&striker);
	
/*
//collsion between striker and coin
  if(fabs(striker.pos.x-coin3.pos.x)<=0.068  && fabs(striker.pos.y-coin3.pos.y)<=0.068 && flag)
  {
	
	float tmpx=coin3.vel.dx;
	float tmpy=coin3.vel.dy;
	//std::cout<<"inside if statement\n";
	coin3.vel.dx=striker.vel.dx;
	coin3.vel.dy=striker.vel.dy;
	striker.vel.dx=tmpx;
	striker.vel.dy=tmpx;
//	flag=false;
//	striker.is_visible=false;
  }

*/
/************************************************************/

// for coin
  coin.pos.x+=coin.vel.dx;
  coin.pos.y+=coin.vel.dy;


	coin.collision();
	coin.pocketfall();
	coin.friction();
if(!coin.is_visible)glClearColor(0.0f,1.0f,0.0f,1.0f);
	for(int i=0;i<COINS;i++)
	{	
		coin2[i].pos.x+=coin2[i].vel.dx;
		coin2[i].pos.y+=coin2[i].vel.dy;


		coin2[i].collision();
		coin2[i].pocketfall();
		coin2[i].friction();

	}

	float v;
	bool flag1=true;
	for(int i=0;i<COINS;i++)
	{
		 v=sqrt(coin2[i].vel.dx*coin2[i].vel.dx+coin2[i].vel.dy*coin2[i].vel.dy);
		//cout<<v<<endl;
		if(v>0.00001)flag1=false;
	}
		 v=sqrt(coin.vel.dx*coin.vel.dx+coin.vel.dy*coin.vel.dy);
		//cout<<v<<endl;
		if(v>0.00001)flag1=false;
		 v=sqrt(striker.vel.dx*striker.vel.dx+striker.vel.dy*striker.vel.dy);
		//cout<<v<<endl<<endl;
		if(v>0.00001)flag1=false;

	if(flag1)
	{	//cout<<"i am in if"<<endl;
		cout<<endl;
		cout<<endl;	
		cout<<"*********SCORE BOARD***********"<<endl;
		
		cout<<"Turn Score: "<<o<<endl;
		cout<<"Total Score: "<<score<<endl;
		cout<<"*******************************"<<endl;		
		cout<<endl;
		
		fw=true;ff=true;
		 double delta = rand()/(double)RAND_MAX;
		  double force =  (rand() % 25)+60;
  
		  striker.pos.x = -0.65 + delta;
		  striker.pos.y = -0.8;
		  striker.type = STRIKER;
	  	striker.is_visible = true;
		if(coin.is_visible)
		{
		  striker.vel.dx = (coin.pos.x - striker.pos.x)/force;
		  striker.vel.dy = (coin.pos.y - striker.pos.y)/force;
		}
		else 
		{
			  striker.vel.dx = (0.0 - striker.pos.x)/force;
			  striker.vel.dy = (0.0 - striker.pos.y)/force;
			
		}

	}

  striker.pocketfall();


	
	
	if(!coin2[0].is_visible && f1)
	{	o+=10;
		score+=10;ff=false;
		f1=false;
	}
	if(!coin2[1].is_visible && f2)
	{	o+=10;
		ff=false;
		score+=10;f2=false;
	}
	if(!coin2[2].is_visible && f3)
	{	o+=20;ff=false;
		score+=20;f3=false;
	}
	if(!coin2[3].is_visible && f4)
	{	o+=20;ff=false;
		score+=20;f4=false;
	}
	if(!coin.is_visible && f)
	{	o+=50;ff=false;
		score+=50;f=false;
	}
	if(!striker.is_visible && fw)
	{	o+=-10;ff=false;
		score-=10;fw=false;
	}
	if(ff)o=0;
	
	
}



double masco=MASS1,masstr=MASS2;
double e=0.9;

void piececol(carrompiece_t* coin3, carrompiece_t* striker)
{
	if(sqrt(pow((*striker).pos.x+(*striker).vel.dx-(*coin3).pos.x-(*coin3).vel.dx,2)+pow((*striker).pos.y+(*striker).vel.dx-(*coin3).pos.y-(*coin3).vel.dy,2))<=0.05 || sqrt(pow((*striker).pos.x-(*coin3).pos.x,2)+pow((*striker).pos.y-(*coin3).pos.y,2))<=0.06)
  {

	float u1=sqrt((*coin3).vel.dx*(*coin3).vel.dx+(*coin3).vel.dy*(*coin3).vel.dy);
	float u2=sqrt((*striker).vel.dx*(*striker).vel.dx+(*striker).vel.dy*(*striker).vel.dy);
	float xd=(*coin3).pos.x-(*striker).pos.x;
	float yd=(*coin3).pos.y-(*striker).pos.y;
	float theta=atan(yd/xd);
	float u1pa=(*striker).vel.dx*cos(theta)+(*striker).vel.dy*sin(theta);
	float u1pe=(*striker).vel.dx*sin(theta)-(*striker).vel.dy*cos(theta);
	float u2pa=(*coin3).vel.dx*cos(theta)+(*coin3).vel.dy*sin(theta);
	float u2pe=(*coin3).vel.dx*sin(theta)-(*coin3).vel.dy*cos(theta);
	/*
	  float mag=sqrt(xd*xd+yd*yd);
	xd/=mag;yd/=mag;
	float u2pa=(-(*coin3).vel.dx*xd-(*coin3).vel.dy*yd);
	float u1pa=(+(*striker).vel.dx*xd+(*striker).vel.dy*yd);
      */	
	float v1pa=((masstr-e*masco)*u1pa/(masstr+masco))+((masco+e*masco)*u2pa/(masstr+masco));
	
	float v2pa=((masco-e*masstr)*u2pa/(masstr+masco))+((masstr+e*masstr)*u1pa/(masstr+masco));
/*	
	(*striker).vel.dx=v1pa*cos(theta);
	(*striker).vel.dy=v1pa*sin(theta);
	(*coin3).vel.dx=v2pa*cos(theta);	
	(*coin3).vel.dy=v2pa*sin(theta);
*/

	(*striker).vel.dx=v1pa*cos(theta)+u1pe*sin(theta);
	(*striker).vel.dy=v1pa*sin(theta)-u1pe*cos(theta);
	(*coin3).vel.dx=v2pa*cos(theta)+u2pe*sin(theta);
	(*coin3).vel.dy=v2pa*sin(theta)-u2pe*cos(theta);
	
	for(int i=0;i<4;i++)
	{
		(*striker).pos.x+=(*striker).vel.dx;
		(*striker).pos.y+=(*striker).vel.dy;
		(*coin3).pos.x+=(*coin3).vel.dx;
		(*coin3).pos.y+=(*coin3).vel.dy;	
	}
  }
}




void gamestate_t::render_game() 
{
  // copy gamestate to renderstate for rendering
  g_rstate.copy_state();
  g_rstate.render();  
}

void gamestate_t::loopstep() 
{
  update();
  render_game();
}


void gamestate_t::c_loopstep() {
    g_gstate.loopstep();
}


