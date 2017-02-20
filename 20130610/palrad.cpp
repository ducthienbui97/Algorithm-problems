#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int const Maxn=1e6+10;
long long int const Base=1e9+97;
long long int Pow[Maxn],hashT[2][Maxn];
char c[Maxn];
int o[Maxn],e[Maxn];
int n;
long long int getHashT(int i,int j,int x){
    return (hashT[x][j]-hashT[x][i-1]*Pow[j-i+1]+Base*Base)%Base;
}
long long int getHash(int i,int j){
    return getHashT(n-j+1,n-i+1,1);
}
main(){
    freopen("palrad.inp","r",stdin);
    freopen("palrad.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",c);
    Pow[0]=1;
    for(int i=1;i<=n;i++)
        Pow[i]=(Pow[i-1]*26)%Base;
    for(int i=1;i<=n;i++)
         hashT[0][i]=(hashT[0][i-1]*26+c[i-1]-'a')%Base;
    int j=0;
    for(int i=n;i>0;i--)
        hashT[1][++j]=(hashT[1][j-1]*26+c[i-1]-'a')%Base;
    int l,r;
    int ans=0,mid;
    for(int i=1;i<=n;i++){
        ans=0;
        r=min(i-1,n-i-1);
        l=0;
        while(l<=r){
            mid=(l+r)/2;
            if(getHashT(i-mid,i,0)==getHash(i+1,i+1+mid)){
                ans=mid+1;
                l=mid+1;
            }else r=mid-1;
        }
        e[i]=ans;
        ans=0;
        r=min(i-1,n-i);
        l=0;
        while(l<=r){
            mid=(l+r)/2;
            if(getHashT(i-mid,i,0)==getHash(i,i+mid)){
                ans=mid;
                l=mid+1;
            }else r=mid-1;
        }
        o[i]=ans;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",e[i]);
    putchar('\n');
    for(int i=1;i<=n;i++)
        printf("%d ",o[i]);
}
