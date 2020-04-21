#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int temp=n,sum=0;
    while(temp>0)
    {
      sum+=temp%10;
      temp/=10;
    }
  if(n%sum==0)
    cout<<"Harshad Number";
  else
    cout<<"Not Harshad Number";

}
