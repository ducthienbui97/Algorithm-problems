#include <bits/stdc++.h>

using namespace std;
long long f(long long t){
    switch(t&3){
    case 0:
        return t;
    case 1:
        return 1;
    case 2:
        return t + 1;
    case 3:
        return 0;
    }
}
void solve(){
    long long l,h,n;
    long long d1,d2;
    cin >> l >> h >> n >> d1 >> d2;
    int x1 = (d1 - n)/l;
    int x2 = (d2 - n)/l;
    int y1 = (d1 - n)%l;
    int y2 = (d2 - n)%l;
    if(x1 > x2) swap(x1,x2);
    if(y1 > y2) swap(y1,y2);
    long long ans = 0;
    for(int i = x1; i <= x2; i++){
        ans = ans ^ f(l*i+y1 + n - 1)^f(l*i+y2 + n);
    }
    cout << (ans^f(n - 1)^f(n + l*h -1)) << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
}




