#include<stdio.h>
int main(void)
{
	int num,count;
	count=0;
	scanf("%d",&num);
	while(num!=1)
	{
		if(num%2==0)
		{
			num/=2;
			count++;
		}
		else
		{
			num=num*3+1;
			num/=2;
			count++;
		}
	}
	printf("%d",count);
	return 0;
}