#include<stdio.h>
int score[100];
int main()
{
	int n,temp,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		score[temp]++;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		printf("%d",score[temp]);
		if(i!=n-1)
			printf(" ");
	}
	return 0;
}