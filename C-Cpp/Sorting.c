#include<stdio.h>

void Sort(int a[],int b[],int l,int h,int n){
	
	int f=0,e=n;
	b[0] = a[l];
	int t;
	for(int j = l+1;j<h;j++){
		if(a[j]<=a[l]){
			t = b[f];
			b[f] = a[j];
			b[f+1] = t;
			f++;
		}
		else if(a[j] > a[l]){
			b[e] = a[j];
			e--;
		}
	}
	Sort(b,a,l,f,n);
	Sort(b,a,f+1,h,n);		
}			
int main(){
	int a[10]; //Declare an integer array of size 10
	int k;
	printf("Enter the 10 numbers\n");
	for(k=0;k<10;k++)
	{
		scanf("%d",&a[k]); //Store the 10 values in the array
	}
	int b[10];
	Sort(a,b,0,10,10);
	for(k=0;k<10;k++){
		printf("%d ",a[k]);
	}
	return 9;
}		
