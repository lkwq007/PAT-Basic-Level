#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	if(*(long *)a>*(long *)b)
		return 1;
	else if(*(long *)a<*(long *)b)
		return -1;
	else
		return 0;
}
int main()
{
	long *num,*nums;
	int n,p;
	register int i,j,max=1;
	scanf("%d%d",&n,&p);
	num=(long *)malloc(n*sizeof(long));
	nums=(long *)malloc(n*sizeof(long));
	for(i=0;i<n;i++)
	{
		scanf("%ld",num+i);
	}
	qsort(num,n,sizeof(long),compare);
	for(i=0;i<n;i++)
	{
		nums[i]=num[i]*p;
	}
	for(i=0;i<n;i++)
	{
		if(n-i<max)
			break;
		for(j=n-1;j>=i;j--)
		{
			if(j-i<max)
				break;
			if(nums[i]>=num[j])
			{
				if(max<j-i+1)
				{
					max=j-i+1;
				}
				break;
			}
		}
	}
	printf("%d\n",max);
}