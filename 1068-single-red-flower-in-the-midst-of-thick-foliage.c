#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int bitmap[1024][1024];
typedef struct bucket_ bucket;
struct bucket_
{
	int color;
	int flag;
	bucket *next;
};
bucket *table[2017];
int lookup(int color)
{
	int index,temp;
	bucket *head;
	index=(color>>8+color)%2017;
	head=table[index];
	while(head)
	{
		if(head->color==color)
		{
			temp=head->flag;
			head->flag=1;
			return temp;
		}
		head=head->next;
	}
	head=(bucket *)malloc(sizeof(bucket));
	head->next=table[index];
	head->color=color;
	head->flag=0;
	table[index]=head;
	return 0;
}
int main()
{
	int m,n,tol,i,j;
	int x,y,color,cnt=0;
	scanf("%d%d%d",&m,&n,&tol);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&(bitmap[i][j]));
			lookup(bitmap[i][j]);
		}
	}
	for(i=0;i<m+2;i++)
	{
		bitmap[0][i]=-tol-1;
		bitmap[n+1][i]=-tol-1;
	}
	for(i=0;i<n+2;i++)
	{
		bitmap[i][0]=-tol-1;
		bitmap[i][m+1]=-tol-1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(lookup(bitmap[i][j])==0)
			{
				if((abs(bitmap[i][j]-bitmap[i-1][j-1])>tol&&
				abs(bitmap[i][j]-bitmap[i-1][j])>tol&&
				abs(bitmap[i][j]-bitmap[i-1][j+1])>tol&&
				abs(bitmap[i][j]-bitmap[i][j-1])>tol&&
				abs(bitmap[i][j]-bitmap[i][j+1])>tol&&
				abs(bitmap[i][j]-bitmap[i+1][j-1])>tol&&
				abs(bitmap[i][j]-bitmap[i+1][j])>tol&&
				abs(bitmap[i][j]-bitmap[i+1][j+1])>tol))
				{
					cnt++;
					x=j;
					y=i;
					color=bitmap[i][j];
				}
				if(cnt>1)
				{
					break;
				}
			}
		}
	}
	if(cnt>1)
	{
		printf("Not Unique\n");
	}
	else if(cnt==0)
	{
		printf("Not Exist\n");
	}
	else
	{
		printf("(%d, %d): %d\n",x,y,color);
	}
}