#include <bits/stdc++.h>
using namespace std;
vector<int> d[200022];
long long cnt[6];
long long F[200022][6];
long long S[200022];
int n,k;
long long ans;
void dfs(int u,int p){
    F[u][0] = 1;
    S[u] = 1;
    for(int v:d[u]){
        if(v != p){
            dfs(v,u);
            S[u] += S[v];
            for(int i=0;i<k;i++)
                for(int j=0;j<k;j++)
                cnt[(j+i)%k] += F[u][i]*F[v][j];
            for(int i=0;i<k;i++)
                F[u][i] += F[v][i];
        }
    }
    ans += (S[u])*(n-S[u]);
    for(int i=k-1;i>0;i--)
        swap(F[u][i-1],F[u][i]);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    dfs(1,-1);
    for(int i=1;i<k;i++)
        ans -= cnt[i]*i;
    ans /= k;
    for(int i=1;i<k;i++)
        ans += cnt[i];
    cout << ans <<endl;
}
