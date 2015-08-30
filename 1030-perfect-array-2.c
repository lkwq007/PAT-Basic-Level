#include<stdio.h>
#include<stdlib.h>
void HeapAdjust(long array[],long i,long nLength)
{
	long nChild;
	long nTemp;
	for(;2*i+1<nLength;i=nChild)
	{
		nChild=2*i+1;
		if(nChild<nLength-1&&array[nChild+1]>array[nChild])
			++nChild;
		if(array[i]<array[nChild])
		{
			nTemp=array[i];
			array[i]=array[nChild];
			array[nChild]=nTemp;
		}
		else
			break;
	}
}

void HeapSort(long array[],long length)
{
	long i;
	for(i=length/2-1;i>=0;--i)
	HeapAdjust(array,i,length);
	for(i=length-1;i>0;--i)
	{
		array[i]=array[0]^array[i];
		array[0]=array[0]^array[i];
		array[i]=array[0]^array[i];
		HeapAdjust(array,0,i);
	}
}

int main()
{
	long *num,*nums;
	int i,j,n,p,max=1;
	scanf("%d%d",&n,&p);
	num=(long *)malloc(n*sizeof(long));
	nums=(long *)malloc(n*sizeof(long));
	for(i=0;i<n;i++)
	{
		scanf("%ld",num+i);
	}
	HeapSort(num,n);
	for(i=0;i<n;i++)
	{
		nums[i]=num[i]*p;
	}
	for(i=0;i<n;i++)
	{
		if(i+max>n)
			break;
		for(j=i+max;j<n;j++)
		{
			if(nums[i]>=num[j])
			{
				if(max<j-i+1)
				{
					max=j-i+1;
				}
			}
			else
			{
				break;
			}
		}
	}
	printf("%d\n",max);
}