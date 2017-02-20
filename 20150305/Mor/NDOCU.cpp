#include <bits/stdc++.h>
using namespace std;
bool A[7][7],used[7],finish;
int B[7],board[7][7];
int Map[7][37];
char KK[37];
void bt(int now,int n,int cnt){
    if(now==n){
        for(int i=0;i<n;i++){
            board[cnt][i]=B[i];
        }
        finish=true;
        return;
    }
    for(int i=1;i<=n;i++){
    if(!A[now][i]&&!used[i]){
        used[i] = true;
        A[now][i]=true;
        B[now]=i;
        bt(now+1,n,cnt);
        used[i]=false;
        if(finish) return;
        else A[now][i]=false;
        }
    }
}
main(){
    freopen("NDOCU.INP","r",stdin);
    freopen("NDOCU.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>&KK[i*n];
    for(int i=0;i<n;i++){
        bt(0,n,i);
        finish=false;
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    for(int k=0;k<n;k++){
            Map[i][j*n+k] = board[i][k]+j*n;
    }
    for(int i=0;i<n;i++)
    for(int k=0;k<n;k++){
        for(int j=0;j<n*n;j++){
            printf("%c",KK[Map[i][(k*n+j)%(n*n)]-1]);
        }
        puts("");
    }
}
