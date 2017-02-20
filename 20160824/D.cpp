#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e2;
const int MaxMax = 1e5+1;
int a[Maxn];
int ls[MaxMax];
int ans[Maxn];
int n,s;
void input(){
    cin >> n;
    cin >> s;
    for(int i=0;i<n;i++)
        cin >> a[i];
}
void preprocess(){
    memset(ls,-1,sizeof ls);
    ls[0]=0;
    for(int j=0;j<n;j++)
    for(int i=a[j];i<MaxMax;i++)
        if(ls[i-a[j]] >= 0){
            ls[i] = j+1;
        }
}
bool in_range(int l,int r,int v){
    return l<=v && v<r;
}
void fill(int x,int v){
    while(x){
        int tmp = ls[x]-1;
        ans[tmp] +=v;
        x -= a[tmp];
    }
}
void solve(){
    for(int i=1;i<MaxMax;i++)
    if(ls[i] >= 0 && ls[s%i] >=0){
        fill(i,s/i);
        fill(s%i,1);
        return;
    }
}
void print(){
    for(int i=0;i<n;i++)
        cout << ans[i]<<' ';
}
main(){
    freopen("D.inp","r",stdin);
    freopen("D.out","w",stdout);
    ios_base::sync_with_stdio(false);
    input();
    preprocess();
    solve();
    print();
}
