#include <stdio.h>
int main()
{int a,b;
printf("The codes for various days of week are\nMonday is M = 1\nTuesday is Tu = 2\nWednesday is Wed = 3\nThursday is Th = 4\nFriday is F = 5\nSaturday is Sat = 6\nSunday is Sun = 7\n");
printf("Give the integer value of today:\n");
scanf("%d",&a);
b=(a+100)%7;
(b==1)?printf("M"):(b==2)?printf("Tu"):(b==3)?printf("Wed"):(b==4)?printf("Th"):(b==5)?printf("F"):(b==6)?printf("Sat"):printf("Sun");
return 2;
/*after 100 days implies 14 weeks and 2 days the day will be two days after today i.e.,if today is friday then after 100 days it would be sunday*/
}
