#include<stdio.h>
int main()
{
	int clock_1,clock_2,cost_time,hour,minute,second;
	scanf("%d%d",&clock_1,&clock_2);
	cost_time=(int)((double)(clock_2-clock_1)/100+0.5);
	hour=cost_time/3600;
	cost_time%=3600;
	minute=cost_time/60;
	cost_time%=60;
	second=cost_time;
	printf("%02d:%02d:%02d\n",hour,minute,second);
}
