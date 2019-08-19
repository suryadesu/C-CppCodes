#include <stdio.h>
int main()
{int a,b,i,exp;
 printf("To check a raised to the power of b\ntype a");
scanf("%d",&a);
printf("\ntype b");
scanf("%d",&b);
for(i=1;i<=b;i++)
{
	exp = exp*a;
	
}
printf("%d",exp);
return 2;
}
