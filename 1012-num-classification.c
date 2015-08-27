#include<stdio.h>

int main()
{
	int n,num[1000],i;
	int a[5],flag=1,count=0,counts=0;
	for(i=0;i<5;i++)
		a[i]=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",num+i);
		switch(num[i]%5)
		{
			case 0:
			if(num[i]%2==0)
			{
				a[0]+=num[i];
			}
			break;
			case 1:
			a[1]+=(flag*num[i]);
			flag=-flag;
			counts++;
			break;
			case 2:
			a[2]++;
			break;
			case 3:
			a[3]+=num[i];
			count++;
			break;
			case 4:
			if(num[i]>a[4])
			{
				a[4]=num[i];
			}
			break;
		}
	}
	for(i=0;i<4;i++)
	{
		if(a[i]==0&&i!=1||i==1&&counts==0)
		{
			printf("N ");
		}
		else if(i==3)
		{
			printf("%.1lf ",a[i]/(double)count);
		}
		else
		{
			printf("%d ",a[i]);
		}
	}
	if(a[i]==0)
	{
		printf("N");
	}
	else
	{
		printf("%d",a[i]);
	}
	return 0;
}
