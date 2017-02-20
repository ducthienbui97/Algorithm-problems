#include <bits/stdc++.h>
#define elif else if
using namespace std;
double F[1<<20];
double a[20][20];
bool done[1<<20];
int All,n;
double f(int t){
    if(!t) return 1;
    if(done[t]) return F[t];
    done[t]=true;
    int num=__builtin_popcount(t);
    for(int i=0;i<n;i++)
    if((t&(1<<i))){
        F[t]=max(F[t],f(t-(1<<i))*a[i][num-1]);
    }
    return F[t];
}
main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            a[i][j]/=100;
        }
    All=(1<<n)-1;
    printf("%.6lf",100*f(All));
}
