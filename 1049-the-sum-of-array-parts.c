#include<stdio.h>
#include<stdlib.h>
int main()
{
	double *data,sum=0;
	int n,i,j;
	scanf("%d",&n);
	data=(double *)malloc(n*sizeof(double));
	for(i=0;i<n;i++)
	{
		scanf("%lf",data+i);
	}
	for(i=0;i<n;i++)
	{
		sum+=(n-i)*(i+1)*data[i];
	}
	printf("%.2lf\n",sum);
}