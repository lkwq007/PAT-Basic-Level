#include<stdio.h>
#include<stdlib.h>

int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int distance[100000];
int main()
{
	int n,i,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",distance+i);
	}
	qsort(distance,n,sizeof(int),compare);
	for(i=n-1;i>=0;i--)
	{
		if(distance[i]>n-i)
		{
			max=n-i;
		}
	}
	printf("%d\n",max);
	return 0;
}