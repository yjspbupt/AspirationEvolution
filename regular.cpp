#include<iostream>
#include<ctime>
#include<cmath>
#include<fstream>
#include<algorithm>
using namespace std;
int w[100][100];
int main()
{
	int n=100;
	ofstream fout;
	fout.open("regular_net.txt",ios::out);
	for(int i=0;i<n;i++)
	{
		for(int j=-2;j<=2;j++)
		{
			if(j==0)continue;
			w[i][(i+j+n)%n]=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			fout<<w[i][j]<<" ";
		}
		fout<<endl;
	}
}
