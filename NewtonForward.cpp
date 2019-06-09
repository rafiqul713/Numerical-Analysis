/// Newton Forward DIfference
///Rafiqul Islam
///
/// Dept: CSE

#include<iostream>
#include<cstdio>
using namespace std;
// here, variable are Declare as Global
double A[100];
double B[100][100],sum,temp,p,x;
int n,i,j;
class NEWTON_FROWARD
{
public:
    double newtonForward(); // Declare a function for Creating Forward Difference Table
    // Display function show the value of Newton Forward Difference table
    void display()
    {
        cout<<"--------------Newton Forward   Difference Table----------";
        cout<<endl<<endl;
        cout<<"Xi\t"<<"Yi\n\n";
        for(i=0;i<n;i++)
    {
        cout<<A[i]<<"\t";
        for(j=0;j<(n-i);j++)
        {
            cout<<B[i][j]<< "   ";
        }
        cout<<endl;
    }
    }

    int factorial(int n); // Declare a function for Factorail

    double forward_interplation_formula(); // Declare interpolation function
};

int NEWTON_FROWARD::factorial(int n)
{
    if(n==0)
    return 1;
    else
        return n* factorial(n-1);
}
/// Logic Behind the Newton Forward Table
double NEWTON_FROWARD :: newtonForward()
{
    int i,j;
    cin>>n;
    /// Input the value of x and y
    for(i=0;i<n;i++)
    {
        cin>>A[i]>>B[i][0];
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<(n-i);j++)
        {
            B[j][i] =  B[j+1][i-1] - B[j][i-1];
        }
    }
    display(); // Call display Function to showForward Difference Table
    forward_interplation_formula(); // Call forward interpolation formula

}
double NEWTON_FROWARD::forward_interplation_formula()
{
    double h;
    cout<<"Input X: ";
    cin>>x;
    h= (A[1]-A[0]); // we know that h = x1-x0
    cout<<"value of h: "<<h<<endl;
     p= (x-A[0] )  / h; // using formula  p= (x-x0) /h
     cout<<"Value of P: "<<p<<endl;
    sum = 0.0;
    /// Logic Behind the Newton Interpolation Formula

    for(i=0;i<n-1;i++)
    {
        temp=1;
        for(j=0;j<i;j++)
        {
            temp= temp* (p-j);
        }
        double fac;
            fac = factorial(i);
            sum = sum+ (temp *( B[0][i])/factorial(i));


    }
    cout<<"Result is:  ";
    printf("y(%lf) = %lf\n",x,sum);
}
int main()
{

NEWTON_FROWARD obj; // Declare the object of NEWTON_FORWARD class
obj.newtonForward(); // Call newtonForward()   function
return 0;
}
