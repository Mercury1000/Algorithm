#include<iostream>
using namespace std;

const int N=110;
int n,m;
int fa[N*N];
char a[N][N];

int dx[] = {0, 1, 1, 1};
int dy[] = {1, 1, 0, -1};

int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void un(int x, int y)
{
fa[find(x)] = find(y);
}

int main(int argc, char const *argv[])
{
	cin>>n>>m;
	//要涉及二维转一维，下标都从0开始
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];

	for(int i=0;i<n*m;i++) fa[i]=i;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j] == '.') continue;

			for(int k = 0; k < 4; k++)
			{
				int x = i + dx[k], y = j + dy[k];
				if(y >= 0 && a[x][y] == 'W')
				{
					un(i * m + j, x * m + y);
				}
			}
		}
	}
	int ret=0;
	for(int i = 0; i < n * m; i++)
	{
		// 一维转二维
		int x = i / m, y = i % m;
		// 找有几个根节点即可
		if(a[x][y] == 'W' && fa[i] == i) ret++;
	}
	cout << ret << endl;

	return 0;
}