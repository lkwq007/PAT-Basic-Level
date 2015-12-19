#include<stdio.h>
#include<stdlib.h>
int main()
{
	double *data,sum;
	int n,i,j;
	scanf("%d",&n);
	data=(double *)malloc(n*sizeof(double));
	for(i=0;i<n;i++)
	{
		scanf("%lf",data+i);
	}
	for(i=0;i<n;i++)
	{
		for(j=n-i;j>0;j--)
		{
			sum+=j*data[n-j];
		}
	}
	printf("%.2lf\n",sum);
}