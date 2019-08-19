#include <bits/stdc++.h>
int main()
{int a,i,j,k,l;
j=0;
 
printf("Enter the number to be checked as prime:");
scanf("%d",&a);
if(a<2){
	printf("\nIt is not a prime\n");
	
}
else if (a==2 || a==3){
	printf("It is a prime\n");
}
else{
	for(i=2;i<=sqrt(a);i++){
		if (a%i==0){
			printf("It is not a prime\n");
			j+=1;
			break;
		}
		else{
			continue;
		}
		
	}
	if(j==0){
	printf("It is a prime");}
}
return 8;
}










