#include <stdio.h>
#include<math.h>
void calMeanAndSD(int arr[], int n, float *mean, float *stdDev)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    *mean = (float)sum / n;

    float Diff = 0;
    float Dev;
    for (int i = 0; i < n; i++)
    {
        Diff += (arr[i] - *mean);
        Dev += (Diff * Diff);
        *stdDev = sqrt(Dev/ n);
    }
    
}

int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    float mean, stdDev;

    calMeanAndSD(arr, n, &mean, &stdDev);

    printf("Mean: %.2f\n", mean);
    printf("Standard Deviation: %.2f\n", stdDev);

    return 0;
}
