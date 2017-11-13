#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5+30;
int l[Maxn],r[Maxn],s[Maxn];
long long F[Maxn];
long long Ans[Maxn];
void _set(int idx, long long v){
    for(int i = idx; i < Maxn; i+= (i&-i))
        F[i] = max(F[i],v);
}
long long _get(int idx){
    long long ans = 0;
    for(int i = idx; i > 0; i -=(i&-i))
        ans = max(ans,F[i]);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int> > v;
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    for(int i = 1; i <= n; i++){
        cin >> l[i];
        l[i] = max(0,i - l[i] - 1);
        v.push_back(make_pair(l[i],i));

    }
    for(int i = 1; i <= n; i++){
        cin >> r[i];
        r[i] = min(n + 1,i + r[i] + 1);
    }
    sort(v.begin(),v.end());
    priority_queue<int> waiting;
    long long ans = 0;
    for(auto&u:v){
        int idx = u.second;
        while(!waiting.empty() && -waiting.top() <= l[idx]){
            int i = -waiting.top();
            waiting.pop();
            _set(r[i],Ans[i]);
        }
        Ans[idx] = _get(idx) + s[idx];
        ans = max(ans, Ans[idx]);
        waiting.push(-idx);
    }
    cout << ans << endl;
}
