#include<iostream>

using namespace std;
const int N=1e3+10;
int n,m;
int fa[2*N];

int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void un(int x,int y)
{
	int fx=find(x);
	int fy=find(y);

	if(fy>n) fa[fy]=fx;//保证根在[1,n]
	else fa[fx]=fy;	
}

int main(int argc, char const *argv[])
{
	cin>>n>>m;

	//init
	for(int i=1;i<=2*n;i++) fa[i]=i;

	while(m--)
	{
		char opt;int p,q;
		cin>>opt>>p>>q;

		if(opt=='F')
		{
			un(p,q);
		}
		else
		{
			un(p,q+n);
			un(p+n,q);
		}
	}

	//只查找[1,n]的根的个数
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		if(fa[i]==i)
			ret++;
	}
	cout<<ret<<endl;

	return 0;
}