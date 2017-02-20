#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <utility>
#define elif else if
using namespace std;
typedef long long int li;
typedef unsigned long long int lu;
typedef pair <long long int,long long int> pll;
typedef pair <int,int> pii;
typedef pair<double,double> pdd;
typedef vector <int> vi;
typedef vector <li> vli;
int a[55555];
int minn[55555];
int find(int p,int l,int r,int t){
    if(l<=r){
    int mid=(l+r)/2;
    if(r-l<=1) if(a[t]-minn[l]>=p) return t-l;
                elif(a[t]-minn[r]>=p) return t-r;
                else return -1;
    if(a[t]-minn[mid]>=p) return find(p,l,mid,t);
    else return find(p,mid,r,t);}
    return -1;
}
main()
{
    int i,j,maxx,x,m,n;
    a[0]=0;
    j=INT_MAX;
    maxx=-2;
    scanf("%d%d",&m,&n);
    for(i=1; i<=m; i++)
    {
        scanf("%d",&x);
        if(x>=n) maxx=1;
        a[i]=a[i-1]+x;
        j=min(j,a[i]);
        minn[i]=j;
    }
    for(i=1;i<=m;i++){
        maxx=max(maxx,find(n,1,i-1,i));
        }
    printf("%d",maxx);
}
