#include<stdio.h>
#define pi 3.14
int main()
{
  int r;
  float area;
  printf("enter the value of radius:\n");
  scanf("%d",&r);
  area = pi*r*r;
  printf("The area of the circle is %.4f",area);
}
