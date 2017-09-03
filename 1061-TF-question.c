#include<stdio.h>
int main()
{
	int n,m,i,j;
	int score[2][100];
	int temp,total;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&(score[0][i]));
		score[1][i]=score[0][i];
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&temp);
		score[1-temp][i]=0;
	}
	for(j=0;j<n;j++)
	{
		total=0;
		for(i=0;i<m;i++)
		{
			scanf("%d",&temp);
			total+=score[temp][i];
		}
		printf("%d\n",total);
	}
	return 0;
}