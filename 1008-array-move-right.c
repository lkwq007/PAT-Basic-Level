#include<stdio.h>

int main()
{
	int i,n,right,num[100];
	scanf("%d %d",&n,&right);
	for(i=0;i<n;i++)
	{
		right%=n;
		scanf("%d",&num[right]);
		right++;
	}
	for(i=0;i<n-1;i++)
	{
		printf("%d ",num[i]);
	}
	printf("%d\n",num[i]);
}