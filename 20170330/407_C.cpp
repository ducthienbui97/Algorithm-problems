#include <bits/stdc++.h>
using namespace std;
int vs[3111];
vector<int> edges;
int main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    for(int i=0;i < k; i++){
        int x;
        cin >> x;
        edges.push_back(x-n);
    }
    sort(edges.begin(),edges.end());
    edges.resize(unique(edges.begin(),edges.end())-edges.begin());
    memset(vs,-1,sizeof vs);
    queue<pair<int,int> > q;
    q.push(make_pair(0,n+1000));
    while(!q.empty()){
        int s = q.front().first;
        int u = q.front().second;
        q.pop();
        for(int e:edges){
            int v = u+e;
            if(v>=0 && v < 3111 && vs[v] < 0){
                vs[v] = s+1;
                q.push(make_pair(vs[v],v));
            }
        }
    }
    cout <<vs[n+1000];
}
