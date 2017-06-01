#include <bits/stdc++.h>
#define head first
#define tail second
#define x first
#define y second
using namespace std;
typedef pair<int,int> point;
typedef pair<point,point> snake;
void solve() {
    int n;
    cin >> n;
    vector<snake> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].head.x >> v[i].head.y >> v[i].tail.x >> v[i].tail.y;
        if(v[i].head.x > v[i].tail.x)
            swap(v[i].head.x,v[i].tail.x);
        if(v[i].head.y > v[i].tail.y)
            swap(v[i].head.y,v[i].tail.y);
    }
    int ans = 1<<30;
    for(int x=1;x<=50;x++)
    for(int y=1;y<=50;y++){
        int time = 0;
        for(int i=0;i<v.size();i++)
            time = max(time,abs(min(v[i].tail.x,x) - max(v[i].head.x,x)) + abs(min(v[i].tail.y,y) - max(v[i].head.y,y)));
        ans = min(ans,time);
    }
    cout <<ans <<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i=0; i<t; i++) solve();
}

