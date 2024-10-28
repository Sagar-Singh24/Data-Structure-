#include<stdio.h>
int main()
{
    int test_scores[20]={85,78,92,65,89,76,94,81,87,90,72,88,95,79,83,91,70,84,86,93};
    int sum=0,count=0,count2=0;
    for(int i=0;i<20;i++)
    {
        for(int j=i+1;j<20;j++)
        {
            if(test_scores[i]<test_scores[j])
            {
                int temp;
                temp=test_scores[i];
                test_scores[i]=test_scores[j];
                test_scores[j]=temp;
            }
        }
    }
    for(int i=0;i<20;i++)
    {
        sum+=test_scores[i];
    }
    printf("Average score is-%.2f\n",sum/20.0f);
    printf("Highest score is-%d\n",test_scores[0]);
    for(int i=0;i<20;i++)
    {
        if(test_scores[i]<60)
        count++;
        else
        count2++;
    }
    printf("No. of passed-%d\nNo. of failed-%d",count2,count);
    int o,e,a,b,f;
    o=a=e=b=f=0;
    for(int i=0;i<20;i++)
    {
        if(test_scores[i]>=90&&test_scores[i]<=100)
        o++;
        else if(test_scores[i]>=80&&test_scores[i]<90)
        e++;
        else if(test_scores[i]>=70&&test_scores[i]<80)
        a++;
        else if(test_scores[i]>=60&&test_scores[i]<70)
        b++;
        else if(test_scores[i]<60)
        f++;
    }
    printf("Number of students with grade o:%d\n",o);
    printf("Number of students with grade e:%d\n",e);
    printf("Number of students with grade a:%d\n",a);
    printf("Number of students with grade b:%d\n",b);
    printf("Number of students with grade f:%d\n",f);
    return 0;
}