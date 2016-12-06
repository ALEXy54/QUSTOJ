#include<iostream>
using namespace std;

class Complex
{
private:
    double r,i;

public:
    Complex(double a=0,double b=0)
    {
       r=a;
       i=b;
    }
    Complex operator+(const Complex &a2)const;
    Complex operator-(const Complex &a2)const;
    void show();
};
Complex Complex::operator+(const Complex &a2)const
{
return Complex(r+a2.r,i+a2.i);
}
Complex Complex::operator-(const Complex &a2)const
{
return Complex(r-a2.r,i-a2.i);
}

void Complex::show()
{
    cout<<"("<<r<<","<<i<<")";
}

int main()
{
    double r1,i1,r2,i2;
    cin>>r1>>i1>>r2>>i2;
    Complex c3;
    Complex c1(r1,i1);
    Complex c2(r2,i2);
    c3=c2+c1;
    c3.show();
    c3=c1-c2;
    cout<<" ";
    c3.show();
    return 0;
}
