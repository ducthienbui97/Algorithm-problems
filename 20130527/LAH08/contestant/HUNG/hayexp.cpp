#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>

#define maxn 555

using namespace std;

int n;
int q;
int a[maxn];
int s[maxn];
int f[maxn];

void input(){
    int i;
    scanf("%d%d",&n,&q);
    for (i=1;i<=n;i++){
        scanf ("%d",&a[i]);
    }
}

int sum(int x,int y){
    int i;
    int res;
    res=0;
    for (i=x;i<=y;i++){
        res+=a[i];
    }
    return res;
}

int main(){
    int i;
    freopen("hayexp.inp","r",stdin);
    freopen("hayexp.out","w",stdout);
    input();
    for (i=1;i<=q;i++){
        scanf ("%d%d",&s[i],&f[i]);
        printf("%d\n",sum(s[i],f[i]));
    }
}
