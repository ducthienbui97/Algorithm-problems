#include <bits/stdc++.h>
using namespace std;
int d[111];
int cnt[111];
bool vs[111];
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        d[i] = x;
        cnt[x] ++;
    }
    for(int i=1;i<=n;i++)
    if(!cnt[i]){
        cout <<"-1" <<endl;
        return 0;
    }
    int lcm = 1;
    for(int i=1;i<=n;i++)
    if(!vs[i]){
        int c = 1;
        int u = i;
        vs[i] = true;
        while(!vs[d[u]]) u = d[u],vs[u]=true,c++;
        c = c%2?c:c/2;
        lcm = lcm*c/__gcd(c,lcm);
    }
    cout << lcm <<endl;
}
