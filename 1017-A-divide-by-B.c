#include<stdio.h>

int main()
{
	char a[1001],*pa=a,temp[3],q[1001],*pq=q;
	int b,r=0,num;
	scanf("%s%d",a,&b);
	while(*pa)
	{
		temp[0]=r+'0';
		temp[1]=*pa;
		temp[2]='\0';
		sscanf(temp,"%d",&num);
		*(pq++)=num/b+'0';
		r=num%b;
		pa++;
	}
	*pq='\0';
	if(q[0]=='0'&&q[1]=='\0'||q[0]!='0')
		pq=q;
	else
		pq=q+1;
	printf("%s %d",pq,r);
}