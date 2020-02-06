#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i,n,data[1000];
    float sum =0.0,average,sum1=0.0,variance,std_deviation;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&data[i]);
    }
    for (i = 0; i < n; i++)
    {
        sum = sum + data[i];
    }
    average = sum / (float)n;
    /*  Compute  variance  and standard deviation  */
    for (i = 0; i < n; i++)
    {
        sum1 = sum1 + pow((data[i] - average), 2);
    }
    variance = sum1 / (float)n;
    std_deviation = sqrt(variance);
    printf("%.1f",std_deviation);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

