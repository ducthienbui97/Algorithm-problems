#include <bits/stdc++.h>
using namespace std;
int ans,n;
char c[25][25];
bool used[25];
bool worker[25];

bool ok(int t){
    if(t==n) return true;
    for(int w = 0; w < n; w++)
    if(!worker[w]){
        worker[w] = true;
        bool k = true;
        int cnt =0;
        for(int i=0;i<n && k;i++)
        if(!used[i] && c[w][i] == '1'){
            used[i] = true;
            k &= ok(t+1);
            cnt++;
            used[i] = false;
        }
        worker[w] = false;
        if(!cnt||!k) return false;
    }
    return true;
}
void bt(int x,int y,int spent){
    //cout << x <<" "<<y <<" "<<spent<<endl;
    if(spent > ans) return;
    if(y==n){
        bt(x+1,0,spent);
        return;
    }
    if(x==n){
        if(ok(0)) ans = spent;
        return;
    }
    bt(x,y+1,spent);
    if(c[x][y] != '1'){
        c[x][y] = '1';
        bt(x,y+1,spent+1);
        c[x][y] = '0';
    }
}
void solve(int nTest){
    cin >> n;
    ans = n*n;
    for(int i=0;i<n;i++)
        cin >> c[i];
    bt(0,0,0);
    cout << "Case #"<<nTest<<": " << ans<<endl;
}
main(){
    freopen("D-small-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}



