#include<stdio.h>
#include<string.h>
int main()
{
	char in[81],out[81],broken[100]="",*p,*pb=broken;
	int i;
	scanf("%s%s",in,out);
	for(i=0;out[i]!='\0';i++)
	{
		while((p=strchr(in,out[i]))!=NULL)
		{
			*p=1;
		}
	}
	for(i=0;in[i]!='\0';i++)
	{
		if(in[i]>1&&in[i]>='a'&&in[i]<='z')
			in[i]=in[i]+('A'-'a');
	}
	for(i=0;in[i]!='\0';i++)
	{
		if(in[i]>1)
		{
			if((p=strchr(broken,in[i]))==NULL)
			{
				*pb=in[i];
				*(pb+1)='\0';
				pb++;
			}
		}
	}
	printf("%s",broken);
}