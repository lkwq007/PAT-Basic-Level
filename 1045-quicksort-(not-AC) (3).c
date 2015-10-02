#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int compare(const void *a,const void *b)
{
	return *((int *)a)-*((int *)b);
}
int main()
{
	int n,num[100000],i,j,sort[100000],temp[100000],result[100000],*p_result;
	scanf("%d",&n);
	p_result=result;
	for(i=0;i<n;i++)
	{
		scanf("%d",num+i);
		sort[i]=num[i];
	}
	qsort(sort,n,sizeof(int),compare);
	for(i=0;i<n;i++)
	{
		if(num[i]!=sort[i])
		{
			continue;
		}
		if(i>n/2)
		{
			memcpy(temp,num,i*sizeof(int));
			qsort(temp,i,sizeof(int),compare);
			for(j=0;j<i;j++)
			{
				if(temp[j]!=sort[j])
					goto END;
			}
		}
		else
		{
			memcpy(temp,num+i,(n-i)*sizeof(int));
			qsort(temp,n-i,sizeof(int),compare);
			for(j=i;j<n;j++)
			{
				if(temp[j]!=sort[j])
					goto END;
			}			
		}
		*(p_result)=sort[i];
		p_result++;
END:
		;
	}
	printf("%d\n",p_result-result);
	if(p_result-result>0)
		printf("%d",*result);
	for(i=1;i<p_result-result;i++)
		printf(" %d",result[i]);
	printf("\n");
}