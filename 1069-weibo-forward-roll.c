#include<stdio.h>
#include<string.h>
char table[1000][20];
int lookup(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(!strcmp(str,table[i]))
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int m,n,s,offset=0,skip=0;
	int i;
	char buf[21];
	scanf("%d%d%d",&m,&n,&s);
	for(i=0;i<m;i++)
	{
		scanf("%s",buf);
		if(i-s>-2&&(i+1-s-skip)%n==0)
		{
			if(lookup(buf,offset)<0)
			{
				strcpy(table[offset],buf);
				offset++;
				printf("%s\n",buf);
			}
			else
			{
				skip++;
			}
		}
	}
	if(offset==0)
	{
		printf("Keep going...\n");
	}
	return 0;
}