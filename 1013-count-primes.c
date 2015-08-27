#include<stdio.h>
#include<math.h>
int is_prime(int num)
{
	int i;
	if(num==2)
		return 1;
	else
	{
		for(i=2;i<=sqrt(num);i++)
		{
			if(num%i==0)
				return 0;
		}
	}
	return 1;
}

int main()
{
	int m,n,num,i=0,count=0;
	scanf("%d %d",&m,&n);
	for(num=2;1;num++)
	{
		if(is_prime(num))
		{
			i++;
			if(i>=m&&i<n)
			{
				count++;
				if(count==10)
				{
					printf("%d\n",num);
					count=0;
				}
				else
				{
					printf("%d ",num);
				}
			}
			else if(i==n)
			{
				count++;
				if(count==10)
				{
					printf("%d\n",num);
					count=0;
				}
				else
				{
					printf("%d",num);
				}
				break;
			}
		}
	}
}