#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define elif else if
#define mp make_pair

using namespace std;
const int base=31;
const int Maxn=1e6+30;
int H[2][Maxn];
int P[Maxn];
int n[2];
char S[2][Maxn];
int get(int l,int r,bool w){
    return H[w][r]-H[w][l-1]*P[r-l+1];
}
main(){
    //BASESTRING
    freopen("BASESTRING.INP","r",stdin);
    freopen("BASESTRING.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>S[0]+1>>S[1]+1;
    n[0]=strlen(S[0]+1);
    n[1]=strlen(S[1]+1);
    P[0]=1;
    for(int i=1;i<=min(n[0],n[1]);i++)
        P[i]=P[i-1]*base;
    for(int i=0;i<=1;i++){
        for(int j=1;j<=n[i];j++){
            H[i][j]=H[i][j-1]*base+S[i][j]-'a'+1;
        }
    }
    int l[2];
    l[0]=l[1]=1;
    while(true){
        int tmp[2];
        tmp[0]=n[0]-l[0]+1;
        tmp[1]=n[1]-l[1]+1;
        bool k=tmp[0]>tmp[1];
        if(get(l[0],l[0]+tmp[k]-1,0)!=get(l[1],l[1]+tmp[k]-1,1)){
            puts("NO");
            return 0;
        }elif(tmp[0]==tmp[1]){
            for(int i=l[0];i<=n[0];i++)
                putchar(S[0][i]);
            return 0;
        }
        l[!k]+=tmp[k];
    }
}
