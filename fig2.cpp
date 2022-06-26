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
	
	string graph_type;
	
	double ind_beta;
	cin>>graph_type>>ind_beta;
	string net_file= graph_type+"_net.txt";
	string out_file="data\\"+ graph_type+"_data.txt";
	fout.open(out_file,ios::out);
	
	init_set(n);
	set_beta(n,1);
	set_p(n,1./3,1./3);
	set_asp(n,2.2,1.8);
	
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
	
	member=1;
	for(int i=1;i<=20;i++)
	{
		string lambda_file="lambda\\"+to_string(i)+".txt";
		fin_lambda.open(lambda_file,ios::in);
		double lambda[max_N];
		
		v[member].beta=ind_beta;
		
		for(int j=0;j<n;j++)fin_lambda>>lambda[j];
		set_lambda(n,lambda);
		cout<<i<<endl;
		operation(n,n*100000);
		fout<<get_abun_ind("AH")<<","<<get_abun_ind("AL")<<","<<get_abun_ind("BH")<<","<<get_abun_ind("BL")<<endl;
		fin_lambda.close();
	}
	
}
