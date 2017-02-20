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
#include <utility>
#include <algorithm>
#define elif else if
#define X first
#define Y second
using namespace std;
const long long int Maxn=4e4+10;
typedef pair<long long int,long long int> pi;
struct stll{
    long long int a,b,h;

};
bool cmp(stll a,stll b){
    if(a.a<b.a) return true;
    if(a.a>b.a) return false;
    if(a.b<b.b) return true;
    if(a.b>b.b) return false;
    return (a.h<b.h);
}
stll A[Maxn];
vector<pi> S;
bool OA[Maxn],OB[Maxn],Ch[Maxn],Ck[Maxn];
long long int n,j;
main(){
    freopen("horizon.inp","r",stdin);
    freopen("horizon.out","w",stdout);
    scanf("%lld",&n);
    for(long long int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&A[i].a,&A[i].b,&A[i].h);
    }
    sort(A+1,A+n+1,cmp);
    for(long long int i=1;i<=n;i++){
    if(!OA[i]){
        if(!Ch[i])  S.push_back(pi(A[i].a,0));
        S.push_back(pi(A[i].a,A[i].h));
        j=i+1;
        while(A[j].a<=A[i].b&&j<=n){
           if(A[j].h>A[i].h){
                S.push_back(pi(A[j].a,A[i].h));
                Ch[j]=true;
                if(A[j].b<A[i].b) Ck[j]=true;
                else OB[i]=true;
           }
           else{
               OA[j]=true;
               if(A[i].b<A[j].b) {
                    S.push_back(pi(A[i].b,A[j].h));
                    Ck[i]=true;
                }
                else{
                    OB[j]=true;
                }
           }
           j++;
        }
    }
    if(!OB[i]){
        if(!Ck[i])   S.push_back(pi(A[i].b,0));
        S.push_back(pi(A[i].b,A[i].h));
        }

    }
    sort(S.begin(),S.end());
    n=S.size();
    for(int i=0;i<n;i++)
        //cout<<S[i].X<<" "<<S[i].Y<<endl;
        for(long long int i=0;i<n-1;i++){
        if(S[i].X!=S[i+1].X&&S[i].Y!=S[i+1].Y){
            for(j=i+1;j<n;j++){
                if(S[i].X==S[j].X||S[i].Y==S[j].Y)
                {
                    swap(S[i+1],S[j]);
                    break;
                }
                }
        }
    }
    long long int s=0;
    for(long long int i=0; i<n-1; i++)
        s=s+(S[i].Y+S[i+1].Y)*(S[i+1].X-S[i].X);
    s=s+(S.back().Y+S.front().Y)*(S.front().X-S.back().X);
    printf("%lld",abs(s/2));
}
