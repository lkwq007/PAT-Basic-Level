#include<stdio.h>

int main()
{
	int n,i,temp,num,count[101],total=0;
	scanf("%d",&n);
	for(i=0;i<101;i++)
		count[i]=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		count[num]++;
	}
	for(i=2;i<101;i++)
	{
		if(count[i]!=0)
		{
			temp=i;
			while(temp>1)
			{
				if(temp%2)
				{
					temp=temp*3+1;
					temp/=2;
					if(temp<=100&&temp>1)
						count[temp]=0;
				}
				else
				{
					temp/=2;
					if(temp<=100&&temp>1)
						count[temp]=0;
				}
			}
		}
	}
	temp=0;
	for(i=100;i>1;i--)
	{
		if(count[i]!=0)
			total++;
	}
	for(i=100;i>1;i--)
	{
		if(count[i]!=0)
		{
			temp++;
			if(temp!=total)
				printf("%d ",i);
			else
				printf("%d",i);
		}
	}
	return 0;
}