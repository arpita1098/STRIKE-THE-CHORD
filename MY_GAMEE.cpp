#include<iostream.h>    ///WRITTEN BY ARPITA & VENKAT
#include<conio.h>
#include<graphics.h>
#include<bios.h>
int p1score=0,p2score=0,board[8][8]; 
void mat()
{
   int g=0,x=40,y=50;
   settextstyle(1,0,2);
   outtextxy(145,20,"STRIKE THE CHORD");
   for(int i=0;i<8;i++)
      for(int j=0;j<8;j++)
      {
	if(g%2==0) setfillstyle(1,RED);
	else
	setfillstyle(1,YELLOW);
	bar3d(x+j*50,y+i*50,x+j*50+50,y+i*50+50,0,0);
	if(j!=7)
	g++;
      }
   setcolor(14);
   rectangle(490,20,610,450);
   outtextxy(520,30,"SCORE");
   settextstyle(2,0,0);
   outtextxy(500,110,"PLAYER 1 :");
   setcolor(BLUE);
   setfillstyle(1,BLUE);
   fillellipse(566,116,5,5);
   setcolor(YELLOW);
   outtextxy(500,150,"PLAYER 2 :");
   setfillstyle(1,WHITE);
   setcolor(WHITE);
   fillellipse(566,156,5,5);
 }
   int win()
   {
     int i,j;
     for(i=0;i<8;i++)
       for(j=0;j<8;j++)
	 if(board[i][j]==0)
	      return 0;
     return 1;
   }
    void changeplayer(int &cp)
    {
       if(cp==1)
	  cp=2;
       else
	  cp=1;
    }
   void chkgrp(int cx, int cy,int cp)
   {
     int w=50,y=50,x=40;
     int k=(cy-y)/w,m=(cx-x)/w;
      if(board[k][m]==2)
      {  if((board[k+1][m]==1)&&(board[k+2][m]==2))
	  line(cx,cy,cx,cy+2*w);
	 if((board[k-1][m]==1)&&(board[k-2][m]==2))
	   line(cx,cy,cx,cy-2*w);
	 if((board[k][m+1]==1)&&(board[k][m+2]==2))
	   line(cx,cy,cx+2*w,cy);
	 if((board[k][m-1]==1)&&(board[k][m-2]==2))
	   line(cx,cy,cx-2*w,cy);
	 if((board[k-1][m+1]==1)&&(board[k-2][m+2]==2))
	   line(cx,cy,cx+2*w,cy-2*w);
	 if((board[k-1][m-1]==1)&&(board[k-2][m-2]==2))
	   line(cx,cy,cx-2*w,cy-2*w);
	 if((board[k+1][m+1]==1)&&(board[k+2][m+2]==2))
	   line(cx,cy,cx+2*w,cy+2*w);
	 if((board[k+1][m-1]==1)&&(board[k+2][m-2]==2))
	   line(cx,cy,cx-2*w,cy+2*w);
      }
      else if (board[k][m]==1)
      {
	if((board[k-1][m]==2)&&(board[k+1][m]==2))
	   line(cx,cy,cx,cy-w);
	   line(cx,cy,cx,cy+w);
	if((board[k][m-1]==2)&&(board[k][m+1]==2))
	   line(cx,cy,cx-w,cy);
	   line(cx,cy,cx+w,cy);
	if((board[k-1][m-1]==2)&&(board[k+1][m+1]==2))
	   line(cx,cy,cx-w,cy-w);
	   line(cx,cy,cx+w,cy+w);
	if((board[k-1][m+1]==2)&&(board[k+1][m-1]==2))
	   line(cx,cy,cx+w,cy-w);
	   line(cx,cy,cx-w,cy+w);
     }
   }

   void main()
  {
     int gd=DETECT,gm;
     initgraph(&gd,&gm,"c:\\bgi");
     mat();
     int cr=0,cc=0,x=40,y=50,cx,cy,w=50,cp=1,key,i,j;
     cx=40,cy=50;
     for(i=0;i<8;i++)
       for(j=0;j<8;j++)
	 board[i][j]=0;
      setcolor(GREEN);
    rectangle(cx,cy,cx+w,cy+w);
    while(!win()&&(key=bioskey(0))!=283)
   {
       switch(key)//up-18432 down-20480 left-19200 right-19712 w-4471 b-12386
      {
	case 18432://up
		   setcolor(15);
		   rectangle(cx,cy,cx+w,cy+w);
		   if(cy>y)
		      cy-=w;
		   setcolor(GREEN);
		   rectangle(cx,cy,cx+w,cy+w);
		   break;
	case 20480://down
		    setcolor(15);
		    rectangle(cx,cy,cx+w,cy+w);
		    if(cy!=y+7*w)
		       cy+=w;
		    setcolor(GREEN);
		    rectangle(cx,cy,cx+w,cy+w);
		    break;
	case 19200://left
		    setcolor(15);
		    rectangle(cx,cy,cx+w,cy+w);
		    if(cx>x)
		       cx-=w;
		    setcolor(GREEN);
		    rectangle(cx,cy,cx+w,cy+w);
		    break;
       case 19712://right
		   setcolor(15);
		   rectangle(cx,cy,cx+w,cy+w);
		   if(cx!=x+7*w)
			cx+=w;
		   setcolor(GREEN);
		   rectangle(cx,cy,cx+w,cy+w);
		   break;
       case 4471://w
		  if(board[(cy-y)/w][(cx-x)/w]!=0)break;
		  board[(cy-y)/w][(cx-x)/w]=2;
		  setfillstyle(1,15);
		  fillellipse(cx+w/2,cy+w/2,w/4,w/4);
		  chkgrp(cx,cy);
		  changeplayer(cp);
		  break;
       case 12386://b
		 if(board[(cy-y)/w][(cx-x)/w]!=0)break;
		 board[(cy-y)/w][(cx-x)/w]=1;
		 setfillstyle(1,1);
		 fillellipse(cx+w/2,cy+w/2,w/4,w/4);
		 chkgrp(cx,cy);
		 changeplayer(cp);
		 break;
     }
  }
     //getch();
}
