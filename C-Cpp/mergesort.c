#include<stdio.h>
void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Merge(int arr[],int l1,int mid,int h2){
    int temp[h2-mid];
    int j =0;
    for(int i=mid+1;i<=h2;i++){
        while(j!=mid+1){
            if(arr[j]>arr[i]){
                temp[j] = arr[i];
                j++;
                break;
            }
            j++;
        }
    }
}
void Mergesort(int arr[],int l,int h){
    if(l<h){
        int mid = (l+h)/2;
        Mergesort(arr,l,mid);
        Mergesort(arr,mid+1,h);
        Merge(arr,l,mid,h);
    }
}
int main(){
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int a[2n];
    printf("Enter the elements one by one:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    Mergesort(a,0,n-1);
    for(int i = n;i<2n;i++){
        printf("%d ",a[i]);
    }
    return 9;
}