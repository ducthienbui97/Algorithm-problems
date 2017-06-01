#include <bits/stdc++.h>
using namespace std;
char c[111];
bool d[111];
void solve(){
    memset(d,0,sizeof d);
    cin >> (&c[1]);
    int n = strlen(c+1);
    for(int i=1;i<=n;i++){
        if(c[i] == 'm'){
            if(c[i-1]=='s' && !d[i-1]){
                d[i-1] = true;
            }else if(c[i+1]=='s' && !d[i+1]){
                d[i+1] = true;
            }
        }
    }
    int m = 0;
    int s = 0;
    for(int i=1;i<=n;i++)
        if(c[i]=='m') m++;
        else if(!d[i]) s++;
    if(m == s) cout << "tie\n";
    else if (m > s) cout << "mongooses\n";
    else cout << "snakes\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++) solve();
}
