#include<stdio.h>

int main()
{
	int num,power,flag=0,count=0;
	while(scanf("%d %d",&num,&power)!=EOF)
	{
		if(power!=0&&num!=0)
		{
			count++;
			if(flag==0)
			{
				printf("%d %d",num*power,power-1);
				flag=1;
			}
			else
				printf(" %d %d",num*power,power-1);
		}
	}
	if(count==0)
		printf("0 0");
}