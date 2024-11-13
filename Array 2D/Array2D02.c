#include<stdio.h>
void trans(int *ptr, int K, int L);
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
        }
    }
    trans(&arr[0][0],n,m);
    return 0;
}
void trans(int *ptr, int K, int L)
{
    int arr1[L][K];
    for(int i=0; i<L; i++)
    {
        for(int j=0; j<K; j++)
        {
            arr1[i][j]=*ptr;
            ptr++;
        }
    }
    printf("The transpose of matrix is:\n");
    for(int i=0; i<L; i++)
    {
        for(int j=0; j<K; j++)
        {
            printf("%d ",arr1[j][i]);
        }
        printf("\n");
    }
}
