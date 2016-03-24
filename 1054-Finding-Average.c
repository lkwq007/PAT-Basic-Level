#include<stdio.h>
#include<stdlib.h>
#define DOT 1
#define SIGN 2
#define INT 4
#define FLOAT 8
#define LARGE 16
int check(char *buf)
{
	int flag=0,i,count,temp;
	char dot;
	for(i=0;buf[i];i++)
	{
		switch(buf[i])
		{
			case '.':
			if(flag&DOT)
			{
				return 0;
			}
			else
			{
				flag=flag|DOT;
			}
			break;
			case '+':
			case '-':
			if(flag&SIGN||flag&DOT)
			{
				return 0;
			}
			else
			{
				flag=flag|SIGN;
			}
			break;
			default:
			if(!(buf[i]>='0'&&buf[i]<='9'))
			{
				return 0;
			}
		}
	}
	for(i=0;buf[i]!='.'&&buf[i]!=0;i++)
	{
		;
	}
	count=0;
	for(i;buf[i];i++)
	{
		count++;
	}
	if(count>3)
	{
		return 0;
	}
	return 1;
/*	for(i=0;buf[i]!='.'&&buf[i]!=0;i++)
	{
		;
	}
	dot=buf[i];
	buf[i]=0;
	sscanf(buf,"%d",&temp);
	buf[i]=dot;
	if(temp>1000||temp<-1000)
	{
		return 0;
	}
	if(buf[i]==0)
	{
		return 1;
	}
	if(temp==1000||temp==-1000)
	{
		flag=flag|LARGE;
	}
	temp=0;
	buf[i]='0';
	sscanf(buf+i,"%d",&temp);
	buf[i]=dot;
	count=0;
	for(i++;buf[i];i++)
	{
		count++;
	}
	if(count>2)
	{
		return 0;
	}
	if((flag&LARGE)&&temp==0||temp<100&&(flag&LARGE)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}*/
}
int main()
{
	int n,i,total=0;
	double sum=0,temp;
	char buf[101];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",buf);
		if(check(buf))
		{
			sscanf(buf,"%lf",&temp);
			if(temp<=1000.00&&temp>=-1000.00)
			{	
				sum+=temp;
				total++;
			}
			else
			{
				printf("ERROR: %s is not a legal number\n",buf);
			}
		}
		else
		{
			printf("ERROR: %s is not a legal number\n",buf);
		}
	}
	if(total==0)
	{
		printf("The average of 0 numbers is Undefined\n");
	}
	else if(total==1)
	{
		printf("The average of %d number is %.2lf\n",total,sum);
	}
	else
	{
		printf("The average of %d numbers is %.2lf\n",total,sum/total);
	}
}