#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
char s[1005];
int f[1005][1005];

int get(int k){
    int i, j;
    for(i=0;i<=k;i++) f[i][k]= 0;
    for(j=k;j<=n;j++) f[0][j]= 0;
    for(i=1;i<=k;i++){
        for(j=k+1;j<=n;j++){
            if(s[i]==s[j]) f[i][j]= f[i-1][j-1]+ 1;
            else f[i][j]= max(f[i-1][j], f[i][j-1]);
        }
    }
    return f[k][n];
}

int main(){
    freopen("Squared.inp","r",stdin);
    freopen("Squared.out","w",stdout);
    int i, maxi= 0;
    scanf("%d%s", &n, s+1);
    for(i=1;i<=n-1;i++){
        maxi= max(maxi, get(i));
    }
    printf("%d\n", n-2*maxi);
    return 0;
}
