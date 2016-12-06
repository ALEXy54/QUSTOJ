#include<iostream>
using namespace std;

int main()
{
	int i,j,n,m,k;
	int p[100][100];
	cin>>k;
	for(int q=0;q<k;q++)
	{
		cin>>n>>m;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>p[i][j];
	for(i=0;i<m;i++)
		{
		for(j=0;j<n-1;j++)
			cout<<p[j][i]<<' ';
		cout<<p[j][i];
		cout<<endl;
		}
	}
	return 0;
}
