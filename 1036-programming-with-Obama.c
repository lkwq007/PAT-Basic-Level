#include<stdio.h>

main()
{
	int i,j,n,row;
	char c;
	scanf("%d %c",&n,&c);
	row=(int)(n/2.0+0.5);
	for(i=0;i<row;i++)
	{
		for(j=0;j<n;j++)
		{
			if((j!=0&&j!=n-1)&&(i!=0&&i!=row-1))
				printf(" ");
			else
				printf("%c",c);
		}
		printf("\n");
	}
}