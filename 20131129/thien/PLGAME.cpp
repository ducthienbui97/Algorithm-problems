#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define elif else if
using namespace std;
int F[4][1011][4][1011];
bool done[4][1011][4][1011];
char C[4][1011];
int n;
int xx[]={-1,0,1};
 bool out(int x,int y){
    if(x>3||x<1) return true;
    if(y>n||y<1) return true;
    return false;
}
 bool ok(int x1,int y1,int x2,int y2){
    if(out(x1,y1)||out(x2,y2)) return false;
    return (C[x1][y1]==C[x2][y2]);
}
int f(int x1,int y1,int x2,int y2){
    if(done[x1][y1][x2][y2]) return F[x1][y1][x2][y2];
    done[x1][y1][x2][y2]=true;
    if(y1==y2) F[x1][y1][x2][y2]=1;
    else F[x1][y1][x2][y2] =2;
    int rep=0;
    for(int i=0;i<3;i++)
    if(!out(x1+xx[i],y1-1))
        for(int j=0;j<3;j++)
            if(ok(x1+xx[i],y1-1,x2+xx[j],y2+1)) rep=max(rep,f(x1+xx[i],y1-1,x2+xx[j],y2+1));
    F[x1][y1][x2][y2]+=rep;
    return F[x1][y1][x2][y2];

}
main() {
    freopen("PLGAME.INP","r",stdin);
    freopen("PLGAME.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=3;i++)
        cin>>(C[i]+1);
        int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            ans=max(ans,f(j,i,j,i));
            if(i<n)
            for(int l=0;l<3;l++)
                if(ok(j,i,j+xx[l],i+1)) {
                        ans=max(ans,f(j,i,j+xx[l],i+1));

                }
        }
    }
    printf("%d",ans);
}
