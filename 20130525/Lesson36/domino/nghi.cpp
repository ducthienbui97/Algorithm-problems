#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;

iii a[100010];
int n,res[100010];

stack<iii> st;

int main()
{
	freopen("DOMINO.INP","r",stdin);
	freopen("DOMINO.OUT","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i].first.first >> a[i].first.second,a[i].second=i,res[i]=1;
	sort(a,a+n);
	st.push(a[n-1]);st.push(a[n-1]);
	for(int i=n-2;i>=0;i--){
		while(a[i].first.first+a[i].first.second>st.top().first.first && st.size()>1){
		//	cout << st.top().second << endl;
			res[a[i].second]+=res[st.top().second],st.pop();
		}
		st.push(a[i]);
	}
	for(int i=0;i<n;i++) cout << res[i] << " ";
	return 0;
}
