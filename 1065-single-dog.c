#include<stdio.h>
#include<stdlib.h>

int id[100001];
int single[50000];
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
	int n,i,c1,c2,offset=0,temp,partner,total;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&c1,&c2);		
		if(c1==0)
		{
			c1=100000;
		}
		if(c2==0)
		{
			c2=100000;
		}
		id[c1]=c2;
		id[c2]=c1;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(temp==0)
		{
			temp=100000;
		}
		if(id[temp]==0)
		{
			single[offset++]=temp;
		}
		else
		{
			partner=id[temp];
			id[temp]=-partner;
			if(id[partner]>0)
			{
				single[offset++]=temp;
			}
		}
	}
	total=offset;
	for(i=0;i<offset;i++)
	{
		partner=id[single[i]];
		if(partner<0)
		{
			partner=-partner;
		}
		if(id[partner]<0&&id[single[i]]<0)
		{
			single[i]=-1;
			total--;
		}
	}
	printf("%d\n",total);
	qsort(single,offset,sizeof(int),compare);
	temp=1;
	if(single[offset-1]==100000)
	{
		printf("%05d",0);
		single[offset-1]=-1;
		temp=0;
	}
	for(i=0;i<offset;i++)
	{
		if(single[i]>0)
		{
			if(temp)
			{
				printf("%05d",single[i]);
				temp=0;
			}
			else
			{
				printf(" %05d",single[i]);
			}
		}
	}
	return 0;
}