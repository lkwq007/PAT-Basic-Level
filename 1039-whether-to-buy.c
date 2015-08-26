/*LLonely
 *PAT Basic Level No.1039
 *Duration: 1ms
 *Memory: 256kB
 */
#include<stdio.h>

int main(void)
{
	int count_sold[128],count_wanted[128],i,more=0,less=0;
	char c;
	for(i=0;i<128;i++)
	{
		count_sold[i]=0;
		count_wanted[i]=0;
	}
	while((c=getchar())!='\n')
	{
		count_sold[c]++;
	}
	while((c=getchar())!='\n')
	{
		count_wanted[c]++;
	}
	for(i=0;i<128;i++)
	{
		if(count_sold[i]>count_wanted[i])
		{
			more+=(count_sold[i]-count_wanted[i]);
		}
		else if(count_sold[i]<count_wanted[i])
		{
			less+=(count_wanted[i]-count_sold[i]);
		}
	}
	if(less==0)
	{
		printf("Yes %d\n",more);
	}
	else
	{
		printf("No %d\n",less);
	}
	return 0;
}