#include<stdio.h>
patterns(int n){
 int i,j;
 for(i=1;i<=n;i++){
  for(j=1;j<=(2*n);j++){
//left pattern upper part 
 if(i>(n-j+1))
    printf(" ");
   else
    printf("*");
 if((i+n)>j)
 printf(" ");
 else
 printf("*");
}
printf("\n");
}
for(i=1;i<=n;i++){
 for(j=1;j<=(2*n);j++){
//lower part right pattern 
 if(i<j)
   printf(" ");
 else
   printf("*");
 if(i<=((2*n)-j))
  printf(" ");
 else
   printf("*");
 }
printf("\n");
}
}
int main(){
patterns(5);
return 0;
}
