#include<stdio.h>
struct game
{
	int speak;
	int done;
	int count;
} a={0,0,0},b={0,0,0};
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&(a.speak),&(a.done),&(b.speak),&(b.done));
		if(a.speak+b.speak==a.done)
		{
			if(a.done==b.done)
			{
				continue;
			}
			else
			{
				a.count++;
			}
		}
		else if(a.speak+b.speak==b.done)
		{
			b.count++;
		}
	}
	printf("%d %d\n",b.count,a.count);
}