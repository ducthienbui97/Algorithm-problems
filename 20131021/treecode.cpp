#include <bits/stdc++.h>
#define elif else if
#define FORE(i,d) for(__typeof(d.begin()) i=d.begin();i!=d.end();i++)
#define FOR(i,d) for(int i=0;i<d.size();i++)
using namespace std;
priority_queue <int, vector<int> ,greater<int> > pq;
vector<int> a;
int see[100011];
main() {
#ifndef HYQ
    freopen("treecode.inp","r",stdin);
    freopen("treecode.out","w",stdout);
#endif // HYQ
    vector<pair<int,int> > ans;
    int n;
    cin>>n;
    a.resize(n);
    for(int i=1; i<n; i++) {
        cin>>a[i];
        see[a[i]]++;
        }
    for(int i=1; i<=n; i++) {
        if(!see[i]) pq.push(i);
        }
    for(int i=1; i<n; i++) {
        int u=pq.top();
        pq.pop();
        ans.push_back(make_pair(a[i],u));
        see[a[i]]--;
        if(!see[a[i]]) pq.push(a[i]);
        }
    sort(ans.begin(),ans.end());
    FORE(i,ans) printf("%d %d\n",i->first,i->second);
    }
