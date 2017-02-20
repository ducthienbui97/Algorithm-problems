#include <bits/stdc++.h>
#define elif else if
#define int long long
using namespace std;
const int Maxn=111;
int dis[Maxn][Maxn];
int root[Maxn];
int findroot(int t){
    if(root[t]==t) return t;
    return root[t]=findroot(root[t]);
}
main() {
    int n,k;
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        dis[i][j]=1000111000;
    for(int i=1;i<=n;i++)
        root[i]=i,dis[i][i]=0;

    int x,y,z;
    int t;
    while(k--){
        cin>>t;
        if(!t){
            cin>>x>>y;
            if(findroot(x)!=findroot(y)) puts("-1");
            else printf("%d\n",dis[x][y]);
        }
        else{
            cin>>x>>y>>z;
            root[findroot(x)]=findroot(y);
            dis[y][x]=dis[x][y]=min(dis[x][y],z);
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                   dis[j][x]=dis[x][j]=min(dis[j][x],dis[j][i]+dis[i][x]);
                   dis[j][y]=dis[y][j]=min(dis[j][y],dis[j][i]+dis[i][y]);
                }
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                 dis[i][j]=dis[j][i]=min(dis[i][j],min(dis[i][x]+dis[x][j],dis[i][y]+dis[y][j]));
            for(int i=1;i<=n;i++)
                dis[y][x]=dis[x][y]=min(dis[x][y],dis[x][i]+dis[i][y]);

        }
    }

}


