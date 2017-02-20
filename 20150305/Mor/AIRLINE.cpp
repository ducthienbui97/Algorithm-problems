#include <bits/stdc++.h>
#define U first.first
#define X first.second
#define L second
using namespace std;
const int Max=1e5+20;
vector<pair<pair<int,int>,int> > E[Max];
map<int,int> D[Max];
set<pair<int,int> > iqueue;
queue<pair<int,int> > q;
main(){
    freopen("AIRLINE.INP","r",stdin);
    freopen("AIRLINE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int type,x,y,z;
        cin>>type>>x>>y>>z;
        if(!(--type)){
            E[x].push_back(make_pair(make_pair(y,1<<30),z));
        }else{
            swap(x,y);
            E[x].push_back(make_pair(make_pair(y,E[y].size()),z));
        }
    }
    D[1][1<<30]=0;
    iqueue.insert(make_pair(1,1<<30));
    q.push(make_pair(1,1<<30));
    while(!q.empty()){
        int x = q.front().first;
        int sz = q.front().second;
        int l = D[x][sz];
        iqueue.erase(q.front());
        q.pop();
        for(int i=0;i < min(int(E[x].size()),sz);i++){
        if(D[E[x][i].U].find(E[x][i].X)==D[E[x][i].U].end()||E[x][i].L+l<D[E[x][i].U][E[x][i].X]){
            D[E[x][i].U][E[x][i].X]=E[x][i].L+l;
            pair<int,int> Tmp = make_pair(E[x][i].U,E[x][i].X);
            if(iqueue.find(Tmp)==iqueue.end()){
                iqueue.insert(Tmp);
                q.push(Tmp);
            }
        }
        }
    }
    for(int i=2;i<=n;i++){
        int l= D[i].find(1<<30)==D[i].end()?-1:D[i][1<<30];
        printf("%d\n",l);
    }
}
