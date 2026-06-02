#include<iostream>

using namespace std;
const int N=5e3+10;
int n,m,p;
int fa[N];

int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(int argc, char const *argv[])
{
	cin>>n>>m>>p;
	//init
	for(int i=1;i<=n;i++) fa[i]=i;

	while(m--)
	{
		int x,y;cin>>x>>y;
		int fx=find(x);
		int fy=find(y);
		fa[fx]=fy;
	}

	while(p--)
	{
		int x,y;cin>>x>>y;
		if(find(x)==find(y)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

	return 0;
}