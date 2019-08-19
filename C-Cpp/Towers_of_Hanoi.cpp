#include<bits/stdc++.h>
void Move(char source,char dest)
{
printf("Move the top disk from tower %c to tower %c\n",source,dest);
}

void Hanoi(int n, char source,char dest,char aux){
if(n==1){Move(source,dest);
}	
else{Hanoi((n-1),source,aux,dest);
Move(source,dest);
Hanoi((n-1),aux,dest,source);
}	
}

int main(){
clock_t start,end;
double cpu_time_used;
start = clock();
int n;
char a,b,c;
printf("Enter the number of disks");
scanf("%d",&n);
Hanoi(n,'a','b','c');

























end = clock();
cpu_time_used = ((double)end-start)/CLOCKS_PER_SEC;
printf("Cpu time used is %f",cpu_time_used);
return 9;

}
