#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,d,k,i,j,vacancy=0,may_vacancy=0,count;
	double e,temp;
	scanf("%d%lf%d",&n,&e,&d);
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		count=0;
		for(j=0;j<k;j++)
		{
			scanf("%lf",&temp);
			if(temp<e)
			{
				count++;
			}
		}
		if(count>k/2&&k>d)
		{
			vacancy++;
		}
		else if(count>k/2)
		{
			may_vacancy++;
		}
	}
	printf("%.1lf%% %.1lf%%\n",may_vacancy/(double)n*100.0,vacancy/(double)n*100.0);
}