#include<stdio.h>
int main()
{
	char buf[100000],*pbuf=buf;
	int sum=0,i,zeros=0,ones=0,temp;
	gets(buf);
	while(*pbuf)
	{
		if(*pbuf>='a'&&*pbuf<='z')
		{
			sum+=*pbuf-'a'+1;
		}
		else if(*pbuf>='A'&&*pbuf<='Z')
		{
			sum+=*pbuf-'A'+1;
		}
		pbuf++;
	}
	for(i=8*sizeof(sum)-1;i>=0;i--)
	{
		temp=1<<i;
		if(temp&sum)
		{
			ones++;
		}
		else if(ones)
		{
			zeros++;
		}
	}
	printf("%d %d\n",zeros,ones);
	return 0;
}