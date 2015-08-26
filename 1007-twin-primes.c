#include<stdio.h>
#include<math.h>
main()
{
	int isprime(int n);
	int prime_pre,prime_next,temp,twin,i,j,n;
	scanf("%d",&n);
	twin=0;
	for(i=2;i<=n;i++)
	{
		if(isprime(i))
		{
			prime_pre=i;
			for(j=i+1;j<=n;j++)
			{
				if(isprime(j))
				{
					prime_next=j;
					break;
				}
			}
			if(prime_next-prime_pre==2)
			{
				twin++;
			}
			i=j-1;
		}
	}
	printf("%d\n",twin);
}
int isprime(int n)
{
	int sqn,i;
	sqn=sqrt(n);
	for(i=2;i<=sqn;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}