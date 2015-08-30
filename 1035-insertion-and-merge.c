#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int arraycmp(int *a,int *b,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]!=b[i])
			return 0;
	}
	return 1;

}

int issort(int *a,int i)
{
	int temp,j;
	temp=a[i];
	for(j=i-1;j>=0;j--)
	{
		if(a[j]>temp)
		{
			a[j+1]=a[j];
		}
		else
		{
			break;
		}
	}
	a[j+1]=temp;
}

int mgsort(int *a,int n,int size)
{
	int i,edge;
	for(i=0;i<n;i+=size*2)
	{
		edge=i+size*2-1;
		if(edge>=n)
		{
			edge=n-1;
		}
		if(edge<=i)
			return 0;
		qsort(a+i,edge-i+1,sizeof(int),compare);
	}
}

int main()
{
	int i,j,flag=0,n,num[100],sorted[100],insertion[100],merge[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",num+i);
		insertion[i]=num[i];
		merge[i]=num[i];
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",sorted+i);
	}
	for(i=1;i<n;i++)
	{
		issort(insertion,i);
		if(arraycmp(insertion,sorted,n))
		{
			flag=1;
			i++;
			break;
		}
	}
	if(flag)
	{
		printf("Insertion Sort\n");
		if(i!=n)
			issort(insertion,i);
		for(i=0;i<n-1;i++)
			printf("%d ",insertion[i]);
		printf("%d\n",insertion[i]);
	}
	else
	{
		printf("Merge Sort\n");
		for(i=1;i<n;i*=2)
		{
			mgsort(merge,n,i);
			if(arraycmp(merge,sorted,n))
			{
				mgsort(merge,n,i*2);
				break;
			}
		}
		for(i=0;i<n-1;i++)
			printf("%d ",merge[i]);
		printf("%d\n",merge[i]);	
	}
}