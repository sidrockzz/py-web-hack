#include<stdio.h>
struct point
{
 int x,y,z;
};

int main()
{
 struct point p1 ={.y=0,.z=1,.x=2};
 struct point p2 ={.x=20};
 printf("x =%d,y =%d,z =%d",p1.x,p1.y,p1.z);
 printf("x =%d",p2.x);
 return 0;
}
