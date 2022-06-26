#include<iostream>
#include<ctime>
#include<cmath>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
	int n=100;
	ofstream fout;
	fout.open("complete_net.txt",ios::out);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)fout<<0<<" ";
			else fout<<1<<" ";
		}
		fout<<endl;
	}
}
