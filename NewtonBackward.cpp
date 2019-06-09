/// Newton Backward
///Rafiqul Islam
/// 
/// Dept: CSE

#include<iostream>
#include<cstdio>
using namespace std;

/// Declare Global Variable
double A[50],h,sum,temp,x,p,fac;
double B[50][50];
int n,i,j;

class NEWTON_BACKWARD
{
public:
    double newtonBackward(); // Declare a function to Calculate the Bacward Difference
    double backward_interpolation_formula(); //  Declare Interpolation Function
    void display()  // Declare Display function to show the Backward Table
    {
        cout<<"---------NEWTON BACKWARD Difference Table---------";
        cout<<endl<<endl;
        cout<<"Xi\t"<<"Yi\n\n";
        for(i=0;i<n;i++)
    {
        cout<<A[i]<<"\t";
        for(j=0;j<=i;j++)
        {
            cout<<B[i][j]<<"   ";
        }
        cout<<endl;
    }
    }
    double factorial(int n); // Declare a function for finding factorial
};

double NEWTON_BACKWARD:: factorial(int n)
{
    if(n==0)
        return 1;
        else
            return n*factorial(n-1);
}
/// Logic Behind the Newton Backward Difference Table

double NEWTON_BACKWARD :: newtonBackward()
{

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>A[i]>>B[i][0];
    }
 for(i=1;i<n;i++)
    {
        for(j=n-1;j>=(i-1);j--)
        {
            B[j][i] = B[j][i-1] - B[j-1][i-1];
        }
    }
    display(); // Call Display Function
    backward_interpolation_formula();
}

double NEWTON_BACKWARD :: backward_interpolation_formula()
{
    cout<<"Input the value of x:  ";
    cin>>x;
h = A[1] - A[0];  // h = X- X0
cout<<"value of h: "<<h<<endl;
p= (x- A[n-1]) / h;  // P=  (X- Xn)/ h
cout<<"value of p: "<<p<<endl;
sum = 0.0;
 for(i=0;i<n-1;i++)
    {
        temp=1;
        for(j=0;j<i;j++)
        {
            temp= temp* (p+j);
        }
            fac = factorial(i);
            sum = sum+ (temp *( B[n-1][i])/factorial(i));


    }
    printf("Result:  y(%0.3lf)    =   %0.3lf\n",x,sum);
}
int main()
{

NEWTON_BACKWARD obj;  /// Declare object
obj.newtonBackward(); /// Call  Function

}
