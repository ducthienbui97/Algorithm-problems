#include <bits/stdc++.h>
using namespace std;
void solve(int nTest){
    int n;
    cin >> n;
    vector<pair<int,int> > c;
    set<pair<int,int> > y;
    set<pair<int,int> > x;
    c.resize(n);
    for(auto&p:c){
        cin >> p.first >> p.second;
        y.insert(make_pair(p.second,p.first));
        x.insert(make_pair(p.first,p.second));
    }
    sort(c.begin(),c.end());
    bool ans = false;
    int maxX = x.rbegin()->first;
    int maxY = y.rbegin()->first;
    while(x.size()&&y.size()){
        if(x.rbegin()->second == maxY){
            ans = true;
            break;
        }
        while(x.size() && x.rbegin()->first == maxX){
            y.erase(make_pair(x.rbegin()->second,x.rbegin()->first));
            x.erase(*x.rbegin());
        }
        while(y.size() && y.rbegin()->first == maxY){
            x.erase(make_pair(y.rbegin()->second,y.rbegin()->first));
            y.erase(*y.rbegin());
        }
        if(x.size()) maxX = x.rbegin()->first;
        if(y.size()) maxY = y.rbegin()->first;
    }
    cout <<"Case #"<<nTest<<": "<<(ans?"YES":"NO")<<endl;
}
main(){
    freopen("D-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)solve(i);
}

