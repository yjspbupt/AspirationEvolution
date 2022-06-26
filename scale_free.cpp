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
	fout.open("scale_free_net.txt",ios::out);
	for(int i=1;i<n;i++)w[0][i]=1,w[i][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			fout<<w[i][j]<<" ";
		}
		fout<<endl;
	}
}
