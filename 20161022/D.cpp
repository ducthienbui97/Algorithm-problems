#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pii;
main() {
    ios_base::sync_with_stdio(false);
    vector<pii> q;
    pii lm;
    int n;
    cin >> n;
    int ans = n;
    cin >> lm.first >> lm.second;
    q.resize(--n);
    for(int i = 0; i < n; i++) {
        cin>> q[i].first>>q[i].second;
        }
    sort(q.begin(),q.end());
    reverse(q.begin(),q.end());
    priority_queue <long long,vector<long long>,greater<long long> > pr;
    for(int i=0;;) {

        while(i<q.size()&&q[i].first>lm.first) {
            pr.push(q[i].second-q[i].first+1);
            i++;
            }
        ans = min(ans,(int)pr.size()+1);
        if(pr.empty()||lm.first<pr.top()) break;
        else {
            long long t = pr.top();
            pr.pop();
            lm.first -= t;
            }
        }
    cout << ans <<endl;
    }
