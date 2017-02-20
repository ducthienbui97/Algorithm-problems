#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <utility>
#include <climits>
#include <vector>
#include <cstring>
#include <deque>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#define elif else if
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
int a[31111];
int m[555];
int s[31111];
int sum[31111];
int f[31111][555];
void run(int n,int k,int w){
    for(int i=2; i<=k; i++)
        for(int j=m[i]; j<=n; j++){
            f[j][i]=max(f[j-1][i],f[j-w][i-1]+s[j]);
        }
}
void doit(){
    int n,w,k;
    scanf("%d%d%d",&n,&k,&w);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=k;i++)
    m[i]=i*w;
    if(m[k]>=n) printf("%d\n",sum[n]);
    elif(k==0||k==0||w==0) printf("0\n");
    else{
        for(int i=1; i<w; i++)
           f[i][1]=s[i]=sum[i];
        for(int i=w; i<=n; i++){
            s[i]=sum[i]-sum[i-w];
            f[i][1]=max(f[i-1][1],s[i]);
        }
        run(n,k,w);
        printf("%d\n",f[n][k]);
    }
}
main()
{
    int t;
        s[0]=0;
    sum[0]=0;
    f[0][1]=0;

    freopen("3.inp","r",stdin);
    freopen("3.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        doit();
    }
}

