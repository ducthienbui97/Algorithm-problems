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
#include <deque>
#include <climits>
#include <algorithm>
#include<iostream>
using namespace std;
const double eps=0.0000001;
double k,t=0;
int n;
double a[100100];
void input(){
    scanf("%lf",&k);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
}
void solve(){
    double move;
    for(int i=1;i<n;i++){
        if (a[i]-t-a[i-1]-eps>k){
            move=(a[i]-t-a[i-1]-k)/2.0;
            a[i-1]+=move;
            a[i]=a[i]-t-move;
            t+=move;
        } else if (a[i]-t-a[i-1]+eps<k){
            if (a[i]+t-a[i-1]-eps>k){
                a[i]=k+a[i-1];
            } else a[i]=a[i]+t;
        } else {
            a[i]-=t;
        }
    }
    //for(int i=0;i<n;i++) printf("%.3lf ",a[i]);cout<<endl;
    printf("%.3lf",t);
}
int main(){
    //freopen("messagers.inp","r",stdin);
    //freopen("messagers.out","w",stdout);
    input();
    solve();
    return 0;
}
