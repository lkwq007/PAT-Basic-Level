#include<stdio.h>
int count[100000];
int main()
{
	int n,id,score,edge=0,max=0,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&id,&score);
		count[id]+=score;
		if(edge<id)
			edge=id;
	}
	for(i=0;i<=edge;i++)
	{
		if(count[i]>count[max])
			max=i;
	}
	printf("%d %d\n",max,count[max]);
}