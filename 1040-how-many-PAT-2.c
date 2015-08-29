#include<stdio.h>
struct
{
	char c;
	long num;
	long next;
}count[100001],*pcount,*pcount_e;
int main()
{
	char buf[100001]=" ";
	int i,j,k;
	long result=0,count_t=0,count_a=0;
	pcount=count;
	gets(buf);
	count[0].c=buf[0];
	count[0].num++;
	for(i=1;buf[i];i++)
	{
		if(buf[i]==pcount->c)
		{
			(pcount->num)++;
		}
		else
		{
			pcount++;
			pcount->c=buf[i];
			pcount->num++;
		}
	}
	pcount_e=pcount+1;
	pcount_e->c='T';
	pcount_e->num=0;
	for(i=0;pcount+i>count;i--)
	{
		if((pcount+i)->c=='T')
		{
			(pcount+i)->num+=count_t;
			count_t=(pcount+i)->num;
		}
		else if((pcount+i)->c=='A')
		{
			(pcount+i)->next=count_t;
			(pcount+i)->num*=(pcount+i)->next;
			(pcount+i)->num+=count_a;
			count_a=(pcount+i)->num;
		}
	}
/*	count_t=0;
	for(i=0;pcount+i>count;i--)
	{
		if((pcount+i)->c=='A')
		{
			for(j=i+1;pcount+j<=pcount_e;j++)
			{
				if((pcount+j)->c=='T')
				{
					(pcount+i)->next=(pcount+j)->num;
					break;
				}
			}
			(pcount+i)->num*=(pcount+i)->next;
			(pcount+i)->num+=count_t;
			count_t=(pcount+i)->num;
		}
	}*/
	for(i=0;count+i<pcount-1;i++)
	{
		if(count[i].c=='P')
		{
			for(j=i+1;count+j<pcount_e;j++)
			{
				if(count[j].c=='A')
				{
					result+=(count[i].num*count[j].num);
					result%=1000000007;
					break;
				}
			}
		}
	}
/*	for(i=0;count+i<pcount_e;i++)
	{
		temp[0]=1;
		if(count[i].c=='P')
		{
			temp[0]*=count[i].num;
			temp[1]=0;
			for(j=i+1;count+j<pcount_e;j++)
			{
				if(count[j].c=='A')
				{
					temp[2]=1;
					temp[2]*=count[j].num;
					temp[2]*=count[j].next;
					temp[1]+=temp[2];
				}
			}
			temp[0]*=temp[1];
			result+=temp[0];
			result%=1000000007;
		}
	}*/
	printf("%d\n",result);
}