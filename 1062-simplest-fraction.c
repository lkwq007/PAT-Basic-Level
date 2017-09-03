#include<stdio.h>
#include<math.h>
// brute force method
int compare(int num_1,int den_1,int num_2,int den_2)
{
	return num_1*den_2-num_2*den_1;
}
int co_prime(int num,int den)
{
	int i;
	if(num>den)
	{
		i=num;
		num=den;
		den=i;
	}
	if(num==1||den==1)// when den=1
	{
		return 1;
	}
	if(den%num==0)
	{
		return 0;
	}
	for(i=2;i<=num/2;i++)
	{
		if(num%i==0&&den%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n1,m1,n2,m2,k,temp,iter;
	scanf("%d/%d%d/%d%d",&n1,&m1,&n2,&m2,&k);
	if(compare(n1,m1,n2,m2)>0)
	{
		temp=n1;
		n1=n2;
		n2=temp;
		temp=m1;
		m1=m2;
		m2=temp;
	}
	temp=1;
	for(iter=0;1;iter++)
	{
		if(compare(n1,m1,iter,k)<0)
		{
			if(compare(iter,k,n2,m2)<0)
			{
				if(co_prime(iter,k))
				{
					if(temp)
					{
						printf("%d/%d",iter,k);
						temp=0;
					}
					else
					{
						printf(" %d/%d",iter,k);
					}
				}
			}
			else
			{
				break;
			}
		}
	}
	printf("\n");
	return 0;
}