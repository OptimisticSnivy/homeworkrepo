#include<graphics.h>
#include<iostream>
#include <winbgim.h>
using namespace std;

class cohen{
	public:
	int ymax;
    int ymin;
    int xmin;
    int xmax;
    int opcodea[4],opcodeb[4],ans[4];
    public:
	cohen(int xmi,int xma,int ymi,int yma){
		opcodea[0]=0;opcodea[1]=0;opcodea[2]=0;opcodea[3]=0;
		opcodeb[0]=0;opcodeb[1]=0;opcodeb[2]=0;opcodeb[3]=0;
		xmin=xmi;
		xmax=xma;
		ymin=ymi;
		ymax=yma;
	}
	float pointa[2],pointb[2];
	public:
		void displayop(){
			cout<<opcodea[0]<<" "<<opcodea[1]<<" "<<opcodea[2]<<" "<<opcodea[3]<<endl;
			cout<<opcodeb[0]<<" "<<opcodeb[1]<<" "<<opcodeb[2]<<" "<<opcodeb[3]<<endl;
		}
		void opcodedefine(float coordinates[],int  opcode[]){
			if(coordinates[1]>ymax){
				opcode[0]=1;
			}
			if(coordinates[1]<ymin){
				opcode[1]=1;
			}
           if(coordinates[0]>xmax){
           	   opcode[2]=1;
		   }
		   if(coordinates[0]<xmin){
		   	   opcode[3]=1;
		   }
		}
		void input(){
			cout<<"Enter the coordinates:"<<endl;
			cout<<"enter x1:";cin>>pointa[0];cout<<endl;
			cout<<"enter y1:";cin>>pointa[1];cout<<endl;
			cout<<"enter x2:";cin>>pointb[0];cout<<endl;
			cout<<"enter y2:";cin>>pointb[1];cout<<endl;
			opcodedefine(pointa,opcodea);
			opcodedefine(pointb,opcodeb);
		}
		void displayline(){
			drawline(pointa[0],pointa[1],pointb[0],pointb[1]);
		}
		void step1(){
			for(int i=0;i<4;i++){
				ans[i]=opcodea[i]|opcodeb[i];
			}
		}
		void step2(){
			for(int i=0;i<4;i++){
				ans[i]=opcodea[i]&opcodeb[i];
			}
		}

		void clipping(float point[],int opc[]){
			int flag=1;
			float m=(pointb[1]-pointa[1])/(pointb[0]-pointa[0]);
			float c=pointa[1]-m*pointa[0];
			if(opc[0]==1 && flag){
				point[1]=ymax;
				point[0]=(ymax-c)/m;
				if(point[0]<=xmax && point[0]>=xmin){
					flag=0;
				}
			}
			if(opc[1]==1 && flag){
				point[1]=ymin;
				point[0]=(ymin-c)/m;
				if(point[0]<=xmax && point[0]>=xmin){
					flag=0;
				}	
			}
			if(opc[2]==1 && flag){
				point[0]=xmax;
				point[1]=xmax*m+c;
				if(point[1]<=ymax && point[1]>=ymin){
					flag=0;
				}
			}
			if(opc[3]==1 && flag){
				point[0]=xmin;
				point[1]=xmin*m+c;
				if(point[1]<=ymax && point[1]>=ymin){
					flag=0;
				}
			}
			
		}
		bool check(){
			if(ans[0]==0 && ans[1]==0 && ans[2]==0 && ans[3]==0){
				return 1;
			}
			return 0;
		}
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
		
};
int main()  
{  
    int gd = DETECT,gm;  
    char b[11]="C:\\TC\\BGI";
    initgraph(&gd, &gm,NULL); 
    cohen a(100,400,100,400);
    a.drawline(0,100,500,100);
    a.drawline(0,400,500,400);
    a.drawline(100,0,100,500);
	a.drawline(400,0,400,500);  
	a.input();
	a.step1();
	if(a.check()){
		a.displayline();
	}else{
		a.step2();
        if(a.check()){
        	a.clipping(a.pointa,a.opcodea);
        	a.clipping(a.pointb,a.opcodeb);
        	a.displayline();
		}else{
			cout<<"THE LINE IS OUTSIDE THE BOX"<<endl;
		}
	}
	a.displayop();
    delay(100000);
}  
