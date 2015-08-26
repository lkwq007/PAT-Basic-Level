/*LLonely
 *PAT Basic Level No.1039
 *Duration: 1ms
 *Memory: 328kB
 */
#include<stdio.h>
#include<string.h>

int main(void)
{	
	char beads_sold[1001],beads_wanted[1001],*p;
	int more=0,less=0,i;
	scanf("%s",beads_sold);
	scanf("%s",beads_wanted);
	for(i=0;i<strlen(beads_wanted);i++)
	{
		if((p=strchr(beads_sold,beads_wanted[i]))!=NULL)
		{
			*p=1;
			beads_wanted[i]=1;
		}
	}
	for(i=0;i<strlen(beads_wanted);i++)
	{
		if(beads_wanted[i]!=1)
		{
			less++;
		}
	}
	if(less!=0)
	{
		printf("No %d\n",less);
	}
	else
	{
		for(i=0;i<strlen(beads_sold);i++)
		{
			if(beads_sold[i]!=1)
			{
				more++;
			}
		}
		printf("Yes %d\n",more);
	}
	return 0;
}