#include <bits/stdc++.h>
using namespace std;
vector<int> p;
vector<pair<pair<int,int>,int> > q;
const int MAX = 2e6+10;
int BIT[MAX];
void update(int x,int v) {
    while(x<MAX) {
        BIT[x] += v;
        x+=(x&-x);
    }
}
int get(int x) {
    int r =0;
    while(x > 0) {
        r += BIT[x];
        x-=(x&-x);
    }
    return r;
}
main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> vs;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        if(x==0) p.push_back(-1);
        else if(x==1) {
            int a;
            cin >> a;
            vs.push_back(a);
            p.push_back(a);
        } else {
            int k,a;
            cin >> k >> a;
            p.push_back(-2);
            vs.push_back(a);
            q.push_back(make_pair(make_pair(k,a),q.size()));
        }
    }
    sort(vs.begin(),vs.end());
    sort(q.begin(),q.end());
    vector<int> ans(q.size());
    int j = 0;
    stack<int> s;
    for(int i=0; i<p.size(); i++) {
        while(j<q.size() && i==q[j].first.first) {
            ans[q[j].second] = get(lower_bound(vs.begin(),vs.end(),q[j].first.second)-vs.begin());
            j++;
        }
        if(p[i]==-1) {
            if(!s.empty()) {
                update(upper_bound(vs.begin(),vs.end(),s.top())-vs.begin(),-1);
                s.pop();
            }
        } else if(p[i]>=0){
            update(upper_bound(vs.begin(),vs.end(),p[i])-vs.begin(),1);
            s.push(p[i]);
        }
    }
    while(j<q.size()) {
        ans[q[j].second] = get(lower_bound(vs.begin(),vs.end(),q[j].first.second)-vs.begin());
        j++;
    }
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] <<endl;
}
