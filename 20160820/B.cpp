#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> ppi;
const int Maxn= 1e5+20;
bool vs[Maxn];
vector<ppi> v;
main() {
    ios_base::sync_with_stdio(false);
    int m,n,k;
    v = vector<ppi>();
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x >> y>>z;
        v.push_back(ppi(z,pii(x,y)));
    }
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        vs[x]=true;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        int x = v[i].Y.X;
        int y = v[i].Y.Y;
        if(vs[x]^vs[y]){
            cout << v[i].X;
            return 0;
        }
    }
    cout << -1;
    return 0;
    }
