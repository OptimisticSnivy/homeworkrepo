#include<graphics.h>
#include<iostream>
#include <winbgim.h>
using namespace std;

class shapes{
	public:
		void drawline(float x,float y,float xx,float yy){
			float dx,dy;
		    dx=xx-x;
		    dy=yy-y;
		    float step;
		    if(abs(dx)>=abs(dy)){
		    	step=abs(dx);
			}else{
				step=abs(dy);
			}
			dx=dx/step;
			dy=dy/step;
			while(step){
				step--;
				putpixel(x,y,YELLOW);
				x+=dx;
				y+=dy;
			}			
		}
	void symmetry(int xc,int yc,int x,int y){
    putpixel(xc+x, yc+y, YELLOW);
    putpixel(xc-x, yc+y, YELLOW);
    putpixel(xc+x, yc-y, YELLOW);
    putpixel(xc-x, yc-y, YELLOW);
    putpixel(xc+y, yc+x, YELLOW);
    putpixel(xc-y, yc+x, YELLOW);
    putpixel(xc+y, yc-x, YELLOW);
    putpixel(xc-y, yc-x, YELLOW);
}
void circl(int xc,int yc,int r){
     int x=0;
     int y=r;
	 float dp=3-2*r;
     symmetry(xc,yc,x,y);
	 while(y>=x){
	 	x=x+1;
	 	if(dp<0){
	 		dp+=4*x+6;
		}else{
			y=y-1;
			dp+=4*(x-y)+10;
		}
		symmetry(xc,yc,x,y);
	 }	
}
};
int main()  
{  
int gdriver = 9;
int gmode = 2;
initgraph(&gdriver,&gmode, NULL);
    shapes a;
    a.circl(200,200,200);
    a.circl(200,200,100);
    a.drawline(27,300,373,300);
    a.drawline(27,300,200,0);
    a.drawline(373,300,200,0);
//    a.drawline(28,300,200,0);
//    a.drawline(375,300,200,0);
    
    delay(100000);
}  
