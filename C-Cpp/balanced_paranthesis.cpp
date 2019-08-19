#include<bits/stdc++.h>
int isFull(int top,int n){
	if(top==n){
		return 1;
		
	}
	else{
		return 0;
	}
}
void Push(int x,int a[], int top,int n ){
	if(isFull(top,n) == 0){
	
		a[top] = x;
		top++;
	}
	else{
		printf("Stack is full\n");
	}
}
int isEmpty(int top){
	if (top == 0){
		return 1 ;
	}
	else{
		return 0;
	}
}
int Pop(int a[],int top){
	if (isEmpty(top) == 0){
		int k;
		top--;
		k= a[top];
		
		return k;
	}
	else {
		printf("Stack is empty\n");
	}
}

int Peek(int a[],int top){
	return a[top];
	 
}
void Display(int a[],int top){
	int i;
	
	for (i=0;i<top;i++){
		printf("The elements of the stack are:\n");
		printf("%d\n",a[i]);
		
	}
}
int main(){
	clock_t start,end;
double cpu_time_used;
start = clock();
int n,p;
char t;
printf("Enter the number of times to be checked:\n");
scanf("%d",n);
int i = 0;
while(i<n){
	printf("Enter the string:\n");
	scanf("%s",&t);
	for(p=0;p<len(t);p++){
		if (s[p]=="(" || s[p]=="{" || s[p]=="["){
			Push(s[p],a[],)
		}
	}
}



















end = clock();
cpu_time_used = ((double)end-start)/CLOCKS_PER_SEC;
printf("Cpu time used is %f",cpu_time_used);

return 9;

}
