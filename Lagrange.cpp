/// Lagrange Interpolation
///Rafiqul Islam
/// 
/// Dept: CSE
#include<iostream>
#include<cstdio>
using namespace std;

// Declare Global Variable
double A[50],B[50],Denominator,Numerator,x,y;
int i,j,n;
class LAGRANGE
{
public:
    double lagrange(); // Declare a Function

};

/// Logic Behind the Lagrange interpolation
double LAGRANGE:: lagrange()
{
cout<<"How many Input:  ";
 cin>>n;
 cout<<"Input the value of X and Y: \n";
 for(i=0;i<=n;i++)
 {
     cin>>A[i]>>B[i];
 }
 cout<<"Input the value of X: ";
 cin>>x;
     for(i=0;i<=n;i++)
 {
     Numerator=1;
     Denominator=1;
     for(j=0;j<=n;j++)
    if(j!=i)
    {
        Numerator= Numerator * (x-A[j]);
        Denominator= Denominator* (A[i]-A[j]);
    }
    y= y+ (Numerator/Denominator)*B[i];
 }
 printf("Answer is:  y(%0.3lf)   =  %0.3lf\n",x,y);
}

int main()
{
    LAGRANGE obj; /// Declare Object
    obj.lagrange(); // Call Lagrange Function
}
