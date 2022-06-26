#include<iostream>
#include<ctime>
#include<cmath>
#include<fstream>
#include<algorithm>
using namespace std;
int w[100][100];
int swap_edge(int n)
{
	int a=rand()%n;
	int b=rand()%n;
	if(a==b)return 0; 
	int c=0,d=0;
	while(1)
	{
		c=rand()%n;
		if(w[a][c])
		{
			break;
		}
	}
	while(1)
	{
		d=rand()%n;
		if(d==c)continue;
		if(w[b][d])
		{
			break;
		}
	}
	
	if(w[a][d]>0)return 0;
	if(w[b][c]>0)return 0;
	
	if(a==d||b==c)return 0;
	w[a][c]=0;
	w[b][d]=0;
	
	w[c][a]=0;
	w[d][b]=0;
	
	w[a][d]=1;
	w[b][c]=1;
	w[d][a]=1;
	w[c][b]=1;
	return 1;
}
int f[100]; 
int getf(int x)
{
	if(x==f[x])return x;
	return f[x]=getf(f[x]);
}
void merge(int x,int y)
{
	int u=getf(x),v=getf(y);
	f[u]=v;
}
int gen()
{
	srand(time(0));
	int n=100;
	ofstream fout;
	fout.open("random_regular_net.txt",ios::out);
	for(int i=0;i<n;i++)
	{
		for(int j=-2;j<=2;j++)
		{
			if(j==0)continue;
			w[i][(i+j+n)%n]=1;
		}
	}
	for(int count=0;count<n*10;count++)
	{
		while(!swap_edge(n));
	}
	for(int i=0;i<n;i++)f[i]=i;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(w[i][j]>0)merge(i,j);
		}
	}
	int root=getf(0);
	for(int i=0;i<n;i++)
	{
		if(getf(i)!=root)
		{
			return 0;
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
	
	return 1;
}
int main()
{
	while(!gen())
	{
	}
}
