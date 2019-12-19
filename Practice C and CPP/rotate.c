#include<stdio.h>

void printArray(int arr[], int size);

int gcd(int a, int b);

void leftRotate(int arr[], int d, int n){
  int i,j,k,temp;
  int g=gcd(d,n);
  for(i=0;i<g;i++){
    temp=arr[i];
    j=i;
    while(1){
      k=j+d;
      if(k>=n)
       k=k-n;
      if(k==i)
       break;
      arr[j]=arr[k];
      j=k;
    }
    arr[j]=temp;
  }
}

void printArray(int arr[],int n){
  int i;
  for(i=0;i<n;i++)
  printf("%d",arr[i]);
}
int gcd(int a,int b){
  if(b==0)
  return a;
  else
  return gcd(b,a%b);
}

int main(){
  int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
  leftRotate(arr,2,7);
  printArray(arr,7);
  getchar();
  return 0;
}
