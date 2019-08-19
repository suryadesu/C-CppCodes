#include<bits/stdc++.h>
int key = 0;
void linear(int a[],int n){
	if(n == -1){
		printf("Not found");
	}
	else{
		if (a[n-1] == key){
			printf("Key found at %d",n-1);
		}
		else{
			linear(a,n-1);
		}
		
	}
}
void binary(int a[],int l, int h){
	if(l<=h){
		int mid = (l+h)/2;
		if(a[mid] == key){
			printf("Found at %d",mid);
		}
		else if(a[mid>key]){
			binary(a,mid+1,h);
		}
		else{
			binary(a,l,mid-1);
		}
	}
	else{
	
	printf("Key not found");
	}
}
int main(){
	int n,i;
	
	printf("Number of elements:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the values:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the key:\n");
	scanf("%d",&key);
	int l = 0;
	binary(a,l,n-1);
	return 9;
}
