#include<bits/stdc++.h>
void heap(int h[],int n){
	
int j,c,root,t;
for (j=0;j<n+1;j++){
c = n;	
while(c!=1){
		
	root = c/2;
	if(h[root]<h[c]){
		t = h[c];
		h[c] = h[root];
		h[root] = t;
	}
	c--;
}
}
}
int main(){
	clock_t start,end;
double cpu_time_used;
start = clock();
int n;
int i,j,c,root,t,temp;
printf ("Enter the no. of elements:\n");
scanf("%d",&n);
int h[n+1];
printf("Enter the elements:\n");
for (i=1;i<n+1;i++){
	scanf("%d",&h[i]); /*heap*/
}
heap(h,n);
printf("The max heap:\n");
for(i=1;i<n+1;i++){
	printf("%d\t",h[i]);
}
for(j=n;j>1;j--){
	temp = h[1];
	h[1] = h[j];
	h[j] = temp;
	heap(h,j-1);
}
printf("The sorted array is:\n");
for (j=1;j<n+1;j++){
	printf("%d\t",h[j]);
}















end = clock();
cpu_time_used = ((double)end-start)/CLOCKS_PER_SEC;
printf("Cpu time used is %f",cpu_time_used);

return 9;

}
