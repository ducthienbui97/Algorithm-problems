#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <algorithm>
#define elif else if
using namespace std;
const int Maxn=2010;
char s1[Maxn];
int F[Maxn][Maxn];
int add[Maxn],del[Maxn];

main(){
    freopen("cheappal.inp","r",stdin);
    freopen("cheappal.out","w",stdout);
    int n,m,j,x,y;
    char c;
    scanf("%d%d",&n,&m);
    scanf("%s",s1);
    j=m;
    for(int i=0;i<n;i++){
        getchar();
        scanf("%c",&c);
        scanf("%d%d",&add[c],&del[c]);
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<=m;j++){
            if(s1[j-1]==s1[j-1+i]) F[j][j+i]=F[j+1][j+i-1];
            else F[j][j+i]=min(F[j+1][j+i]+min(del[s1[j-1]],add[s1[j-1]]),F[j][j+i-1]+min(del[s1[j+i-1]],add[s1[j+i-1]]));
        }
    }
    printf("%d",F[1][m]);
}
