
#include <stdio.h>
int main()
{
    int m,n,zcount=0;
    printf("Please enter a sparse matrix.\n");
    printf("Enter row size: ");
    scanf("%d",&m);
    printf("Enter column size: ");
    scanf("%d",&n);
    int arr[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter element (%d,%d) :",i,j);
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==0)
                zcount++;
        }
    }
    if(zcount>m*n/2)
    {
        printf("Tuple representation of sparse matrix:\n");
        printf("Row\tColumn\tElement\n");
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]!=0)
                {
                    printf("%2d\t%2d\t%2d\n",i,j,arr[i][j]);
                }

            }
        }
    }
    else
        printf("The matrix is not sparse matrix!");
    return 0;
}