#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct info_
{
	char name[9];
	int height;
} info;
int compare(const void *a,const void *b)
{
	if(((info *)a)->height==((info *)b)->height)
	{
		return strcmp(((info *)a)->name,((info *)b)->name);
	}
	return ((info *)b)->height-((info *)a)->height;
}
int main()
{
	info *group;
	int i,j,n,k,cols,total,id,offset,*result;
	scanf("%d%d",&n,&k);
	group=(info *)malloc(n*sizeof(info));
	result=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%s%d",group[i].name,&(group[i].height));
	}
	qsort(group,n,sizeof(info),compare);
	total=n;
	offset=0;
	id=0;
	for(i=0;i<k;i++)
	{
		cols=total-n/k*(k-i-1);
		total-=cols;
		for(j=1;j<=cols;j++)
		{
			result[offset+cols/2+(j%2==0?-j/2:j/2)]=id++;
		}
		printf("%s",group[result[offset]].name);
		for(j=1;j<cols;j++)
		{
			printf(" %s",group[result[offset+j]].name);
		}
		printf("\n");
		offset+=cols;
	}
}