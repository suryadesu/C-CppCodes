#include<stdio.h>
void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int l,int h){
    int pivot = arr[l];
    int i = l+1,j = h;
    while(i<j){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[j],&arr[l]);
    return j;
}
void Quicksort(int arr[],int l,int h){
    if(l<h){
        int res = partition(arr,l,h);
        Quicksort(arr,l,res-1);
        Quicksort(arr,res+1,h);
    }
}
int main(){
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements one by one:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    Quicksort(a,0,n-1);
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 9;
}