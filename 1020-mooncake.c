#include<stdio.h>
#include<stdlib.h>
typedef struct mooncake
{
	int amount;
	int sale;
	double price;
} MOONCAKE;
int rcompare(const void *a,const void *b)
{
	if(((MOONCAKE *)b)->price>((MOONCAKE *)a)->price)
		return 1;
	else if(((MOONCAKE *)b)->price<((MOONCAKE *)a)->price)
		return -1;
	return 0;
}
/*int rcompare(const void *a,const void *b)
{
	if(((MOONCAKE *)b)->sale*((MOONCAKE *)a)->amount>((MOONCAKE *)a)->sale*((MOONCAKE *)b)->amount)
		return 1;
	else if(((MOONCAKE *)b)->sale*((MOONCAKE *)a)->amount<((MOONCAKE *)a)->sale*((MOONCAKE *)b)->amount)
		return -1;
	return 0;
}*/
int main()
{
	int i,n,demand,amount=0,enough=0;
	double result=0;
	MOONCAKE *mc;
	scanf("%d%d",&n,&demand);
	mc=(MOONCAKE *)malloc(n*sizeof(MOONCAKE));
	for(i=0;i<n;i++)
		scanf("%d",&(mc[i].amount));
	for(i=0;i<n;i++)
	{
		scanf("%d",&(mc[i].sale));
		mc[i].price=mc[i].sale/(double)mc[i].amount;
	}
	qsort(mc,n,sizeof(MOONCAKE),rcompare);
	for(i=0;i<n;i++)
	{
		amount+=(mc[i].amount);
		if(amount>demand)
		{
			enough=1;
			break;
		}
	}
	n=i+1;
	amount=0;
	for(i=0;i<n;i++)
	{
		if(i==n-1&&enough==1)
		{
			amount=demand-amount;
			/*result+=(mc[i].price*amount);*/
			result+=(mc[i].sale*amount/(double)mc[i].amount);
			break;
		}
		result+=mc[i].sale;
		amount+=mc[i].amount;
	}
	printf("%.2f\n",result);
	return 0;
}