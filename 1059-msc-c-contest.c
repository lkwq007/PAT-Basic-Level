#include<stdio.h>
#include<math.h>
#define MYSTERY 1
#define MINION 2
#define CHOCOLATE 3
#define CHECKED 4
int status[10001];
int is_prime(int n)
{
	int i;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n,i,id;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&id);
		status[id]=i==1?MYSTERY:is_prime(i)?MINION:CHOCOLATE;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&id);
		printf("%04d: ",id);
		switch(status[id])
		{
			case MYSTERY:
			printf("Mystery Award\n");
			break;
			case MINION:
			printf("Minion\n");
			break;
			case CHOCOLATE:
			printf("Chocolate\n");
			break;
			case CHECKED:
			printf("Checked\n");
			break;
			default:
			printf("Are you kidding?\n");
			break;
		}
		if(status[id]!=0)
		{
			status[id]=CHECKED;
		}
	}
}