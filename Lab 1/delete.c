#include <stdio.h>

int main(){
    int size;
    printf("Enter the size of array:");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        printf("Enter the element to insert:");
        scanf("%d",&arr[i]);
    }
    printf("Elements of array:\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    
    int pos;
    printf("\nEnter the position to delete:");
    scanf("%d",&pos);
    for(int i=pos-1;i<size;i++){
        arr[i]=arr[i+1];
    }
    printf("Elements of array:\n");
    for(int i=0;i<size-1;i++){
        printf("%d ",arr[i]);
    }
    
}