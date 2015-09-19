#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	long long id;
	int test;
	int exam;
} SEAT;
int main()
{
	int i,n,m,temp;
	SEAT *seats;
	scanf("%d",&n);
	seats=(SEAT *)malloc(n*sizeof(SEAT));
	for(i=0;i<n;i++)
	{
		scanf("%lld%d%d",&seats[i].id,&seats[i].test,&seats[i].exam);
	}
	scanf("%d",&m);
	while(m>0)
	{
		scanf("%d",&temp);
		for(i=0;i<n;i++)
		{
			if(seats[i].test==temp)
			{
				printf("%lld %d\n",seats[i].id,seats[i].exam);
				break;
			}
		}
		m--;
	}
	free(seats);
	return 0;
}