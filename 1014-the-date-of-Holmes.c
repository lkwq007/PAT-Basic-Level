#include<stdio.h>
int main()
{
	char str[4][61],day[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int i,count=0;
	for(i=0;i<4;i++)
		scanf("%s",str[i]);
	i=0;
	while(str[0][i]!='\0'&&str[1][i]!='\0')
	{
		if(str[0][i]==str[1][i]&&(str[0][i]>='0'&&str[0][i]<='9'||str[0][i]>='A'&&str[0][i]<='N'))
		{
			if(count==0)
			{
				if(str[0][i]>='A'&&str[0][i]<='G')
				{
					printf("%s ",day[str[0][i]-'A']);
					count++;
				}
			}
			else if(count==1)
			{
				printf("%02d:",str[0][i]>='0'&&str[0][i]<='9'?str[0][i]-'0':str[0][i]-'A'+10);
				count++;
			}
			else
				break;
		}
		i++;
	}
	i=0;
	while(str[2][i]!='\0'&&str[3][i]!='\0')
	{
		if(str[2][i]==str[3][i]&&(str[2][i]>='a'&&str[2][i]<='z'||str[2][i]>='A'&&str[2][i]<='Z'))
		{
			printf("%02d",i);
			break;
		}
		i++;
	}
}