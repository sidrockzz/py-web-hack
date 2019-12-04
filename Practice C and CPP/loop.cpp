#include<iostream>
using namespace std;
int main()
{
 int c1 = 0,c2 = 0;
 for(int i=0;++c1&&i<10;i++)
  for(int j=0; ++c1&&j<100;j++); 
  
 for(int i=0;++c2&&i<100;i++)
  for(int j=0; ++c2&&j<10;j++);
 
 cout << "Count for first"<< c1<<endl;
 cout << "Count for second" << c2 << endl;
 return 0;
}

 
