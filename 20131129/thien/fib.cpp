#include <iostream>
#include <cstdio>
#include <cstring>
#define mp make_pair
#include <string>
#include <vector>
#include <algorithm>
#define elif else if
using namespace std;
bool F[1111][1111];
vector<int> fibo;
int n;
long long ml(long long  a,long long b,int r) {
    a%=r;
    if(!b) return 1;
    long long tmp=ml(a,b/2,r)%r;
    if(b&1) {
        return ((tmp*tmp)%r*a)%r;
        }
    return (tmp*tmp)%r;
    }
long long ucln(long long a,long long b) {
    if(a>b) swap(a,b);
    if(!a) return b;
    return ucln(b%a,a);
    }
void doit() {
    memset(F,0,sizeof F);
    fibo.clear();

    long long x,y;
    cin>>x>>y>>n;
    int a=0,b=1;
    for(;;) {
        if(F[a][b]) {
            break;
            }
        fibo.push_back(a);
        F[a][b]=true;
        a+=b;
        a%=n;
        swap(a,b);
        }
    long long t1=ml(x,y,fibo.size());
    long  long t2=ucln(x,y);
    cout<<fibo[t1%fibo.size()]<<" "<<fibo[t2%fibo.size()]<<endl;
    }
main() {
    freopen("fib.inp","r",stdin);
    freopen("fib.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) doit();

    }
