#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *((int *)a)-*((int *)b);
}
int main()
{
	int num[100005],temp[100005],result[100005],*p_result=result,i,j,n,latest=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",num+i);
		temp[i]=num[i];
	}
	qsort(temp,n,sizeof(int),compare);
	for(i=0;i<n;i++)
	{
		if(temp[i]==num[i])
		{
			for(j=latest+1;j<i;j++)
			{
				if(num[j]>num[i])
					break;
			}
			if(j<i)
				continue;
			*(p_result++)=num[i];
			latest=i;
		}
	}
	n=p_result-result;
	printf("%d\n",n);
	if(n==0)
	{
		printf("\n");
		return 0;
	}
	for(i=0;i<n-1;i++)
		printf("%d ",result[i]);
	printf("%d\n",result[i]);
	return 0;
}