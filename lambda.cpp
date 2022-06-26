#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;
double lambda[100];
void gene(int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		lambda[i]=rand()%1000+1000;
		sum+=lambda[i];
	}
	for(int i=0;i<n;i++)
	{
		lambda[i]/=sum;
	}
}

int main()
{
	srand(time(0));
	int n=100;
	
	for(int i=1;i<=20;i++)
	{
		gene(n);
		ofstream fout;
		string file_name;
		file_name=to_string(i)+".txt";
		fout.open(file_name,ios::out);
		fout<<1<<endl;
		for(int j=0;j<n;j++)fout<<lambda[j]<<" ";
	}
}
