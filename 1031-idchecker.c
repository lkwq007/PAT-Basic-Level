#include<stdio.h>
#include<stdlib.h>

int get_num(char c)
{
	if(c>='0'&&c<='9')
	{
		return c-'0';
	}
	else
		return -1;
}

int main()
{
	int n,i,j,temp=0,count=0;
	char id[100][19];
	int power[18]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2},valid[11]={1,0,-1,9,8,7,6,5,4,3,2};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",id[i]);
		temp=0;
		for(j=0;j<18;j++)
		{
			temp=temp+(get_num(id[i][j])*power[j]);
		}
		temp%=11;
		if(valid[temp]!=get_num(id[i][17]))
		{
			count++;
			printf("%s\n",id[i]);
		}
	}
	if(count==0)
		printf("All passed\n");
	return 0;
}