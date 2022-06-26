#include<iostream>
#include<ctime>
#include<cmath>
#include<fstream>
#include<algorithm>
using namespace std;

typedef long long ll;
const int max_N=200,mod=998244353;
double w[max_N][max_N];
double matrix[2][2];

struct rand_struct
{
	ll seed;
	ll now;
}rs;
void init_rand()
{
	srand(time(0));
	rs.now=1;
	rs.seed=((ll)rand()*(ll)rand()+(ll)rand())%mod;
}
int ran(int n)
{
	rs.now=rs.now*rs.seed%mod;
	return rs.now%n;
}
bool event(double p)
{
	return ran(mod)<p*mod;
}
double femi(double x)
{
	return 1./(1.+exp(-x));
}
struct node
{
	double lambda,sum_lam;
	double p1,p2;
	double (*g)(double );
	double e[2],beta;//e[0] for aH, a[1] for aL 
	int stra;//0 for A, 1 for B
	int expe;//0 for high, 1 for low
	bool is_change(double);
}v[max_N];
bool node::is_change(double benefit)
{
	return event(g(beta*(e[expe]-benefit)));
}
int pick(int n)//update a node based on the lambda
{
	double temp=ran(mod)*1.0/mod;
	int l=0,r=n-1;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(v[mid].sum_lam<temp)
		{
			l=mid;
		}
		else if(v[mid].sum_lam-v[mid].lambda>temp)
		{
			r=mid;
		}
		else return mid;
	}
	if(v[l].sum_lam>temp&&temp>v[l].sum_lam-v[l].lambda)
	{
		return l;
	}
	return r;
}

int member=0;
long long type[2][2],temp[2][2];//[strategy][aspiration]
long long type_per[2][2];
void operation(int n,int T)
{
	int pre_T=T;
	
	for(int j=0;j<2;j++)
	{
		for(int k=0;k<2;k++)type[j][k]=0,temp[j][k]=0;
	}

	for(int j=0;j<2;j++)
	{
		for(int k=0;k<2;k++)type_per[j][k]=0;
	}
	
	for(int i=0;i<n;i++)
	{
		temp[v[i].stra][v[i].expe]++;
	}
	bool flag=0;
	while(T--)
	{
		int i=pick(n);
		double pi=0;
		for(int j=0;j<n;j++)
		{
			pi+=w[i][j]*matrix[v[i].stra][v[j].stra];
		}
		if(v[i].is_change(pi))//change 
		{
			int opt=ran(mod);
			temp[v[i].stra][v[i].expe]--;
			if(opt<mod*v[i].p1)//p1
			{
				v[i].stra=1-v[i].stra;
			}
			else if(opt<mod*(v[i].p1+v[i].p2))//p2
			{
				v[i].expe=1-v[i].expe;
			}
			else//p3
			{
				v[i].stra=1-v[i].stra;
				v[i].expe=1-v[i].expe;
			}
			temp[v[i].stra][v[i].expe]++;
		}
		if(T<pre_T*0.9)flag=1;
		if(flag)
		{
			for(int k=0;k<2;k++)
				for(int l=0;l<2;l++)type[k][l]+=temp[k][l];
			
			type_per[v[member].stra][v[member].expe]++;
		}
	}
}
double get_abun(string opt,double AH,double AL,double BH,double BL)
{
	double ALL=AH+AL+BH+BL;
	if(opt=="A")
	{
		return (AH+AL)/ALL;
	}
	if(opt=="B")
	{
		return (AH+BH)/ALL;
	}
	if(opt=="H")
	{
		return (AL+BL)/ALL;
	}
	if(opt=="L")
	{
		return (BH+BL)/ALL;
	}
	if(opt=="AH")
	{
		return AH/ALL;
	}
	if(opt=="AL")
	{
		return AL/ALL;
	}
	if(opt=="BH")
	{
		return BH/ALL;
	}
	if(opt=="BL")
	{
		return BL/ALL;
	}
	return 0;
}
double get_abun_pop(string opt)
{
	double AH=type[0][0],AL=type[0][1],BH=type[1][0],BL=type[1][1];
	return get_abun(opt,AH,AL,BH,BL);
}
double get_abun_ind(string opt)
{
	double AH=type_per[0][0],AL=type_per[0][1],BH=type_per[1][0],BL=type_per[1][1];
	return get_abun(opt,AH,AL,BH,BL);
}
void init_set(int n)
{
	init_rand();
	for(int i=0;i<n;i++)
	{
		v[i].g=&femi;
		v[i].expe=ran(2);
		v[i].stra=ran(2);
	}
}
void set_beta(int n,double beta)
{
	for(int i=0;i<n;i++)
	{
		v[i].beta=beta;
	}
}
void set_lambda(int n,double lambda[])
{
	for(int i=0;i<n;i++)
	{
		v[i].lambda=lambda[i];
	}
	v[0].sum_lam=v[0].lambda;
	for(int i=1;i<n;i++)
	{
		v[i].sum_lam=v[i-1].sum_lam+v[i].lambda;
	}
}
void set_p(int n,double p1,double p2)
{
	for(int i=0;i<n;i++)
	{
		v[i].p1=p1;
		v[i].p2=p2; 
	}
}
void set_asp(int n,double H,double L)
{
	for(int i=0;i<n;i++)
	{
		v[i].e[0]=H;
		v[i].e[1]=L; 
	}
}

void clear_graph(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			w[i][j]=0;
		}
	}
}
void normal_graph(int n)
{
	for(int i=0;i<n;i++)
	{
		double all=0;
		for(int j=0;j<n;j++)
		{
			all+=w[i][j];
		}
		for(int j=0;j<n;j++)
		{
			w[i][j]/=all;
		}
	}
}
