#include<stdio.h>
#include<stdlib.h>
typedef struct num
{
	int number;
	int state;
} NUM;
int main()
{
	NUM *in;
	int n,i,j,*result,*p_result;
	scanf("%d",&n);
	in=(NUM *)malloc(n*sizeof(NUM));
	result=(int *)malloc(n*sizeof(int));
	p_result=result;
	for(i=0;i<n;i++)
	{
		scanf("%d",&(in[i].number));
		in[i].state=1;
	}
	for(i=0;i<n;i++)
	{
		if(in[i].state==0)
			continue;
		for(j=0;j<n;j++)
		{
			if(j<i&&in[j].number<in[i].number||j>i&&in[j].number>in[i].number||j==i)
				;
			else
			{
				in[j].state=0;
				goto ANOTHER;
			}
		}
		*(p_result)=in[i].number;
		p_result++;
ANOTHER:
		;
	}
	printf("%d\n",p_result-result);
	if(p_result-result>0)
		printf("%d",*result);
	for(i=1;i<p_result-result;i++)
		printf(" %d",result[i]);
	printf("\n");
}