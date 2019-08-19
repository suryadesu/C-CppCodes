#include <stdio.h>
int main()
{
    int a,b,c;
    a=6;
    b=7;
    c=10;
    (a>b)? printf("a>b"):(b>c)? printf("b>c"): printf("c is the greatest number");
    return 0;
}
