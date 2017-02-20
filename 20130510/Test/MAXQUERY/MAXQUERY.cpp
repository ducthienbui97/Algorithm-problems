#include<iostream>
#include<cmath>
using namespace std;
int N,K;
int a[105000];
int mark[30];
int RMQ[105000][50];
void input(){
    cin>>N>>K;
    for(int i=0;i<N;i++) cin>>a[i];
    mark[0]=1;
    for(int i=1;i<30;i++) mark[i]=mark[i-1]<<1;
}

void initRMQ(){
    for(int i=0;i<N;i++) RMQ[i][0]=a[i];
    int k=(int) trunc(log(N)/log(2));
    for(int j=1;j<=k;j++)
        for(int i=0;i<N-mark[j]+1;i++) 
            RMQ[i][j]=max(RMQ[i][j-1],RMQ[i+mark[j-1]][j-1]);
}

long long TinhMax(int u,int v){
    int k=(int) trunc(log(v-u+1)/log(2));
    return max(RMQ[u][k],RMQ[v-mark[k]+1][k]);
}

void answer(){
    int u,v;
    for(int i=0;i<K;i++){
        scanf("%d %d\n",&u,&v);
        u--;v--;
        printf("%d\n",TinhMax(u,v));
    }
}
int main(){
    input();
    initRMQ();
    answer();
}
