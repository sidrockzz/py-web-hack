#include<stdio.h>
struct point
{
 int x,y;
};

int main()
{
 struct point p1 ={0 , 1};
 p1.x = 20;
 printf("x =%d, y = %d",p1.x,p1.y);
 return 0;
}
