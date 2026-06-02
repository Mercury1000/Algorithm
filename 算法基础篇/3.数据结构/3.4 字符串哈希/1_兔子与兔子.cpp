#include<iostream>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e6+10, P = 131;

ULL f[N],p[N];

void init_hash(string& s)
{
	p[0] = 1;
	for(int i=1;i<=s.size();i++)
	{
		f[i] = f[i-1] * P + s[i-1];
		p[i] = p[i-1] * P;
	}
}

ULL gethash(int l,int r)
{
	return f[r]-f[l-1]*p[r-l+1]; 
}

int main()
{
	string s;cin>>s;
	init_hash(s);
	int m;cin>>m;
	while(m--)
	{
		int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
		if(gethash(l1,r1)==gethash(l2,r2)) cout<< "Yes"<<endl;
		else cout << "No" <<endl;
	}
	return 0;
}