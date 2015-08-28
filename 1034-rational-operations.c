#include<stdio.h>
#define ABS(x) ((x)>0?(x):(-x))
typedef struct fraction
{
	int numerator;
	int denominator;
	int num;
} FRACTION;

FRACTION simplify(FRACTION a)
{
	int i,flag=1;
	if(a.denominator==0)
	{
		a.num=0;
		return a;
	}
	if(a.numerator>0&&a.denominator<0||a.numerator<0&&a.denominator>0)
	{
		flag=-1;
		a.numerator=ABS(a.numerator);
		a.denominator=ABS(a.denominator);
	}
	else if(a.numerator<0&&a.denominator<0)
	{
		flag=1;
		a.numerator=ABS(a.numerator);
		a.denominator=ABS(a.denominator);
	}
	a.num=a.numerator/a.denominator;
	a.numerator%=a.denominator;
	for(i=a.numerator;i>=2;i--)
	{
		if(a.numerator%i==0&&a.denominator%i==0)
		{
			a.numerator/=i;
			a.denominator/=i;
		}
	}
	if(a.num!=0)
		a.num=flag*a.num;
	else
		a.numerator=flag*a.numerator;
	return a;
}

FRACTION plus(FRACTION a,FRACTION b)
{
	FRACTION c;
	c.denominator=a.denominator*b.denominator;
	c.numerator=a.numerator*b.denominator+b.numerator*a.denominator;
	return c;
}

FRACTION sub(FRACTION a,FRACTION b)
{
	FRACTION c;
	c.denominator=a.denominator*b.denominator;
	c.numerator=a.numerator*b.denominator-b.numerator*a.denominator;
	return c;
}

FRACTION multi(FRACTION a,FRACTION b)
{
	FRACTION c;
	c.denominator=a.denominator*b.denominator;
	c.numerator=a.numerator*b.numerator;
	return c;
}

FRACTION div(FRACTION a,FRACTION b)
{
	FRACTION c;
	c.denominator=a.denominator*b.numerator;
	c.numerator=a.numerator*b.denominator;
	return c;
}

void print(FRACTION a)
{
	if(a.num==0)
	{
		if(a.denominator==0)
			printf("Inf");
		else if(a.numerator==0)
			printf("0");
		else
		{
			if(a.numerator<0)
				printf("(-%d/%d)",ABS(a.numerator),ABS(a.denominator));
			else
				printf("%d/%d",a.numerator,a.denominator);
		}
	}
	else if(a.numerator==0)
	{
		if(a.num>0)
			printf("%d",a.num);
		else
			printf("(%d)",a.num);
	}
	else
	{
		if(a.num>0)
			printf("%d %d/%d",a.num,a.numerator,a.denominator);
		else
			printf("(%d %d/%d)",a.num,a.numerator,a.denominator);
	}
}

void print_expression(FRACTION a,FRACTION b,FRACTION c,char o)
{
	print(a);
	printf(" %c ",o);
	print(b);
	printf(" = ");
	print(c);
	printf("\n");
}

int main()
{
	FRACTION a,b,a_s,b_s,c;
	scanf("%d/%d %d/%d",&a.numerator,&a.denominator,&b.numerator,&b.denominator);
	a_s=simplify(a);
	b_s=simplify(b);
	c=simplify(plus(a,b));
	print_expression(a_s,b_s,c,'+');
	c=simplify(sub(a,b));
	print_expression(a_s,b_s,c,'-');
	c=simplify(multi(a,b));
	print_expression(a_s,b_s,c,'*');
	c=simplify(div(a,b));
	print_expression(a_s,b_s,c,'/');
}