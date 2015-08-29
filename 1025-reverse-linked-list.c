#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	char address[6];
	char next[6];
	int data;
} list;
int main()
{
	int n,k,i,j,value;
	char start[6];
	list *in,*out,temp;
	scanf("%s%d%d",start,&n,&k);
	in=(list *)malloc(n*sizeof(list));
	out=(list *)malloc(n*sizeof(list));
	for(i=0;i<n;i++)
	{
		scanf("%s%d%s",in[i].address,&in[i].data,in[i].next);
		if((value=strcmp(start,in[i].address))==0)
		{
			out[0]=in[i];
		}
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n;j++)
		{
			if(strcmp(out[i].next,in[j].address)==0)
			{
				out[i+1]=in[j];
			}
		}
	}
	for(i=0;i<n;i+=k)
	{
		if(n-i>=k)
		{
			for(j=i;j<i+k/2;j++)
			{
				temp=out[j];
				out[j]=out[i+k-j-1];
				out[i+k-j-1]=temp;
			}
		}
		else
		{
			break;
		}
	}
	for(i=0;i<n-1;i++)
	{
		strcpy(out[i].next,out[i+1].address);
		printf("%s %d %s\n",out[i].address,out[i].data,out[i].next);
	}
	strcpy(out[i].next,"-1");
	printf("%s %d %s\n",out[i].address,out[i].data,out[i].next);
	free(in);
	free(out);
}