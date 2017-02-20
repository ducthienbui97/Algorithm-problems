#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,minc[1010];
int q[1010],fi,la;
void input(){
    scanf("%d %d\n",&n,&m);
    int a,b,w;
    for(int i=0;i<n;i++) minc[i]=2000000000;
    for(int i=0;i<m;i++){
        scanf("%d %d %d\n",&a,&b,&w);
        b--;
        minc[b]=min(minc[b],w);
        //cout<<minc[b]<<endl;
    }
    sort(&minc[0],&minc[n]);
    if (minc[n-2]==2000000000) cout<<-1;
    else {
        long long ans=0;
        for(int i=0;i<n-1;i++) ans+=minc[i];
        cout<<ans;
    }
}
int main(){
    freopen("dagmst.inp","r",stdin);
    freopen("dagmst.out","w",stdout);
    input();
    return 0;
}
