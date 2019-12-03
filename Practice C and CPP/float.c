#include<stdio.h>
int main()
{
 float x= 0.1;
 if(x == 0.1)
  printf("IF");
 else if(x == 0.1f)
  printf("ELSE IF");
 else
  printf("ELSE");
 return 0;
}// prints the ELSE IF as the binary count will be same as of 0.1f 
