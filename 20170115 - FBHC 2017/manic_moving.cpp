#include <bits/stdc++.h>
using namespace std;
vector<int> S;
vector<int> D;
vector<int> d[111];
int n,m,k;
int w[111][111];
int F[111][5555][3];
priority_queue<pair<pair<int,int>,pair<int,int> > > pr;
void run(int numtest){
    while(!pr.empty()) pr.pop();
    memset(w,0x3f,sizeof w);
    memset(F,0x3f,sizeof F);
    cin >> n >> m >> k;
    int ans = -1;
    for(int i=0; i <m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        w[x][y] = min(w[x][y],z);
        w[y][x] = min(w[y][x],z);
        d[x].push_back(y);
        d[y].push_back(x);
    }
    S.resize(k+1);
    D.resize(k+1);
    for(int i=1;i <= k; i++)
        cin >> S[i] >> D[i];
    pr.push(make_pair(make_pair(-0,1),make_pair(0,0)));
    F[1][0][0] = 0;
    while(!pr.empty()){
        int used = -pr.top().first.first;
        int note = pr.top().first.second;
        int done = pr.top().second.first;
        int load = pr.top().second.second;
        pr.pop();
        if(F[note][done][load] < used) continue;
        if(done == k){
            ans = used;
            break;
        }
        if(load > 0 && D[done+1] == note && F[note][done+1][load -1] > used) {
            F[note][done+1][load -1] = used;
            pr.push(make_pair(make_pair(-used,note),make_pair(done+1,load-1)));
        }
        if(load < 2 && done + load + 1 <= k && S[done+load+1] == note && F[note][done][load+1] > used){
            F[note][done][load + 1] = used;
            pr.push(make_pair(make_pair(-used,note),make_pair(done,load+1)));
        }
        for(int i=0 ; i < d[note].size(); i++){
            int v = d[note][i];
            if(F[v][done][load] > used + w[note][v]){
                F[v][done][load] = used + w[note][v];
                pr.push(make_pair(make_pair(-used - w[note][v],v),make_pair(done,load)));
            }
        }
    }
    cout <<"Case #"<<numtest<<": "<<ans<<endl;
}
main(){
    freopen("manic_moving.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        run(i);
}
