#include<iostream>
#include<string>
using namespace std;
class Employee
{
private:
	string name;
	string address;
	string city;
	string mail;
public:
	void show();
	void change(string n,string a,string c,string m)
	{

	name=n;
	address=a;
	city=c;
	mail=m;


	}
};
 void Employee::show()
{
	cout<<"name:"<<name<<' ';
	cout<<"address:"<<address<<' ';
	cout<<"city:"<<city<<' ';
	cout<<"mail:"<<mail<<endl;
}


int main()
{
	string n,a,c,m;
	int i,num;
	Employee s[5];
	for(i=0;i<5;i++)
	{
		cin>>n>>a>>c>>m;
		s[i].change(n,a,c,m);
	}
	cin>>num;
	cin>>n>>a>>c>>m;
	s[num-1].change(n,a,c,m);
	for(int i=0;i<5;i++)
		s[i].show();
	return 0;
}
