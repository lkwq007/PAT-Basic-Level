#include<stdio.h>
#include<stdlib.h>
double rope[10000];
int compare(const void *a,const void *b)
{
	return *(double *)a-*(double *)b;
}
int main()
{
	int n,i;
	double total;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",rope+i);
	}
	qsort(rope,n,sizeof(double),compare);
	total=rope[0];
	for(i=0;i<n;i++)
	{
		total+=rope[i];
		total/=2.0;
	}
	printf("%d\n",(int)total);
}