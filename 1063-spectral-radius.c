#include <stdio.h>
#include <math.h>
int main()
{
	int n,real,img,max=0,i,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&real,&img);
		temp=real*real+img*img;
		if(temp>max)
		{
			max=temp;
		}
	}
	printf("%.2lf\n",sqrt((float)max));
}