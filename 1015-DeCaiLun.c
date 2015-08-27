#include<stdio.h>
#include<stdlib.h>
int l,m;
#define SAME 0
#define A 1
#define B -1
#define H -1
#define L 1
typedef struct examinee
{
	int id;
	int de;
	int cai;
	int total;
} EXAM;

int section(EXAM *a,EXAM *b)
{
	if(a->de>=m&&a->cai>=m)
	{
		if(b->de>=m&&b->cai>=m)
			return SAME;
		else
			return A;
	}
	else if(a->de>=m&&a->cai<m)
	{
		if(b->de>=m&&b->cai>=m)
			return B;
		else if (b->de>=m&&b->cai<m)
			return SAME;
		else
			return A;
	}
	else if(a->de>=a->cai&&a->de<m&&a->cai<m)
	{
		if(b->de>=m)
			return B;
		else if (b->de>=b->cai&&b->de<m&&b->cai<m)
			return SAME;
		else
			return A;
	}
	else
	{
		if(b->de<b->cai&&b->de<m)
			return SAME;
		else
			return B;
	}
}

int compare(const void *pa,const void *pb)
{
	EXAM *a,*b;
	a=(EXAM *)pa;
	b=(EXAM *)pb;
	switch(section(a,b))
	{
		case SAME:
		if(a->total>b->total)
		{
			return H;
		}
		else if(a->total==b->total)
		{
			if(a->de>b->de)
			{
				return H;
			}
			else if(a->de==b->de)
			{
				if(a->id>b->id)
					return L;
				else
					return H;
			}
			else
				return L;
		}
		else
			return L;
		case A:
		return H;
		case B:
		return L;
	}
}

int main()
{
	int i,n;
	EXAM *list;
	scanf("%d%d%d",&n,&l,&m);
	list=(EXAM *)malloc(sizeof(EXAM)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&list[i].id,&list[i].de,&list[i].cai);
		list[i].total=list[i].de+list[i].cai;
		if(list[i].de<l||list[i].cai<l)
		{
			i--;
			n--;
		}
	}
	qsort(list,n,sizeof(EXAM),compare);
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{
		printf("%d %d %d\n",list[i].id,list[i].de,list[i].cai);
	}
}