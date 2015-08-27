#include<stdio.h>

int main()
{
	long long pa=0,pb=0;
	int da,db,counta=0,countb=0;
	char a[12],b[12],i;
	scanf("%s%d%s%d",a,&da,b,&db);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==da+'0')
			counta++;
	}
	for(i=0;b[i]!='\0';i++)
	{
		if(b[i]==db+'0')
			countb++;
	}
	for(i=0;i<counta;i++)
	{
		pa*=10;
		pa+=da;
	}
	for(i=0;i<countb;i++)
	{
		pb*=10;
		pb+=db;
	}
	printf("%lld\n",pa+pb);

}