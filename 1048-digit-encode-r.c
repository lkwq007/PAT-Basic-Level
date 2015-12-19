#include<stdio.h>
#include<string.h>
void reserve(char *s)
{
	int i,n;
	char temp;
	n=strlen(s);
	for(i=0;i<n/2;i++)
	{
		temp=s[i];
		s[i]=s[n-i-1];
		s[n-i-1]=temp;
	}
	return ;
}
int main()
{
	int i,j,num_a,num_b,length_a,length_b;
	char buf_a[101],buf_b[101],*a=buf_a,*b=buf_b,pattern[14]="0123456789JQK";
	scanf("%s%s",a,b);
	length_a=strlen(a);
	length_b=strlen(b);
	reserve(a);
	reserve(b);
	for(i=0;a[i];i++)
	{
		num_a=(int)(a[i]-'0');
		num_b=(int)(b[i]-'0');
		if(i>=length_b)
		{
			num_b=0;
		}
		if(i%2)
		{
			num_b-=num_a;
			if(num_b<0)
			{
				num_b+=10;
			}
		}
		else
		{
			num_b+=num_a;
			num_b%=13;
		}
		b[i]=pattern[num_b];
	}
	if(length_a>length_b)
	{
		b[i]=0;
	}
	reserve(b);
	printf("%s\n",b);
}