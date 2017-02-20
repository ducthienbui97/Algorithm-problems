#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <utility>
#include <cmath>
#include <climits>
#include <cstring>
#include <climits>
#include <ctime>
#include <queue>
#include <map>
#include <set>
using namespace std;
const int Maxn=1000000+10;
int A[Maxn];
int cnt[Maxn];
int F[Maxn];
main(){
    freopen("patheads.inp","r",stdin);
    freopen("patheads.out","w",stdout);
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
        F[A[i]]++;
    }
    for(int i=1;i<=n;i++)
    if(cnt[A[i]])printf("%d\n",cnt[A[i]]-1);
    else {
        x=sqrt(A[i]);
        for(int j=1;j<=x;j++)
        if(A[i]%j==0){
             cnt[A[i]]+=(F[j]+F[A[i]/j]);
             if(j*j==A[i]) cnt[A[i]]-=F[j];
             }
        printf("%d\n",cnt[A[i]]-1);
        }
}
