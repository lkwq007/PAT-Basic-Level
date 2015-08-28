#include<stdio.h>
int main()
{
	int i,count[10],flag=0;
	char num[60],*pnum=num;
	for(i=0;i<10;i++)
	{
		scanf("%d",count+i);
	}
	for(i=1;i<10;i++)
	{
		while(count[i]>0)
		{
			*(pnum++)=i+'0';
			if(flag==0)
			{
				flag=1;
				while(count[0]>0)
				{
					*(pnum++)='0';
					count[0]--;
				}
			}
			count[i]--;
		}
	}
	*pnum='\0';
	printf("%s\n",num);
	return 0;
}