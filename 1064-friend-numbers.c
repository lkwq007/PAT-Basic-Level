#include <stdio.h>
int id[10000];
int main()
{
	int n,i,temp,cnt=0,max=0;
	char buf[8],*pbuf;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",buf);
		pbuf=buf;
		temp=0;
		while(*pbuf)
		{
			temp+=*pbuf-'0';
			pbuf++;
		}
		if(id[temp]==0)
		{
			id[temp]=1;
			cnt++;
			if(temp>max)
			{
				max=temp;
			}
		}
	}
	printf("%d\n",cnt);
	temp=1;
	for(i=0;i<=max;i++)
	{
		if(id[i]==1)
		{
			if(temp)
			{
				printf("%d",i);
				temp=0;
			}
			else
			{
				printf(" %d",i);
			}
		}
	}
	printf("\n");
}