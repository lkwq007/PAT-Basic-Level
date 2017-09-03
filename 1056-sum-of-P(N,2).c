#include<stdio.h>
int main(){
	int n,i,j,nums[10],sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",nums+i);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				continue;
			}
			sum+=nums[i]*10+nums[j];
		}
	}
	printf("%d\n",sum);
	return 0;
}