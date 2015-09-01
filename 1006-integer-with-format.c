#include<stdio.h>
main()
{
	int n,i,countb,counts,countg;
	scanf("%d",&n);
	
	if(n>=100)
	{
		countg=n%10;
		counts=(n/10)%10;
		countb=(n/100)%10;
		while(countb>0)
		{
			printf("B");
			countb--;
		}
		while(counts>0)
		{
			printf("S");
			counts--;
		}
		for(i=1;i<=countg;i++)
		{
			printf("%d",i);
		}
		printf("\n");
	}
	else if(n<100&&n>9)
	{
		countg=n%10;
		counts=(n/10)%10;
		while(counts>0)
		{
			printf("S");
			counts--;
		}
		for(i=1;i<=countg;i++)
		{
			printf("%d",i);
		}
		printf("\n");
	}
	else if(n<10&&n>0)
	{
		countg=n%10;

			for(i=1;i<=countg;i++)
			{
				printf("%d",i);
			}
		printf("\n");
	}
	return 0;
}