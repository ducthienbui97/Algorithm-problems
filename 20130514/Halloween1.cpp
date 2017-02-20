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
#include <complex>
//#define x real()
//#define y imag()
#define elif else if
#define mp make_pair
using namespace std;
long long int sum[111111];
int a[111111];
int r[111111];
main(){
    int n;
    scanf("%d",&n);
    sum[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
        r[i-1]=0;
    }
    int n1,n2;
    for(int i=1;i<=n;i++){
        if(sum[i]%n==0){
            n1=0;
            n2=i;
            break;
        }
        elif(!r[sum[i]%n]) r[sum[i]%n]=i;
        else{
            n1=r[sum[i]%n];
            n2=i;
            break;
        }
    }
    for(int i=n1+1;i<n2;i++)
    printf("%d ",i);
    printf("%d",n2);
}
