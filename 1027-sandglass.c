#include<stdio.h>
int main()
{
	char c;
	int n,i,j,k;
	scanf("%d %c",&n,&c);
	n--;
	for(i=3;n>=2*i;i+=2)
	{
		n-=(2*i);
	}
	i-=2;
	for(j=i;j>0;j-=2)
	{
		for(k=(i-j)/2;k>0;k--)
			printf(" ");
		for(k=j;k>0;k--)
			printf("%c",c);
		printf("\n");
	}
	for(j=3;j<=i;j+=2)
	{
		for(k=(i-j)/2;k>0;k--)
			printf(" ");
		for(k=j;k>0;k--)
			printf("%c",c);
		printf("\n");
	}
	printf("%d\n",n);
}