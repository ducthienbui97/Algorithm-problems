#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,b[20100],dem[2][1010];
void input(){
    scanf("%d %d\n",&m,&n);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
}
bool kt(){
    int s1=0,s2=0;
    for(int i=1;i<=m;i++){
        s1+=dem[0][i];
        s2+=dem[1][i];
        if (s2>s1) return false;
        if ((s1==s2) && (dem[0][i]>0)) return false;
        if ((s2<s1) && (s1-dem[0][i]<s2)) return false;
    }
    return true;
}
void solve(){
    for(int i=1;i<=m;i++) {
        dem[0][i]=0;
        dem[1][i]=0;
    }
    int ans=0;
    for(int i=0;i<n/2;i++){
        dem[0][b[i]]++;
        dem[1][b[i]]--;
        dem[1][b[i*2]]++;
        dem[1][b[i*2+1]]++;
        if (kt()) ans=i+1; 
    }
    cout<<ans;
}
int main(){
    freopen("binpcklr.inp","r",stdin);
    freopen("binpcklr.out","w",stdout);
    input();
    solve();
    return 0;
}
