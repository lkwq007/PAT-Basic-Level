#include<stdio.h>
#include<string.h>
main()
{
	char temp_name[15],temp_id[15],min_name[15],min_id[15],max_name[15],max_id[15];
	int n,i,min,max,grade;
	scanf("%d",&n);
	min=100;
	max=0;
	for(i=0;i<n;i++)
	{
		scanf("%s",temp_name);
		scanf("%s",temp_id);
		scanf("%d",&grade);
		if(grade>max)
		{
			max=grade;
			strcpy(max_name,temp_name);
			strcpy(max_id,temp_id);
		}
		if(grade<min)
		{
			min=grade;
			strcpy(min_name,temp_name);
			strcpy(min_id,temp_id);
		}
	}
	printf("%s %s\n",max_name,max_id);
	printf("%s %s\n",min_name,min_id);
	return 0;
}