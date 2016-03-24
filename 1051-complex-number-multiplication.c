#include<stdio.h>
#include<math.h>
#include<float.h>
int main()
{
	double r1,p1,r2,p2;
	scanf("%lf%lf%lf%lf",&r1,&p1,&r2,&p2);
	if(r1*r2*cos(p1+p2)>-1e-2)
	{
		printf("%.2lf",fabs(r1*r2*cos(p1+p2)));
	}
	else
	{
		printf("-%.2lf",fabs(r1*r2*cos(p1+p2)));
	}
	if(r1*r2*sin(p1+p2)>-1e-2)
	{
		printf("+%.2lfi\n",fabs(r1*r2*sin(p1+p2)));
	}
	else
	{
		printf("-%.2lfi\n",fabs(r1*r2*sin(p1+p2)));
	}
}