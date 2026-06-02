#include<iostream>
using namespace std;
const int N=3e4+10;
int n,m;
int fa[N],d[N],cnt[N];// 维护集合的合并、维护权值、维护集合的⼤⼩

int find(int x)
{
	if(fa[x]==x) return x;
	int fx =find(fa[x]);
	d[x]+=d[fa[x]];
	return fa[x]=fx;
}

void un(int x,int y)
{	
	int fx = find(x), fy =find(y); 
	if(fx != fy)
	{
		fa[fx]= fy;
		d[fx] = cnt[fy];
		cnt[fy]+=cnt[fx];
	}
}

int query(int x,int y)
{
	if(find(x)!=find(y)) return -1;

	return abs(d[y]-d[x])-1;
}

int main(int argc, char const *argv[])
{
	int T;cin>>T;

	for(int i=1;i<=3e4;i++) fa[i] = i,cnt[i]=1;

	while(T--)
	{
		char op;int i,j;
		cin>>op>>i>>j;
		
		if(op == 'M')
		{
			un(i,j);
		}
		else
		{
			cout<<query(i,j)<<endl;
		}
	}

	return 0;
}