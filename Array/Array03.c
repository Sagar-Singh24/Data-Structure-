#include <stdio.h>
int main() 
{
    int TD[] = {25, 28, 27, 30, 31, 29, 26};
    int n = sizeof(TD) / sizeof(TD[0]);

    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        sum += TD[i];
    }
    double average = (double)sum / n;
    printf("Average temperature for the week: %.2lf\n", average);

    int a = 0, b = 0;
    for (int i = 1; i < n; i++) 
    {
        if (TD[i] > TD[a]) 
        {
            a = i;
        }
        if (TD[i] < TD[b]) 
        {
            b = i;
        }
    }
    printf(" Hottest day: Day %d : %d\n", a + 1, TD[a]);
    printf(" Coldest day: Day %d : %d\n", b + 1, TD[b]);
   
    int temprange = TD[a] - TD[b];
    printf("Temperature range: %d\n", temprange);

    return 0;
}