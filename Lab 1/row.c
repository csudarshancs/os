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
int rsum[len],csum[len];
for(int i=0;i<len;i++){
    int sum=0;
    for(int j=0;j<len;j++){
        sum +=arr[i][j];
    }
    rsum[i]=sum;
}
printf("Sum of Row:");
for(int i=0;i<len;i++){
    printf("%d ",rsum[i]);
}
for(int i=0;i<len;i++){
    int sum=0;
    for(int j=0;j<len;j++){
        sum +=arr[j][i];
    }
    csum[i]=sum;
}
printf("Sum of column:");
for(int i=0;i<len;i++){
    printf("%d ",csum[i]);
}
}