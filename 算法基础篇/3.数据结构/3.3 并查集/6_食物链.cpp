#include<iostream>
using namespace std;
const int N=5e4+10;
int n,m;
int fa[3*N];//x+n表示x的食谱，x+2n表示x的天敌

int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void un(int x,int y)
{
	fa[find(x)]=find(y);
}
bool issame(int x,int y)
{
	return find(x)==find(y);
}
bool solve()
{
	int k,x,y;cin>>k>>x>>y;
	if(x>n||y>n) return false;
	
	if(k==1) //x和y是同类
	{
		if(issame(x+n,y)||issame(x+2*n,y)) return false;
		else 
		{
			un(x,y);
			un(x+n,y+n);
			un(x+2*n,y+2*n);
		}
	}
	else if(k==2) //x吃y
	{
		if(x==y) return false;

		if(issame(x,y)||issame(x+2*n,y)) return false;
		else
		{
			//a吃b,b吃c,c吃a
			un(x,y+2*n);
			un(x+n,y);
			un(x+2*n,y+n);
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	cin>>n>>m;
	//init
	for(int i=1;i<=3*n;i++) fa[i]=i;

	int ret=0;
	while(m--)
	{
		if(!solve()) ret++;//注意统计的是假话
	}

	cout<<ret<<endl;
	return 0;
}