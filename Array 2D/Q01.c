#include<stdio.h>
int main(){
   int m,n,sum=0;
    printf("enter the no of rows and coloumn: ");
    scanf("%d%d",&m,&n);
    int arr[n][m];
    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
         printf("Element - [%d],[%d] : ", i, j);
         scanf("%d",&arr[i][j]);
         sum += arr[i][j];
        }
    }
    printf("Sum of Matrix is:%d",sum);
    return 0;
}