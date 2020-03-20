#include<iostream>

using namespace std;

int main(void){
long long l,m,n,a,w;
cin >> n >> m >> a;
l =n/a;
w =m/a;

if(n % a!=0)l++;
if(m % a!=0)w++;

cout<<l*w<<endl;
return 0;

}
