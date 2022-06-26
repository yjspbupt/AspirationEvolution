#include<iostream>
#include<ctime>
#include<cmath>
#include<fstream>
#include<algorithm>
using namespace std;
int w[100][100];
int re_connect(int n)
{
	int a=rand()%n;
	
	int b=0;
	while(1)
	{
		b=rand()%n;
		if(b==a)continue;
		if(w[a][b])break;
	}
	
	
	int c=rand()%n;
	while(1)
	{
		c=rand()%n;
		if(c==a)continue;
		if(c==b)continue;
		if(w[a][c]==0)break;
	}
	
	w[a][b]=0;
	w[b][a]=0;
	w[a][c]=1;
	w[c][a]=1;
}

int dis[100][100];
void floyd(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dis[i][j]=n;
			if(w[i][j])dis[i][j]=1;
		}
		dis[i][i]=0;
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(dis[i][k]+dis[k][j]<dis[i][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
}
double clu(int n,int now)
{
	int lis[100];
	int num=0;
	for(int j=0;j<n;j++)
	{
		if(w[now][j])
		{
			lis[num++]=j;
		}
	}
	double ans=0;
	for(int j=0;j<num;j++)
	{
		for(int k=0;k<num;k++)
		{
			ans+=w[lis[j]][lis[k]];
		}
	}
	if(ans==0)return 0;
	ans/=(num-1)*num;
	return ans;
}
int main()
{
	srand(time(0));
	int n=100;
	ofstream fout;
	fout.open("small_world_net.txt",ios::out);
	for(int i=0;i<n;i++)
	{
		for(int j=-4;j<=4;j++)
		{
			if(j==0)continue;
			w[i][(i+j+n)%n]=1;
		}
	}
	double p=0.3;
	for(int i=0;i<n*p;i++)
	{
		re_connect(n);
	}
	
	double cluster=0,distance=0;
	for(int i=0;i<n;i++)
	{
		cluster+=clu(n,i);
	}
	cluster/=n;
	cout<<cluster<<endl;
	floyd(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			distance+=dis[i][j];
		}
	}
	distance/=((n-1)*n/2);
	cout<<distance<<endl;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			fout<<w[i][j]<<" ";
		}
		fout<<endl;
	}
}
