#include<stdio.h>

int main()
{
	char a[1001],*pa=a,temp,q[1001],*pq=q;
	int b,r=0,num;
	scanf("%s%d",a,&b);
	while(*pa)
	{
		if(*pa-'0'>=b)
		{
			*(pq++)=(*pa-'0')/b+'0';
			r=(*pa-'0')%b;
		}
		else
		{
			if(*(pa+1)!='\0')
			{
				temp=*(pa+2);
				*(pa+2)='\0';
				*pa+=r;
				sscanf(pa,"%d",&num);
				*(pa+2)=temp;
				*(pq++)=num/b+'0';
				r=num%b;
			}
		}
		pa++;
	}
	*pq='\0';
	printf("%s %d",q,r);
}