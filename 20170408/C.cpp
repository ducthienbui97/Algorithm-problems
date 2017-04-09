#include <bits/stdc++.h>
using namespace std;
long long n,k;
priority_queue<pair<long long,long long> >pr;
void solve(int numTest) {
    cin >> n >> k;
    while(!pr.empty()) pr.pop();
    pr.push(make_pair(n,1));
    while(true){
        long long len = pr.top().first;
        long long cnt = 0;
        while(!pr.empty() && pr.top().first == len){
            cnt += pr.top().second;
            pr.pop();
        }
        long long r = len >>1;
        long long l = r - 1 + (len&1);
        if(cnt >= k){
            cout <<"Case #"<<numTest<<": "<<r<<" "<<l<<endl;
            return;
        }else{
            k-=cnt;
            pr.emplace(l,cnt);
            pr.emplace(r,cnt);
        }
    }
}
main() {
   freopen("C-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}

