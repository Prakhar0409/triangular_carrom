#include "piece.h"
#include<bits/stdc++.h>
using namespace std;

carrompiece_t::carrompiece_t()
{
  pos.x = 5.0;
  pos.y = 5.0;
  vel.dx = 0.0;
  vel.dy = 0.0;
  type = WHITE;
  is_visible = true;
}

void carrompiece_t::collision()
{
  double d1,d2,d3;
  d1=distance1();
   d2=distance2();
   d3=distance3();

 if(d1<=0.06)
{            

	//std::cout<<"I am in if 1\n";
	float m1;
	if(fabs(vel.dx)<0.0000000001 && fabs(vel.dy)>0.00000000001)m1=-0.57735;	
	else m1=vel.dy/vel.dx;


	float m0=-1.732;
	float m2=(m0*(2+(m1*m0))-m1)/(m0*(2*m1-m0)+1);
	if(vel.dx<=0&&vel.dy>=0)
	{
	//	std::cout<<"case 1:"<<m2<<"\t"<<m1<<endl;
		vel.dx=-sqrt((vel.dx*vel.dx+vel.dy*vel.dy)/(m2*m2+1));
		vel.dy=vel.dx*m2;
	} 
	else if(m1>=1.732)
	{
	//	std::cout<<"case 2:"<<m2<<"\t"<<m1<<endl;
		vel.dx=-sqrt((vel.dx*vel.dx+vel.dy*vel.dy)/(m2*m2+1));
		vel.dy=vel.dx*m2;
	}
	else if(m1>0 )
	{
	//	std::cout<<"case 3:"<<m2<<"\t"<<m1<<endl;
		vel.dx=-sqrt((vel.dx*vel.dx+vel.dy*vel.dy)/(m2*m2+1));
		vel.dy=vel.dx*m2;
	}
	else if(m1<0 &&m1>-0.57730)
	{	
	//	std::cout<<"case 4:"<<m2<<"\t"<<m1<<endl;
		vel.dx=-sqrt((vel.dx*vel.dx+vel.dy*vel.dy)/(m2*m2+1));
		vel.dy=vel.dx*m2;	
	}
	else if(m1<=-0.57730 && m1>=-0.57740){
	//	std::cout<<"case 5:"<<m2<<"\t"<<m1<<endl;
		vel.dy=-sqrt(vel.dx*vel.dx+vel.dy*vel.dy);
		vel.dx=0.0;
	}
	else if(m1<=-0.57740)
	{
	//	std::cout<<"case 6:"<<m2<<"\t"<<m1<<endl;
		vel.dx=sqrt((vel.dx*vel.dx+vel.dy*vel.dy)/(m2*m2+1));
		vel.dy=vel.dx*m2;	
	}

//	vel.dx=-sqrt((vel.dx*vel.dx+vel.dy*vel.dy)/(m2*m2+1));
//	vel.dy=vel.dx*m2;
	friction();
}


  if(d2<=0.06)
  {            
	//std::cout<<"I am in if 2\n";
	float m1;
	if(fabs(vel.dx)<0.0000000001 && fabs(vel.dy)>0.00000000001)m1=-0.57735;	
	else m1=vel.dy/vel.dx;
	float m0=1.732;
	float m2=(m0*(2+(m1*m0))-m1)/(m0*(2*m1-m0)+1);
	if(vel.dx>=0&&vel.dy>=0)
	{
	//	std::cout<<"case 1:"<<m2<<"\t"<<m1<<endl;
		vel.dx=sqrt((vel.dx*vel.dx+vel.dy*vel.dy)/(m2*m2+1));
		vel.dy=vel.dx*m2;
	} 
	else if(m1<-1.732)
	{
	//	std::cout<<"case 2:"<<m2<<"\t"<<m1<<endl;
		vel.dx=sqrt((vel.dx*vel.dx+vel.dy*vel.dy)/(m2*m2+1));
		vel.dy=vel.dx*m2;
	}
	else if(m1<=0 )
	{
	//	std::cout<<"case 3:"<<m2<<"\t"<<m1<<endl;
		vel.dx=sqrt((vel.dx*vel.dx+vel.dy*vel.dy)/(m2*m2+1));
		vel.dy=vel.dx*m2;
	}
	else if(m1>0 &&m1<0.57730)
	{	
	//	std::cout<<"case 4:"<<m2<<"\t"<<m1<<endl;
		vel.dx=sqrt((vel.dx*vel.dx+vel.dy*vel.dy)/(m2*m2+1));
		vel.dy=vel.dx*m2;	
	}
	else if(m1>=0.57730 && m1<=0.57740){
	//	std::cout<<"case 5:"<<m2<<"\t"<<m1<<endl;
		vel.dy=-sqrt(vel.dx*vel.dx+vel.dy*vel.dy);
		vel.dx=0.0;
	}
	else if(m1>0.57740)
	{
	//	std::cout<<"case 6:"<<m2<<"\t"<<m1<<endl;
		vel.dx=-sqrt((vel.dx*vel.dx+vel.dy*vel.dy)/(m2*m2+1));
		vel.dy=vel.dx*m2;
	
	}
//	vel.dx=sqrt((vel.dx*vel.dx+vel.dy*vel.dy)/(m2*m2+1));
//	vel.dy=vel.dx*m2;
	friction();	
  }
  
  if(d3<=0.09)
  {            
	//std::cout<<"I am in if 3\n";
	vel.dy=-vel.dy;
	pos.y+=vel.dy;	
	
	
  }
}


double carrompiece_t::distance1()
{
  return -1*((pos.y+vel.dy+1.0)+((1.732)*(pos.x+vel.dx-1.0)))/1.999956;
}

double carrompiece_t::distance2()
{
   return (-1*(pos.y+vel.dy+1.0)+((1.732)*(pos.x+vel.dx+1.0)))/1.999956;
}

double carrompiece_t::distance3()
{
   return pos.y+1;
}





// detecting if striker falls in pocket
void carrompiece_t::pocketfall()
{
  double c1,c2,c3;
  c1=sqrt((pos.x)*(pos.x)+(pos.y-0.607)*(pos.y-0.607));
  c2=sqrt((pos.x-0.875)*(pos.x-0.875)+(pos.y+0.905)*(pos.y+0.905));
  c3=sqrt((pos.x+0.875)*(pos.x+0.875)+(pos.y+0.905)*(pos.y+0.905));
 
  //std::cout<<d1<<"\t"<<d2<<"\t"<<d3<<"\n";
  if(c1<=0.04 || c2<=0.04 || c3<=0.04)
  {
  	is_visible=false;
	vel.dx=0.0;
	vel.dy=0.0;
	pos.x= 1;
	pos.y= 1;
  } 

}
// end of striker falling in pocket




// frictional damping
void carrompiece_t::friction()
{
//	vel.dx=vel.dx/0.995;
//	vel.dy=vel.dy/0.995;
 float v=sqrt((vel.dx*vel.dx)+(vel.dy*vel.dy));
  if(fabs(vel.dx)>0.0 )
 {
 	 vel.dx-=0.00001*vel.dx/v;
  }
  if(fabs(vel.dy)>0.0)
  { 
	 vel.dy-=0.000010*vel.dy/v; 
 }

 if(fabs(vel.dx)<0.0000000001 )vel.dx=0.0;
 if(fabs(vel.dy)<0.0000000001 )vel.dy=0.0;
}



