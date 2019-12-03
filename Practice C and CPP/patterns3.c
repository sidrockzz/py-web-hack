#include<stdio.h>
int main(){
int s,n,y,x;
printf("Enter the no of stars to be printed \n");
scanf("%d",&n);
//for the top part
for(x=0;x<=n;x++){
 for(s=n;s>x;s--) printf(" ");
 for(y=0;y<x;y++) printf("*"); printf("\n");
}
for(x=1;x<n;x++)
{
 for(s=0;s<x;s++) printf(" ");
 for(y=n;y>x;y--) printf("*"); printf("\n");
}
return 0;
}
