#include<stdio.h>
#include<stdlib.h>
typedef struct question_
{
	int mistake;
	int score;
	int n_choice;
	int n_right;
	char choice[32];
} question;
question list[101];
int main()
{
	int n,m,i,j,k;
	int n_select,score,flag,max;
	char temp[2];
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&(list[i].score),&(list[i].n_choice),&(list[i].n_right));
		//list[i].mistake=0;
		for(j=0;j<list[i].n_right;j++)
		{
			scanf("%*[ ]%[a-z]",temp);
			list[i].choice[temp[0]-'a']=1;
		}
	}
	for(i=0;i<n;i++)
	{
		score=0;
		for(j=0;j<m;j++)
		{
			flag=1;
			scanf("%*[^0-9]%d",&n_select);
			for(k=0;k<n_select;k++)
			{
				scanf("%*[^a-z]%[a-z]",temp);
				if(list[j].choice[temp[0]-'a']==0)
				{
					flag=0;
				}
			}
			if(n_select!=list[j].n_right)
			{
				flag=0;
			}
			if(flag)
			{
				score+=list[j].score;
			}
			else
			{
				list[j].mistake++;
			}
		}
		printf("%d\n",score);
	}
	max=0;
	for(i=0;i<m;i++)
	{
		if(max<list[i].mistake)
		{
			max=list[i].mistake;
		}
	}
	if(max==0)
	{
		printf("Too simple\n");
		return 0;
	}
	else
	{
		printf("%d",max);
	}
	for(i=0;i<m;i++)
	{
		if(max==list[i].mistake)
		{
			printf(" %d",i+1);
		}
	}
	printf("\n");
	return 0;
}
