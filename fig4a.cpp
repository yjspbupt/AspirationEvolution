#include<string>
#include"gene.h"
//int stra;//0 for A, 1 for B
//int expe;//0 for high, 1 for low
int main()
{
	int n=100;
	matrix[0][0]=2.5;
	matrix[0][1]=1.5;
	matrix[1][0]=2.1;
	matrix[1][1]=1.9;
	ofstream fout;
	ifstream fin_net,fin_lambda;
	
	string net_file= "complete_net.txt";
	string out_file="Fig4a.txt";
	fout.open(out_file,ios::out);
	
	init_set(n);
	set_beta(n,1);
	v[member].beta=0.1;
	set_p(n,1./3,1./3);
	set_asp(n,2.2,1.8);
	double lambda[max_N];
	for(int i=0;i<n;i++)lambda[i]=1./n; 
	set_lambda(n,lambda);
	fin_net.open(net_file,ios::in);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			fin_net>>w[i][j];
		}
	}
	normal_graph(n);
	
	fout<<"AH"<<","<<"AL"<<","<<"BH"<<","<<"BL"<<endl;
	
	
	for(int i=-10;i<=10;i++)
	{	
		cout<<i<<endl;
		matrix[0][0]=2.5+i*0.05;
		operation(n,n*100000);
		fout<<get_abun_ind("AH")<<","<<get_abun_ind("AL")<<","<<get_abun_ind("BH")<<","<<get_abun_ind("BL")<<endl;
	}
	
}
