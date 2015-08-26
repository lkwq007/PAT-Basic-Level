#include<stdio.h>

int main(void)
{
	long long galleon_P,sickle_P,knut_P,galleon_A,sickle_A,knut_A,galleon,sickle,knut,flag;
	scanf("%lld.%lld.%lld %lld.%lld.%lld",&galleon_P,&sickle_P,&knut_P,&galleon_A,&sickle_A,&knut_A);
	knut_P=knut_P+galleon_P*17*29+sickle_P*29;
	knut_A=knut_A+galleon_A*17*29+sickle_A*29;
	knut_A-=knut_P;
	flag=knut_A>=0?1:(knut_A=-knut_A),-1;
	knut=knut_A%29;
	sickle_A=knut_A/29;
	sickle=sickle_A%17;
	galleon_A=sickle_A/17;
	galleon=galleon_A;
	if(flag==1)
		printf("%lld.%lld.%lld\n",galleon,sickle,knut);
	else
		printf("-%lld.%lld.%lld\n",galleon,sickle,knut);
	return 0;
}