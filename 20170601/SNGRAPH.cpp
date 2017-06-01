#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5+30;
vector<pair<int,int> > edges;
int cnt[Maxn];
int root[Maxn];
int getValue(const pair<int,int> &x){
    return min(cnt[x.first],cnt[x.second]);
}
int cmp(const pair<int,int> &x, const pair<int,int> &y){
    return  getValue(x) < getValue(y);
}
int findroot(int x){
    if(x != root[x]) root[x] = findroot(root[x]);
    return root[x];
}
void solve(){
    edges.clear();
    vector<int> ans;
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cnt[i] = 0;
        root[i] = i;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        edges.emplace_back(x,y);
        cnt[x]++;
        cnt[y]++;
    }
    sort(edges.begin(),edges.end(),cmp);

    int num = n;
    for(int i=n-1;i>=0;i--){
        ans.push_back(num - 1);
        while(!edges.empty() && getValue(edges.back()) == i){
            int x = edges.back().first;
            int y = edges.back().second;
            x = findroot(x);
            y = findroot(y);
            edges.pop_back();
            if(x != y){
                root[x] = y;
                num --;
            }

        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout << ans[i] <<' ';cout <<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++) solve();
}
