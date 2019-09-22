#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

void flood_fill4(int,int,int,int);

void main()
{
	int gm,gd=DETECT,n,i,nc,oc;
	printf("Enter no. of sides: ");
	scanf("%d",&n);
	int x[n],y[n];
	int j=0,x_int=0,y_int=0,arr[2*n+2];
	printf("Enter the coordinates:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		arr[j++]=x[i];
		x_int+=x[i];
		arr[j++]=y[i];
		y_int+=y[i];
	}
	arr[j]=x[0];
	arr[j+1]=y[0];
	nc=5;oc=15;
	initgraph(&gm,&gd,NULL);
	//rectangle(xmin,ymin,xmax,ymax);
	fillpoly(n+1,arr);
	delay(2000);
	x_int/=n;
	y_int/=n;
	flood_fill4(x[0],y[0]+20,nc,oc);
	getch();
	closegraph();
	return;
}

void flood_fill4(int x,int y,int newcolor,int oldcolor)
{
	int current=getpixel(x,y);
	if(current==oldcolor)
	{
		putpixel(x,y,newcolor);
		flood_fill4(x+1,y,newcolor,oldcolor);
		flood_fill4(x,y-1,newcolor,oldcolor);
		flood_fill4(x-1,y,newcolor,oldcolor);
		flood_fill4(x,y+1,newcolor,oldcolor);
	}
}
	
