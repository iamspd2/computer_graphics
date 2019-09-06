#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>

struct point{
	float x,y;
	int flag,region_code[4];
}pt[2];

float xmin,xmax,ymin,ymax;
float x1,yy1,x2,y2,xt,xb,yl,yr,x1d,y1d,x2d,y2d;

void matrix()
{
	int i,t,b,r,l;
	for(i=0;i<=1;i++)
	{
		if(pt[i].y>ymax)
			t=1;
		else
			t=0;
		if(pt[i].y<ymin)
			b=1;
		else
			b=0;
		if(pt[i].x>xmax)
			r=1;
		else
			r=0;
		if(pt[i].x<xmin)
			l=1;
		else
			l=0;
		pt[i].region_code[0]=t;
		pt[i].region_code[1]=b;
		pt[i].region_code[2]=r;
		pt[i].region_code[3]=l;
	}
}

int clip_check()
{
	int i,j,clip_flag;
	for(i=0;i<=1;i++)
	{
		pt[i].flag=0;
		for(j=0;j<=3;j++)
		{
			if(pt[i].region_code[j]!=0)
			{
				pt[i].flag=1;
				break;
			}
		}
	}
	if(pt[0].flag==1 && pt[1].flag==1)
	{
		clip_flag=1; //assuming clipping is needed
		for(i=0;i<=3;i++)
		{
			if(pt[0].region_code[i]&pt[1].region_code[i]==1)
			{
				clip_flag=0;
				break;
			}
		}
	}
	else if(pt[0].flag!=pt[1].flag)
		clip_flag=1;
	else
		clip_flag=0;
	return clip_flag;
}

void clip_line()
{
	x1=(float)pt[0].x; x1d=xmin;
	yy1=(float)pt[0].y; y1d=ymin;
	x2=(float)pt[1].x; x2d=xmax;
	y2=(float)pt[1].y; y2d=ymax;
	//if(clip_check()==1)
	//	return;
	float m=(y2-yy1)/(x2-x1);
	yl=yy1+m*(xmin-x1);
	yr=yy1+m*(xmax-x1);
	xt=x1+(ymax-yy1)/m;
	xb=x1+(ymin-yy1)/m;
//	rectangle(xmin,ymin,xmax,ymax);
	if(yl>=ymin && yl<=ymax)
		y1d=yl;
	if(yr>=ymin && yl<=ymax)
		y2d=yr;
	if(xt>=xmin && xt<=xmax)
		x1d=xt;
	if(xb>=xmin && xb<=xmax)
		x2d=xb;
	line(x1d,y1d,x2d,y2d);
}


void main()
{
	int i,j,gm,gd=DETECT;
	pt[0].x=80;
	pt[0].y=5;
	pt[1].x=300;
	pt[1].y=300;
	xmin=60;
	xmax=200;
	ymin=10;
	ymax=300;
	//printf("Enter the line coordinates:\n");
	//for(i=0;i<=1;i++)
	//	scanf("%d%d",&pt[i].x,&pt[i].y);
	//printf("Enter the clipping window coordinates:\n");
	//scanf("%d%d%d%d",&xmin,&xmax,&ymin,&ymax);
	matrix();
	initgraph(&gd,&gm,NULL);
	line(pt[0].x,pt[0].y,pt[1].x,pt[1].y);
	rectangle(xmin,ymin,xmax,ymax);
	delay(1000);
//	cleardevice();
	setcolor(5);
	clip_line();
	getch();
	closegraph();
}
