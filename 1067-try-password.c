#include<stdio.h>
#include<string.h>
int main()
{
	char password[24],buf[128];
	int n,i,cnt=0;
	scanf("%s%d",password,&n);
	getchar();
	while(1)
	{
		gets(buf);
		if(!strcmp(buf,"#"))
		{
			break;
		}
		if(strcmp(buf,password))
		{
			cnt++;
			printf("Wrong password: %s\n",buf);
			if(cnt>=n)
			{
				printf("Account locked\n");
				break;
			}
		}
		else
		{
			printf("Welcome in\n");
			break;
		}
	}
	return 0;
}