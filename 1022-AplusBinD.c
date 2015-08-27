#include<stdio.h>
void print_base(int num,int base)
{
	char result[500];
	int temp,i=0;
	if(num==0)
		printf("0");
	while(num!=0)
	{
		temp=num%base;
		num/=base;
		result[i++]=temp+'0';
	}
	for(i;i>0;i--)
	{
		printf("%c",result[i-1]);
	}	
}
int main()
{
	int a,b,base;
	scanf("%d %d %d",&a,&b,&base);
	if(base<1||base>10)
		return 1;
	print_base(a+b,base);
}