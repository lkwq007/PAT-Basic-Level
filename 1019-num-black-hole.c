#include<stdio.h>
int compare(const void *a,const void *b)
{
	return *((char *)a)-*((char *)b);
}

int rcompare(const void *a,const void *b)
{
	return *((char *)b)-*((char *)a);
}

int main()
{
	char buf[5]="0000";
	int i,num,rnum,result;
	scanf("%s",buf);
	for(i=0;i<4;i++)
	{
		if(buf[i]=='\0')
			buf[i]='0';
	}
	do
	{
		qsort(buf,4,sizeof(char),compare);
		sscanf(buf,"%d",&num);
		qsort(buf,4,sizeof(char),rcompare);
		sscanf(buf,"%d",&rnum);
		result=rnum-num;
		printf("%04d - %04d = %04d\n",rnum,num,result);
		if(result==0)
		{
			break;
		}
		sprintf(buf,"%04d",result);
	}while(result!=6174);
	return 0;
}