#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point{
	int x,y,flag;
	int region_code[4];
}pt[2];

int xmin,xmax,ymin,ymax;

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
	if(clip_check()==1)
		return;
	float m=(y2-y1)/(x2-x1);



void main()
{
	int i,j;
	printf("Enter the line coordinates:\n");
	for(i=0;i<=1;i++)
		scanf("%d%d",&pt[i].x,&pt[i].y);
	printf("Enter the clipping window coordinates:\n");
	scanf("%d%d%d%d",&xmin,&xmax,&ymin,&ymax);
	matrix();
	printf("\nRegions:\n");
	for(i=0;i<=1;i++)
	{
		for(j=0;j<=3;j++)
			printf("%d ",pt[i].region_code[j]);
		printf("\n");
	}
}

