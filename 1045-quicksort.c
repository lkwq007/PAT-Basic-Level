#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *((int *)a)-*((int *)b);
}
int main()
{
	int num[100000],temp[100000],result[100000],*p_result=result,i,j,n;
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
			*(p_result++)=i;
		}
	}
	for(i=0,j=0;i<n&&j<p_result-result;i++)
	{
		if(i<result[j]&&num[i]<num[result[j]])
			;
		else if(i>=result[j])
			j++;
		else if(num[i]>num[result[j]])
		{
			while(num[i]>num[result[j]]&&j<p_result-result)
			{
				result[j]=-1;
				j++;
			}
		}
	}
	for(i=0,n=0;i<p_result-result;i++)
	{
		if(result[i]>=0)
		{
			temp[n++]=num[result[i]];
		}
	}
	printf("%d\n",n);
	if(n==0)
	{
		printf("\n");
		return 0;
	}
	for(i=0;i<n-1;i++)
		printf("%d ",temp[i]);
	printf("%d\n",temp[i]);
	return 0;
}