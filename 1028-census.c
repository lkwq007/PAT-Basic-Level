//using unstable sort
//need fixing
#include<stdio.h>
#include<stdlib.h>

typedef struct person
{
	char name[6];
	int year;
	int month;
	int day;
} PERSON;
int compare_d(const void *a,const void *b)
{
	return ((PERSON *)a)->day-((PERSON *)b)->day;
}
int compare_m(const void *a,const void *b)
{
	return ((PERSON *)a)->month-((PERSON *)b)->month;
}
int compare_y(const void *a,const void *b)
{
	return ((PERSON *)a)->year-((PERSON *)b)->year;
}
int compare_n(const void *a,const void *b)
{
	return ((PERSON *)a)->name[0]-((PERSON *)b)->name[0];
}
int main()
{
	int n,i,count=0,flag=0,max,min;
	PERSON *census;
	scanf("%d",&n);
	census=(PERSON *)malloc((n+2)*sizeof(PERSON));
	for(i=0;i<n;i++)
		scanf("%s%d/%d/%d",census[i].name,&census[i].year,&census[i].month,&census[i].day);
	census[i].name[0]=1;
	census[i].year=1814;
	census[i].month=9;
	census[i].day=6;
	i++;
	census[i].name[0]=2;
	census[i].year=2014;
	census[i].month=9;
	census[i].day=7;
	qsort(census,n+2,sizeof(PERSON),compare_n);
	qsort(census,n+2,sizeof(PERSON),compare_d);
	qsort(census,n+2,sizeof(PERSON),compare_m);
	qsort(census,n+2,sizeof(PERSON),compare_y);
	for(i=0;i<n+2;i++)
	{
		if(census[i].name[0]==1)
		{
			flag=1;
			max=i+1;
			continue;
		}
		if(census[i].name[0]==2&&flag==1)
		{
			flag=0;
			min=i-1;
		}
		if(flag)
		{
			count++;
		}
	}
	if(count==0)
		printf("0\n");
	else
		printf("%d %s %s\n",count,census[max].name,census[min].name);
}