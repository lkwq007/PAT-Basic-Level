#include<stdio.h>
#include<stdlib.h>
#define B 0//cloth
#define C 1//hammer
#define J 2//scissors
int compare(int a,int b)
{
	if(a==C&&b==J||a==J&&b==B||a==B&&b==C)
		return 0;
	else if(a==b)
		return 1;
	else
		return 2;
}
int main()
{
	int n,i,j,m[2]={0,0},index[2]={0,0},count[4][3];
	char a,b,sign[4]="BCJ";
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			count[i][j]=0;
		}
	}
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%c %c",&a,&b);
		getchar();
		switch(a)
		{
			case 'C':
			a=C;
			break;
			case 'J':
			a=J;
			break;
			case 'B':
			a=B;
			break;
		}
		switch(b)
		{
			case 'C':
			b=C;
			break;
			case 'J':
			b=J;
			break;
			case 'B':
			b=B;
			break;
		}
		switch(compare(a,b))
		{
			case 0:
			count[0][0]++;
			count[1][2]++;
			count[2][a]++;
			break;
			case 1:
			count[0][1]++;
			count[1][1]++;
			break;
			case 2:
			count[0][2]++;
			count[1][0]++;
			count[3][b]++;
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d ",count[i][j]);
		}
		printf("%d\n",count[i][j]);
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			if(m[i]<count[i+2][j])
			{
				m[i]=count[i+2][j];
				index[i]=j;
			}
		}
	}
	printf("%c %c\n",sign[index[0]],sign[index[1]]);
}