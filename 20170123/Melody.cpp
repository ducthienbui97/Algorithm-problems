#include <bits/stdc++.h>
using namespace std;
int a[15];
int F[1<<15][15];
int done[1<<15][15];
int n;
int get(int st,int last){
    if(!((1<<last)&st)) return 0;
    if(done[st][last]) return F[st][last];
    done[st][last] = true;
    F[st][last] = 0;
    for(int i=0;i<n;i++)
    if(!((1<<i)&st))
        F[st][last] = max(F[st][last],__gcd(a[last],a[i])+get(st|(1<<i),i));
    return F[st][last];
}
main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    int ans = 0;
    for(int i=0;i<n;i++)
        ans = max(ans,get(1<<i,i));
    cout << ans <<endl;
}
