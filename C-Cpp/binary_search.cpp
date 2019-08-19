#include <stdio.h>
#define print printf
int key;
void binary(int a[],int l,int h){
	if(l<=h){
	
		int mid = (l+h)/2;
		
		if (a[mid] == key){
			print("Found at %d",mid);
		}
		else if(a[mid]<key){
			binary(a,mid+1,h);
		}
		else{
			binary(a,l,mid-1);
		}
	}
	else{
		print("Not found");
	}

	}
int main()
{	
	int n,c;
	int a[16];
	print("Enter the number of values");
	scanf("%d",&n);
	print("Enter %d values",n);
	for(c=0;c<n;c++){
		scanf("%d",&a[c]);
	}
	print("Enter key:\n");
	scanf("%d",&key);
	int l=0,h=n-1,mid;
	binary(a,l,h);
	return 6;
}

