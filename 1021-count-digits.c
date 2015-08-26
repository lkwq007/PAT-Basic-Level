#include<stdio.h>
int count[10];
main()
{
	char c,i;
	while((c=getchar())!='\n')
	{
		count[c-'0']++;
	}
	for(i=0;i<10;i++)
	{
		if(count[i])
			printf("%d:%d\n",i,count[i]);
	}
	return 0;
}