#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
vector<int> dinh[220];
bool thamc[220][220];
int thamd[220];
int q[220],la,fi;
void input(){
    cin>>n;
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        a--;b--;
        dinh[a].push_back(b);
        dinh[b].push_back(a);
    }
}
void BFS(int u){
    for(int i=0;i<n;i++) thamd[i]=-1;
    q[0]=u;
    thamd[u]=0;
    fi=0;la=0;
    int v;
    while(fi<=la){
        u=q[fi];
        fi++;
        for(int i=0;i<dinh[u].size();i++){
            v=dinh[u][i];
            if ((!thamc[u][v]) && (thamd[v]==-1)){
                thamd[v]=thamd[u]+1;
                la++;
                q[la]=v;
            }
        }
    }
}
int longestpath(int u){
    BFS(u);
    int v1=q[la];
    BFS(v1);
    int v2=q[la];
    //cout<<thamd[v2]<<endl;
    return thamd[v2];
}
void solve(){
    int l1,l2,ans=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<dinh[i].size();j++){
            for(int i2=0;i2<n;i2++)
                for(int j2=0;j2<dinh[i2].size();j2++) thamc[i2][dinh[i2][j2]]=false;
            thamc[i][dinh[i][j]]=true;
            thamc[dinh[i][j]][i]=true;
            l1=longestpath(i);
            l2=longestpath(dinh[i][j]);
            //cout<<endl;
            ans=max(ans,l1*l2);
        }
    }
    cout<<ans;
}
int main(){
    freopen("p2path.inp","r",stdin);
    freopen("p2path.out","w",stdout);
    input();
    solve();
    return 0;
}
