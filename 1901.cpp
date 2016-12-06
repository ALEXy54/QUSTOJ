#include<iostream>
using namespace std;

class myclock
{
private:
    int hour,minute,second;
public:
    myclock(int hour=0,int minute=0,int second=0);
    ~myclock(){}
    void display() const;
    myclock& operator++();
    myclock operator++(int);
};
myclock::myclock(int hour,int minute,int second)
{
    this->hour=hour;
    this->minute=minute;
    this->second=second;

}
myclock myclock::operator++(int)
{
    myclock old=*this;
    ++(*this);
    return old;
}

void myclock::display()const
{
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}
myclock &myclock::operator++()
{
    second++;
    if(second>=60)
    {
        second-=60;
        minute++;
        if(minute>=60){
            minute-=60;
        hour=(hour+1)%24;}
    }
    return *this;
}

int main()
{
    int n;
int h,m,s;
char x;
cin>>n;

    for(int i=0;i<n;i++)
{
   cin>>h>>x>>m>>x>>s;
  myclock a(h,m,s);
   a.display();

    a++;
    (++a).display();

}
return 0;

}
