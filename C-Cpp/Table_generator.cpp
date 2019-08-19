#include <stdio.h>
int main()
{int a,b;
printf ("to get the table of a number\ntype the number:\n");
scanf("%d",&a);
printf("Table of %d is:\n",a);
for(b=1;b<=10;b++)
{printf("%d x %d = %d\n",a,b,(a*b));

}
}
