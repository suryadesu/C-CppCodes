#include<bits/stdc++.h>
int main()
{
	double cpu_time;
	clock_t a,c;
	int b;
	scanf("%d",&b);
	a=clock();
	
	c=clock();
	cpu_time=((double)(c-a))/CLOCKS_PER_SEC;
	printf("%f",cpu_time);
	return 9;
	
}
