#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n;

struct node
{
int x, y, e;
}a[N];

//并查集
int fa[N*2];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

//离散化
int pos;
int disc[N*2];
unordered_map<int,int> mp;

bool solve()
{
	cin>>n;
	//清空数据
	pos = 0;
	mp.clear();
	//先存入数据到结构体中,然后离散数据
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].e;
		disc[++pos]=a[i].x;disc[++pos]=a[i].y;
	}

	int cnt=0;
	for(int i=1;i<=pos;i++)
	{
		if(mp.count(disc[i])) continue;
		mp[disc[i]]=++cnt;
	}

	//初始化并查集
	for(int i=1;i<=cnt;i++) fa[i]=i;

	//先拿出所有相等信息，维护并查集
	for(int i=1;i<=n;i++)
	{
		if(a[i].e==1)
		{
			int fx=find(mp[a[i].x]);
			int fy=find(mp[a[i].y]);
			fa[fx]=fy;
		}
	}

	for(int i=1;i<=n;i++)
	{
		if(a[i].e==0)
		{
			if(find(mp[a[i].x])==find(mp[a[i].y]))
				return false;
		}
	}

	return true;
}

int main()
{
	int T;cin>>T;
	while(T--)
	{
		if(solve()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;	
	}
	return 0;
}