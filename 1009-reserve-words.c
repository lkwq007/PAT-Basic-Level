#include<stdio.h>
#include<string.h>
main()
{
	char source[81],result[81];
	int len;
	gets(source);
	*result=0;
	len=strlen(source);
	for(len--;len>=0;len--)
	{
		if(*(source+len)==' ')
		{
			*(source+len)=0;
			strcat(result,source+len+1);
			strcat(result," ");
		}
	}
	strcat(result,source);
	puts(result);
}