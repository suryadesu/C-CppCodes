#include <bits/stdc++.h>
int prime(int a)
{int i,j;
j=0;
 
if(a<2){
	return 0;
	
}
else if (a==2 || a==3){
	return a;
}
else{
	for(i=2;i<=sqrt(a);i++){
		if (a%i==0){
			j+=1;
			return 0;
		}
		else{
			continue;
		}
		
	}
	if(j==0){
	return a;
	}
}
}

int main(){
	int i,t,l,n;
	int j = 0;
	printf("Enter the prime:");
	scanf("%d",n);
	t = prime(n);
	if (t==0){
		
		
	}
	else{
		for(i=1;i<=n;i++){
			l = prime(i);
			if(l==0){
				continue;
			}
			else{
				j+=1;
			}
		}
	}
	printf("%d",j);
	return 9;
}


