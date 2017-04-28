#include <bits/stdc++.h>
using namespace std;
map<long long,vector<int> > st;
map<int,long long> maxx;
void solve(long long nTest) {
    st.clear();
    maxx.clear();
    long long n,x,y,a,b,c1,c2,m;
    cin >> n >> x >> y >> a >> b >> c1 >> c2 >> m;
    st[x].push_back(1);
    st[y+1].push_back(-1);
    for(int i=2;i<=n;i++){
        long long newX = (a*x%m+b*y%m+c1)%m;
        long long newY = (a*y%m+b*x%m+c2)%m;
        x = newX;
        y = newY;
        if(newX > newY) swap(newX,newY);
        st[newX].push_back(i);
        st[newY+1].push_back(-i);
       // cout << newX << " " << newY <<endl;
    }
    set<int> cur;
    long long last = 0;
    long long ans = 0;
    for(auto&it:st){
        if(cur.size() == 1) maxx[*cur.begin()] += it.first-last;
        if(cur.size() > 0) ans += it.first - last;
        last = it.first;
        for(int v:it.second){
            if(v<0) cur.erase(-v);
            else cur.insert(v);
        }
    }
    last = 0;
    for(auto&it:maxx)
        last = max(last,it.second);
    cout <<"Case #"<<nTest<<": "<<ans - last<<endl;
}
main() {
    freopen("C-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    long long t;
    cin >> t;
    for(long long i=1; i<=t; i++)solve(i);
}


