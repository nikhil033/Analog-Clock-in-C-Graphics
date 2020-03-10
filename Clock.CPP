#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<math.h>
#define x 3.1415

struct time t;
int i;
float sec_x, sec_y, min_x, min_y, hour_x, hour_y, h1=0, h=0, m=0, s=0;

void day(){
   setbkcolor(11);
   for(i = 130; i>=0; i--){
      cleardevice();
      setcolor(YELLOW);
      circle(580+i,70+i,50);
      setfillstyle(SOLID_FILL, YELLOW);
      floodfill(580+i, 70+i, YELLOW);
      delay(30);
      }
   }
void night(){
   for(i=100; i>0; i--){
      cleardevice();
      arc(600+i, 70, 67, 294, 50);
      arc(640+i, 70, 113, 246, 50);
      floodfill(560+i,70, WHITE);
      delay(30);
      }
   int a,b;
//you can put the stars here
   for(i=0; i<=200; i++){
      a=rand()%getmaxx();
      b=rand()%getmaxy();
      putpixel(a,b,15);
      }
   }
void alarm(){
   for(int i=0; i<5; i++){
      sound(700);
      delay(600);
      sound(300);
      delay(100);
      sound(800);
      delay(100);
      sound(460);
      delay(250);
      sound(900);
      delay(500);
      nosound();
      }
   }

void main(){
   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode,"c:\\tc\\bgi");
   gettime(&t);
   h = t.ti_hour;
   h1 = t.ti_hour;
   m = t.ti_min;
   s = t.ti_sec;
//this is code for the animating moon which appears from the west side
//If you think that the animation is not good, then we will remove it in final code

   if(h1 >= 19 || h1 < 7){
   night();
   }
   else if(h1 >= 7 || h1 < 19){
   day();
   setcolor(4);
   }
   else {;}
   if(h>=12)
   h=h-12;
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
   outtextxy(30, 25, "DEMONSTRATION OF ANIMATING CLOCK");
   circle(getmaxx()/2, getmaxy()/2,120);
   circle(getmaxx()/2, getmaxy()/2, 123);
//setfillstyle(SOLID_FILL, BLACK);
//floodfill(320, 240, WHITE);

   while(!kbhit()){
      if(h1>=19||h1<7)
	  setcolor(WHITE);
      else
	  setcolor(RED);
      settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
      outtextxy(420, 240, "3");
      outtextxy(210, 240, "9");
      outtextxy(310, 130, "12");
      outtextxy(310, 340, "6");
      sec_x= 100*cos(2*x/60*s-x/2)+getmaxx()/2;      //note that x here is 3.1415
      sec_y= 100*sin(2*x/60*s-x/2)+getmaxy()/2;
      min_x= 90*cos(2*x/60*m-x/2)+getmaxx()/2;
      min_y= 90*sin(2*x/60*m-x/2)+getmaxy()/2;
      hour_x= 60*cos(2*x/12*(h+m/60)-x/2)+getmaxx()/2;
      hour_y= 60*sin(2*x/12*(h+m/60)-x/2)+getmaxy()/2;
      setcolor(RED);
      line(getmaxx()/2, getmaxy()/2, sec_x, sec_y);
      setcolor(YELLOW);
      line(getmaxx()/2, getmaxy()/2, min_x, min_y);
      setcolor(WHITE);
      line(getmaxx()/2, getmaxy()/2, hour_x, hour_y);
      delay(1000);
      if(h1>=19||h1<7)
	  setcolor(BLACK);
      else
	  setcolor(11);
      line(getmaxx()/2, getmaxy()/2, sec_x, sec_y);
      line(getmaxx()/2, getmaxy()/2, min_x, min_y);
      line(getmaxx()/2, getmaxy()/2, hour_x, hour_y);
      s=s+1;

      if(s>=60){
	  s=0;
	  m=m+1;
	  h=h+1/60;
	  }
      }
   nosound();
   getch();
   closegraph();
}