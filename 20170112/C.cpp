#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+20;
const int maxm = 1e6+20;
const int mol = 1e9+7;
long long pr[maxm];
vector<int> lis[maxm];
const long long v1 = 105379;
const long long v2 = 103903;
typedef pair<unsigned long long,unsigned long long> pii;
pii _hash(vector<int>& x){
    unsigned long long h1 = x.size();
    unsigned long long h2 = x.size();
    for(int i=0; i < x.size(); i++){
        h1 = h1*v1 + x[i];
        h2 = h2*v2 + x[i];
    }
    return make_pair(h1,h2);
}
map<pii,int> cnt;
main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    pr[0] = 1;
    for(int i=1; i < maxm;i++)
        pr[i] = (pr[i-1]*i)%mol;
    for(int i=0; i<n; i++){
        int num,x;
        cin >> num;
        for(int j=0;j < num; j++){
            cin >> x;
            lis[x].push_back(i);
        }
    }
    for(int i=1; i <= m; i++)
            cnt[_hash(lis[i])] ++;
    long long ans = 1;
    for(map<pii,int> :: iterator it = cnt.begin();it!=cnt.end();it++){
        ans = (ans*pr[it->second])%mol;
    }
    cout <<ans <<endl;
}
/*
2 2
2 2 1
2 1 2
*/
