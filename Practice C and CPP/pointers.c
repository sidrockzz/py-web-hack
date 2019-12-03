#include<stdio.h>
int main()
{
 int arr[] = {10,20};
 int *p = arr;
 ++*p;
 printf("arr[0] = %d,arr[1] = %d,*p = %d",arr[0],arr[1],*p);
 return 0;
}
