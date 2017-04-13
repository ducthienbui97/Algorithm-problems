#include <bits/stdc++.h>
using namespace std;
long long used[1111];
void solve(int nTest){
    int n,m;
    cin >> n >> m;
    priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > p;
    for(int i=0;i<n;i++){
        cin >> used[i];
    }
    long long l = 0,r = 100000000000000ll;
    long long your_time;
    while(l<=r){
        long long mid = (l+r)>>1;
        long long tmp = 0;
        for(int i=0;i<n;i++)
            tmp += mid/used[i] + 1;
        if(tmp >= m){
            your_time = mid;
            r = mid -1;
        }else l = mid+1;
    }
    for(int i=0;i<n;i++){
        int t = your_time/used[i];
        m-= t;
        p.push(make_pair(t*used[i],i));
    }
    int ans;
    for(int i=0;i<m;i++){
        int t = p.top().first;
        ans = p.top().second;
        p.pop();
    }
    cout <<"Case #"<<nTest<<": "<<ans+1 <<endl;

}
main(){
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
