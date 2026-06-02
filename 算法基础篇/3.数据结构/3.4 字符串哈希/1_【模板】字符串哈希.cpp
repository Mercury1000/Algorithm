#include<iostream>
#include<set>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e4+10, P = 131;

int n;

set<ULL> st;

int main()
{
	cin>>n;
	while(n--)
	{
		string s;cin>>s;
		ULL ret=0;
		for(int i=0;i<s.size();i++)
		{
			ret = ret * P +s[i];
		}

		st.insert(ret);
	}
	cout<< st.size() <<endl;
}