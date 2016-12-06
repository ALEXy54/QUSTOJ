#include<iostream>
using namespace std;

class circle
{
public:
    circle(){}
    ~circle(){}


};

class cylinder:public circle
{
private:
    int height,radius;
public:
    cylinder(int h,int r){
    height=h;
radius=r;}
    ~cylinder(){}
    int volume();
};

int cylinder::volume()
{
  return 3*radius*radius*height;
}

class conic:public circle
{
private:
    int height,radius;
public:
    conic(int h,int r)
    {
    height=h;
    radius=r;
    }
    ~conic(){}
    int volume()
    {
        return radius*radius*height;
    }


};

int main()
{
int h1,h2,r1,r2;
cin>>h1>>r1>>h2>>r2;
cylinder c(h1,r1);
conic z(h2,r2);
cout<<c.volume()<<" "<<z.volume();
return 0;
}
