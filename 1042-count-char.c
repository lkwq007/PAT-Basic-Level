#include<stdio.h>
int count[128];
int main()
{
	char c;
	int max=0,i;
	while((c=getchar())!='\n')
	{
		count[c]++;
	}
	for(i='A';i<='Z';i++)
	{
		count[i-'A'+'a']+=count[i];
	}
	for(i='a';i<='z';i++)
	{
		if(count[max]<count[i])
		{
			max=i;
		}
	}
	printf("%c %d\n",max,count[max]);
}