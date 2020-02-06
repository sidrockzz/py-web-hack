#include<stdio.h>
int main(){
int n,sum=0;
int a[100];
scanf("%d",&n);
for(int i=0;i<n;i++){
scanf("%d",&a[i]);
}
for(int i=0;i<n;i++){
sum=a[i]+sum;
}

printf("%d\t",sum);
return 0;
}

