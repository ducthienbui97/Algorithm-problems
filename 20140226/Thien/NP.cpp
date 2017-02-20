#include <bits/stdc++.h>
#define elif else if
using namespace std;
int T[511][511];
int x[511];
main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int x,y,t;
        cin>>x>>y>>t;
        T[x][y]=T[y][x]=t;
        }
    int ans=0;
    for(int i=0; i<2000; i++) {
        for(int i=0; i<n; i++)
            x[i]=rand()&1;
        int rep=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                rep+=T[i][j]*x[i]*x[j];
        bool done=false;
        while(!done) {
            done=true;
            for(int i=0; i<n; i++) {
                int charge=0;
                int a=T[i][i]*(!x[i])-T[i][i]*x[i];
                for(int j=0; j<n; j++)if(i!=j)
                        a+=2*(T[i][j]*(!x[i])*x[j]-T[i][j]*(x[i])*x[j]);
                if(a>0) done=false,rep+=a,x[i]=!x[i];
                }
            }
        ans=max(ans,rep);
        }
    cout<<ans;
    }
