#include <bits/stdc++.h>
using namespace std;
const int Max=333;
char S[Max][Max];
int F[Max][Max];
int sum[Max];
int n,m,K;
int ans[Max][Max];
int get(int x1,int y1,int x2,int y2){
    return F[x2][y2]-F[x2][y1-1]-F[x1-1][y2]+F[x1-1][y1-1];
}
main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>K;
    for(int i=1;i<=n;i++)
        cin>>(&S[i][1]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        F[i][j]=F[i-1][j]+F[i][j-1]-F[i-1][j-1]+(S[i][j]=='H');
    for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++){
        memset(sum,0,sizeof sum);
        for(int k=1,last=0;k<=m;k++){
            sum[k]=sum[k-1]+get(j,k,i,k);
            while(last<k&&sum[k]-sum[last+1]>=K) ++last;
            if(!last&&sum[k]<K) continue;
            ans[i-j+1][k-last]++;
            ans[i-j+1][k+1]--;
        }
    }
    for(int i=1;i<=n;i++){
        int s=0;
        for(int j=1;j<=m;j++){
            s+=ans[i][j],ans[i][j]=s;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        ans[i][j]=ans[i][j]+ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
    int q;
    cin>>q;
    int x,y;
    while(q--){
        cin>>x>>y;
        printf("%d\n",ans[x][y]);
    }

}

/*
5 5 4
H.H..
..H..
H...H
HHHH.
HH..H
*/
