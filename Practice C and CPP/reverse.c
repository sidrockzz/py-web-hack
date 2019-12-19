#include<stdio.h>

void printArray(int a[],int size);
void reverseArray(int a[],int start,int end);

void leftRotate(int a[],int d,int n){
  if(d==0)
   return;
  reverseArray(a,0,d-1);
  reverseArray(a,d,n-1);
  reverseArray(a,0,n-1);
}

void printArray(int a[],int size){
  int i;
  for(i=0;i<size;i++)
  printf("%d",a[i]);
}

void reverseArray(int a[],int start ,int end){
  int temp;
  while(start<end){
    temp=a[start];
    a[start]=a[end];
    a[end]= temp;
    start++;
    end--;
  }
}

int main()
{
  int a[]={1,2,3,4,5,6,7};
  int n = sizeof(a)/sizeof(a[0]);
  int d=2;
  d= d%n;
  leftRotate(a,d,n);
  printArray(a,n);
  return 0;
}
