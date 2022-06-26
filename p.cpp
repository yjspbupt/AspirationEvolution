#include<iostream>
#include<ctime>
#include<cmath>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
	int n=100;
	srand(time(0));
	for(int count=1;count<=20;count++)
	{
		ofstream fout;
		string file_name=to_string(count)+".txt";
		fout.open(file_name,ios::out);
		fout<<"p1,p2"<<endl;
		for(int i=0;i<n;i++)
		{
			int p1=rand()%1000+1000;
			int p2=rand()%1000+1000;
			int p3=rand()%1000+1000;
			double all=p1+p2+p3;
			fout<<p1/all<<","<<p2/all<<endl;
		}
	}
	
}
