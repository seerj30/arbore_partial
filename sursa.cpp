#include<iostream>
#include<fstream>
using namespace std;
int viz[50];

void citire(int &n,int a[50][50])
{
	int x,y;
	ifstream f("in.txt");
	f>>n;
	while(f>>x>>y)
		a[x][y]=a[y][x]=1;
}

void df(int vf,int n,int a[50][50])
{
	int k;
	viz[vf]=1;
	for(k=1;k<=n;k++)
		if(a[vf][k]==1 && !viz[k])
		{
			cout<<vf<<" "<<k<<"\n";
			df(k,n,a);
		}
}

int main()
{
	int n,a[50][50]={};
	citire(n,a);
	df(1,n,a);
	return 0;
}
