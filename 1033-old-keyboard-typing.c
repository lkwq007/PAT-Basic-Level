#include<stdio.h>
#include<string.h>
char change(char c)
{
	if(c>='A'&&c<='Z')
		return c+('a'-'A');
	else if(c>='a'&&c<='z')
		return c+('A'-'a');
	else
		return c;
}

int main()
{
	char in[100001],broken[100001],*pi,c;
	int i;
	i=0;
	while((c=getchar())!='\n')
	{
		broken[i++]=c;
	}
	broken[i]='\0';
	i=0;
	while((c=getchar())!='\n')
	{
		in[i++]=c;
	}
	in[i]='\0';
	for(i=0;broken[i]!='\0';i++)
	{
		if(broken[i]>='a'&&broken[i]<='z')
			continue;
		while((pi=strchr(in,broken[i]))!=NULL)
		{
			*pi=1;
		}
		if(broken[i]>='A'&&broken[i]<='Z')
		{
			while((pi=strchr(in,broken[i]+('a'-'A')))!=NULL)
			{
				*pi=1;
			}
		}

	}
	if((pi=strchr(broken,'+'))!=NULL)
	{
		for(i=0;in[i]!='\0';i++)
		{
			if(in[i]>='A'&&in[i]<='Z')
				in[i]=1;
		}
	}
	for(i=0;in[i]!='\0';i++)
	{
		if(in[i]>1)
			printf("%c",in[i]);
	}
	printf("\n");
	return 0;
}