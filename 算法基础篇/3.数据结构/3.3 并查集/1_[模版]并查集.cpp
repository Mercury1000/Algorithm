#include<iostream>

using namespace std;
const int N=2e5+10;
int n,m;
int fa[N];

int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(int argc, char const *argv[])
{
	cin>>n>>m;
	//初始化
	for(int i=1;i<=n;i++) fa[i]=i;

	int x,y,z;
	while(m--)
	{
		cin>>z>>x>>y;
		if(z==1)
		{
			int fx=find(x);
			int fy=find(y);
			fa[fx]=fy;
		}
		else
		{
			if(find(x)==find(y)) cout<<'Y'<<endl;
			else cout<<'N'<<endl;
		}
	}

	return 0;
}