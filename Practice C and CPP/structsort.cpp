#include<bits/stdc++.h>
using namespace std;
struct student
{
 string name;
 int math;
 int phy;
 int chem;
 int total;
 int rank;
};
//functions comparing two students according to the ranks
bool compareTwoStudents(student a,student b)
{
 //if total marks are not same then it returns for higher total value
 if(a.total != b.total)
  return a.total>b.total;
 // if marks in math are not same then returns true for higher marks
 if(a.math != b.math)
  return a.math>b.math;
 return(a.phy > b.phy);
}
void computeRanks(student a[],int n)
{
 //to calculate total marks for all students
 for(int i=0;i<n;i++)
  a[i].total = a[i].math + a[i].phy + a[i].chem;
 //sort the structure array using the user defined function comparetwostrings()
 sort(a,a+5,compareTwoStudents);
 for(int i=0;i<n;i++)
  a[i].rank = i+1;
}

int main()
{
 int n=5;
 student a[n];
 a[0].name= "Siddharth";
 a[0].math = 80;
 a[0].phy = 95;
 a[0].chem =100;

a[1].name= "Akash";
 a[1].math = 85;
 a[1].phy = 90;
 a[1].chem =95;

a[2].name= "Manas";
 a[2].math = 80;
 a[2].phy = 95;
 a[2].chem =100;
a[3].name= "Avinash";
 a[3].math = 80;
 a[3].phy = 95;
 a[3].chem =100;
a[4].name= "Saatwik";
 a[4].math = 80;
 a[4].phy = 95;
 a[4].chem =100;
computeRanks(a,n);return 0;
}
