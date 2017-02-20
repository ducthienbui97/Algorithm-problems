#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6+1;
int vs[Maxn];
int pr[Maxn];
int a,b,c,d,e;
string ans;
bool in_range(int l,int r,int v) {
    return l<=v && v<r;
    }
void trace(int x) {
    while(x)
    if(pr[x]+a==x){
        ans.push_back('+');
        x = pr[x];
        }
    else if(pr[x]*b == x){
        ans.push_back('*');
        x = pr[x];
        }
    else if(pr[x]==x*c){
        ans.push_back('/');
        x = pr[x];
        }
    else{
        ans.push_back('-');
        x = pr[x];
        }
    return;
    }
main() {
    freopen("B.inp","r",stdin);
    freopen("B.out","w",stdout);
    ios_base::sync_with_stdio(false);
    vs[0] = 1;
    ans = "Impossible";
    reverse(ans.begin(),ans.end());
    cin >> a >> b >> c >> d >> e;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int crr = q.front();
        if(crr == e) {
            ans = "";
            trace(e);
            break;
            }
        q.pop();
        if(in_range(0,Maxn,crr+a)&&!vs[crr+a]) {
            q.push(crr+a);
            vs[crr+a] = vs[crr] + 1;
            pr[crr+a] = crr;
            }
        if(in_range(0,Maxn,crr*b)&&!vs[crr*b]) {
            q.push(crr*b);
            vs[crr*b] = vs[crr]+1;
            pr[crr*b] = crr;
            }
        if(crr%c==0&&in_range(0,Maxn,crr/c)&&!vs[crr/c]) {
            q.push(crr/c);
            vs[crr/c] = vs[crr] + 1;
            pr[crr/c] = crr;
            }
        if(in_range(0,Maxn,crr-d)&&!vs[crr-d]) {
            q.push(crr-d);
            vs[crr-d] = vs[crr] + 1;
            pr[crr-d] = crr;
            }
        }

    reverse(ans.begin(),ans.end());
    cout << ans <<"\n";
    }
