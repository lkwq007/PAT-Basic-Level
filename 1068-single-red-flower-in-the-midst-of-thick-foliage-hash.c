// not AC
// i misunderstood the unique color
#include<stdio.h>
#include<math.h>
int bitmap[1024][1024];
typedef struct attr_
{
	int x;
	int y;
	int color;
	int flag;
} attr;
attr table[2048];
int lookup(int color,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(color==table[i].color)
		{
			table[i].flag=1;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int m,n,tol,i,j,offset=0;
	int x,y,color,ret,cnt,last;
	scanf("%d%d%d",&m,&n,&tol);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&(bitmap[i][j]));
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
			if( abs(bitmap[i][j]-bitmap[i-1][j-1])>tol&&
				abs(bitmap[i][j]-bitmap[i-1][j])>tol&&
				abs(bitmap[i][j]-bitmap[i-1][j+1])>tol&&
				abs(bitmap[i][j]-bitmap[i][j-1])>tol&&
				abs(bitmap[i][j]-bitmap[i][j+1])>tol&&
				abs(bitmap[i][j]-bitmap[i+1][j-1])>tol&&
				abs(bitmap[i][j]-bitmap[i+1][j])>tol&&
				abs(bitmap[i][j]-bitmap[i+1][j+1])>tol)
			{
				ret=lookup(bitmap[i][j],offset);
				if(ret==0)
				{
					table[offset].x=j;
					table[offset].y=i;
					table[offset].color=bitmap[i][j];
					table[offset++].flag=0;
				}
			}
		}
	}
	cnt=0;
	for(i=0;i<offset;i++)
	{
		if(table[i].flag==0)
		{
			cnt++;
			last=i;
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
		printf("(%d, %d): %d\n",table[last].x,table[last].y,table[last].color);
	}
}