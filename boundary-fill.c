#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

void boundary_fill4(int,int,int,int);

void main()
{
	int gm,gd=DETECT,xmin,xmax,ymin,ymax,nc,ec;
	printf("Enter the coordinates:\n");
	scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
	nc=4;ec=15;
	initgraph(&gm,&gd,NULL);
	rectangle(xmin,ymin,xmax,ymax);
	delay(2000);
	boundary_fill4(xmin+20,ymin+10,nc,ec);
	getch();
	closegraph();
	return;
}

void boundary_fill4(int x,int y,int newcolor,int edgecolor)
{
	int current=getpixel(x,y);
	if(current!=newcolor && current!=edgecolor)
	{
		putpixel(x,y,newcolor);
		boundary_fill4(x+1,y,newcolor,edgecolor);
		boundary_fill4(x,y-1,newcolor,edgecolor);
		boundary_fill4(x-1,y,newcolor,edgecolor);
		boundary_fill4(x,y+1,newcolor,edgecolor);
	}
}
	
