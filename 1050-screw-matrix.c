#include<stdio.h>
#include<stdlib.h>
int *buf,**matrix,guide=0,m,n,N;
struct position
{
	int x;
	int y;
} filler={0,0},direction[4]={{1,0},{0,1},{-1,0},{0,-1}};
int rcompare(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int canmove()
{
	int x,y;
	x=filler.x+direction[guide].x;
	y=filler.y+direction[guide].y;
	if(x<0||x>=n||y<0||y>=m)
	{
		return 0;
	}
	else if(matrix[y][x]!=0)
	{
		return 0;
	}
	return 1;
}
int move(int count)
{
	matrix[filler.y][filler.x]=buf[count];
	if(count==N-1)
	{
		return 0;
	}
	while(!canmove())
	{
		guide=(guide+1)%4;
	}
	filler.y+=direction[guide].y;
	filler.x+=direction[guide].x;
	return 0;
}
int main()
{
	int i,j,count=0;
	scanf("%d",&N);
	buf=(int *)malloc(N*sizeof(int));
	for(i=0;i<N;i++)
	{
		scanf("%d",buf+i);
	}
	qsort(buf,N,sizeof(int),rcompare);
	m=N;
	n=1;
	for(i=N;i>0;i--)
	{
		if(N%i==0)
		{
			if(i-N/i<0)
			{
				break;
			}
			if(i-N/i<m-n)
			{
				m=i;
				n=N/i;
			}
		}
	}
	matrix=(int **)malloc(m*sizeof(int *));
	for(i=0;i<m;i++)
	{
		matrix[i]=(int *)calloc(n,sizeof(int));
	}
	while(count<N)
	{
		move(count);
		count++;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n-1;j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("%d\n",matrix[i][j]);
	}
}