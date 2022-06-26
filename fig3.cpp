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
	ifstream fin_net,fin_p;
	
	string graph_type="complete";
	
	
	string net_file= graph_type+"_net.txt";
	string out_file="data\\"+ graph_type+"_data.txt";
	fout.open(out_file,ios::out);
	
	init_set(n);
	set_beta(n,1);
	double lambda[max_N];
	for(int i=0;i<n;i++)lambda[i]=1./n;
	set_lambda(n,lambda); 
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
	
	
	for(int i=1;i<=20;i++)
	{
		string p_file="p\\"+to_string(i)+".txt";
		fin_p.open(p_file,ios::in);
		
		string title;
		fin_p>>title;
		char foo;
		for(int j=0;j<n;j++)fin_p>>v[j].p1>>foo>>v[j].p2;
		cout<<i<<endl;
		operation(n,n*100000);
		fout<<get_abun_ind("AH")<<","<<get_abun_ind("AL")<<","<<get_abun_ind("BH")<<","<<get_abun_ind("BL")<<endl;
		fin_p.close();
	}
	
}
