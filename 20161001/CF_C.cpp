#include <bits/stdc++.h>
using namespace std;
vector<int> pr;
vector<long long> a;
vector<int> q;
vector<long long> ans;
int getP(int x){
    if(x<0||x>=pr.size()) return -1;
    else if(pr[x] != x) return pr[x] = getP(pr[x]);
    else return x;
}

main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    a.resize(n);
    pr.resize(n);
    q.resize(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++){
        cin>>q[i];
        q[i]--;
        pr[i] = -1;
    }
    long long MAX = 0;
    reverse(q.begin(),q.end());
    for(int i=0;i < n; i++){
        ans.push_back(MAX);
        int x = q[i];
        pr[x] = x;
        int u = getP(x-1);
        int v = getP(x+1);
        if(u>=0){
            pr[u] = x;
            a[x] += a[u];
        }
        if(v>=0){
            pr[v]=x;
            a[x]+=a[v];
        }
        if(a[x] > MAX)
            MAX = a[x];
    }
    reverse(ans.begin(),ans.end());
    for(int i=0; i < n; i++)
        cout <<ans[i]<<endl;
}
