#include <stdio.h>
int main(){
    int len;
    printf("Enter size of array:");
    scanf("%d",&len);
    int arr[len][len];
    printf("Enter the multidimensional array:");
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Matrix:\n");
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int sum=0;
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(i>j){
                sum+=arr[i][j];
            }
        }
    }
    printf("Sum of left diagonal matrix:%d",sum);
}