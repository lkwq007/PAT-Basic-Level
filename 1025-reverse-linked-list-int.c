#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct
{
	int address;
	int data;
	int next;
} list;
int main()
{
	int n,k,i,j,start,count=1;
	list *in,*out,temp,*po;
	scanf("%d%d%d",&start,&n,&k);
	in=(list *)malloc(n*sizeof(list));
	out=(list *)malloc(n*sizeof(list));
	po=NULL;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&in[i].address,&in[i].data,&in[i].next);
		if(start==in[i].address)
		{
			memcpy(&out[0],&in[i],sizeof(list));
			po=out;
		}
		else if(po!=NULL&&po->next==in[i].address)
		{
			memcpy(po+1,&in[i],sizeof(list));
			count++;
			po++;
		}
	}
/*	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n;j++)
		{
			if(out[i].next==in[j].address)
			{
				memcpy(&out[i+1],&in[j],sizeof(list));
				count++;
				break;
			}
		}
	}*/
	while(po->next!=-1)
	{
		for(i=0;i<n;i++)
		{
			if(po->next==in[i].address)
			{
				memcpy(po+1,&in[i],sizeof(list));
				count++;
				po++;
				break;
			}
		}
	}
	if(k>1&&k<=count)
	{
		for(i=0;i<count;i+=k)
		{
			if(count-i>=k)
			{
				for(j=i;j<i+k/2;j++)
				{
					memcpy(&temp,&out[j],sizeof(list));
					memcpy(&out[j],&out[i+i+k-j-1],sizeof(list));
					memcpy(&out[i+i+k-j-1],&temp,sizeof(list));
				}
			}
			else
			{
				break;
			}
		}
		for(i=0;i<count-1;i++)
		{
			out[i].next=out[i+1].address;
			printf("%05d %d %05d\n",out[i].address,out[i].data,out[i].next);
		}
		out[i].next=-1;
		printf("%05d %d %d\n",out[i].address,out[i].data,out[i].next);
	}
	else
	{
		for(i=0;i<count-1;i++)
		{
			printf("%05d %d %05d\n",out[i].address,out[i].data,out[i].next);
		}
		printf("%05d %d %d\n",out[i].address,out[i].data,out[i].next);
	}
	free(in);
	free(out);
}