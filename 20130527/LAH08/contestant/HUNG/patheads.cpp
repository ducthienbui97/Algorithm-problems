#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>

#define maxn 111111
#define maxm 1111111

using namespace std;

int n;
int a[maxn];
int c[maxn];

void input(){
    int i;
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>a[i];
    }
}

void process(){
    int i,j;
    int sum;
    memset(c,0,sizeof(c));
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++){
            if (a[i]%a[j]==0) c[i]++;
        }
}

void output(){
    int i;
    for (i=1;i<=n;i++)
        printf("%d\n",c[i]-1);
}

int main(){
    freopen("patheads.inp","r",stdin);
    freopen("patheads.out","w",stdout);
    input();
    process();
    output();
}
