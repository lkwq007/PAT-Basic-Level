#include <stdio.h>
int main()
{
	int m,n,a,b,color,i,j,temp;
	scanf("%03d%03d",&m,&n);
	scanf("%03d%03d%03d",&a,&b,&color);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n-1;j++)
		{
			scanf("%03d",&temp);
			if(temp>=a&&temp<=b)
			{
				printf("%03d ",color);
			}
			else
			{
				printf("%03d ",temp);
			}
		}
		scanf("%03d",&temp);
		if(temp>=a&&temp<=b)
		{
			printf("%03d\n",color);
		}
		else
		{
			printf("%03d\n",temp);
		}
	}
	return 0;
}