#include <bits/stdc++.h>
#define elif else if
using namespace std;
template <class T> T operator - (T a,T b){
    return T(a.first-b.first,a.second-b.second);
}
template <class T> int operator * (T a,T b){
    return a.first*b.second-a.second*b.first;
}
typedef pair<int,int>  pp;
int get(pp X,pp Y,pp Z){
    return abs((X-Y)*(Z-Y));
}
vector<int> E[555];
bool T[555][555];
map<vector<int> ,int> mp;
int ara[555],F[555][2];
bool vs[555];
vector<pp> V;
vector<int> nx[555][555];
vector<int> d[555];
pp root;

void dfs(int t){
    vs[t]=true;
    F[t][1]=ara[t];
    for(int i=0;i<d[t].size();i++){
        int v=d[t][i];
        if(vs[v]) continue;
        dfs(v);
        F[t][0]+=max(F[v][1],F[v][0]);
        F[t][1]+=F[v][0];
    }
}
bool cmp(int x,int y){
    return (V[x]-root)*(V[y]-root)>0;
}
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    V.resize(n);
    for(int i=0;i<n;i++)
        cin>>V[i].first>>V[i].second;
    for(int i=3;i<n;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        T[x][y]=true;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        T[i][(i+1)%n]=true;
        T[i][(i-1+n)%n]=true;
        E[i].push_back((i+1)%n);
        E[i].push_back((i-1+n)%n);
    }
    for(int i=0;i<n;i++){
        root=V[i];
        sort(E[i].begin(),E[i].end(),cmp);
        for(int j=1;j<E[i].size();j++){
            vector<int> tmp(3);
            tmp[0]=i;
            tmp[1]=E[i][j-1];
            tmp[2]=E[i][j];
            if(!T[tmp[1]][tmp[2]]) continue;
            sort(tmp.begin(),tmp.end());
            if(!mp.count(tmp)){
                mp[tmp]=mp.size();
                nx[tmp[0]][tmp[1]].push_back(mp.size());
                nx[tmp[0]][tmp[2]].push_back(mp.size());
                nx[tmp[1]][tmp[2]].push_back(mp.size());
                ara[mp.size()]=get(V[tmp[0]],V[tmp[1]],V[tmp[2]]);
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
    if(nx[i][j].size()==2){
        d[nx[i][j][0]].push_back(nx[i][j][1]);
        d[nx[i][j][1]].push_back(nx[i][j][0]);
    }
    int ans=0;
    for(int i=1;i<=mp.size();i++)
    if(!vs[i]) {
        dfs(i);
        ans+=max(F[i][0],F[i][1]);
    }
    printf("%.3lf",0.5*ans);
}
