#C program to create a fully functional clock using 2D transformation

#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

void main()
{
	int gd=DETECT,gm,i,xc,yc;
	float x,y,xf,yf,xp,yp,mx,my,mx_b,my_b,hx,hy,hx_b,hy_b;
	initgraph(&gd,&gm,NULL);
	xf=320.0;
	yf=240.0;
	x=320.0; xp=x;
	y=120.0; yp=y;
	mx=320.0; mx_b=mx;
	my=140.0; my_b=my;
	hx=320.0; hx_b=hx;
	hy=180.0; hy_b=hy;
	float deg=3.14/30.0;
	float c,s;
	c=cos(deg);
	s=sin(deg);
	int sc=0,mc=0;
	while(1)
	{
		if(mc==60)
		{
			mc=0;
			hx=xf+((hx_b-xf)*c)-((hy_b-yf)*s);
                        hy=yf+((hx_b-xf)*s)+((hy_b-yf)*c);
			hx_b=hx;
			hy_b=hy;
		}
		if(sc==60)
		{
			sc=0; mc++;
			mx=xf+((mx_b-xf)*c)-((my_b-yf)*s);
			my=yf+((mx_b-xf)*s)+((my_b-yf)*c);
			mx_b=mx;
			my_b=my;
		}
		sc++;
		x=xf+((xp-xf)*c)-((yp-yf)*s);
		y=yf+((xp-xf)*s)+((yp-yf)*c);
		xp=x;
		yp=y;
		cleardevice();
		setcolor(15);
		circle(xf,yf,140);
		setcolor(4);
		line(xf,yf,hx,hy);
		setcolor(3);
		line(xf,yf,mx,my);
		setcolor(14);
		line(xf,yf,x,y);
		delay(20);
	}
	getchar();
	closegraph();
	return;
}
