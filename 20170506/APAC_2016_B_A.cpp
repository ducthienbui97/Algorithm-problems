#include <bits/stdc++.h>
using namespace std;
int dist[24][555][24];
vector<int> d[555];
vector<pair<int,int> > edges;
vector<vector<int> > w;
priority_queue<pair<int,int >, vector<pair<int,int > >, greater<pair<int,int > > > pr;
int n,m,k;
void find(int startTime){
    while(!pr.empty()) pr.pop();
    dist[startTime][1][startTime] = 0;
    pr.push(make_pair(0,1));
    while(!pr.empty()){
        int u = pr.top().second;
        int time = pr.top().first;
        int h = (time+startTime)%24;
//        cout << u <<" "<<h<<" "<<time<<endl;
        pr.pop();
        if(time > dist[startTime][u][h]) continue;
        for(int e:d[u]){
            int v;
            if(u==edges[e].first) v = edges[e].second;
            else v = edges[e].first;
            if(dist[startTime][v][h] > time + w[e][h]){
                dist[startTime][v][h] = w[e][h] + time;
                pr.push(make_pair(dist[startTime][v][h],v));
            }
        }
    }
}
void solve(int nTest) {
    memset(dist,0x3f,sizeof dist);
    edges.clear();
    w.clear();
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) d[i].clear();

    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        d[x].push_back(edges.size());
        d[y].push_back(edges.size());
        edges.push_back(make_pair(x,y));
        w.push_back(vector<int>(24));
        for(auto&v:w.back()) cin >> v;
    }
    for(int i=0;i<24;i++) find(i);
    cout << "Case #"<<nTest<<":";
    for(int i=0;i<k;i++){
        int d,s;
        cin >> d >> s;
        int ans = 1<<29;
        for(int i=0;i<24;i++)
            ans = min(ans,dist[s][d][i]);
        if(ans == 1<<29) ans = -1;
        cout <<' '<<ans;
    }
    cout <<'\n';
}
main() {
    freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}


