#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <vector>
#define input "mobiles.inp"
#define output "mobiles.out"
#define elif else if
using namespace std;
inline void openfile() {
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
    }

int n,s,x,y,l,r,b,t,a1,z;
int a[1050][1050];
inline void update(int ll,int rr,int val) {
    for(int i=ll; i<=s; i+=(i&(-i)))
        for(int j=rr; j<=s; j+=(j&(-j)))
            a[i][j]+=val;
    }
inline int get(int ll,int rr) {
    int sum=0;
    for(int i=ll; i>0; i-=(i&(-i)))
        for(int j=rr; j>0; j-=(j&(-j)))
            sum+=a[i][j];
    return sum;
    }
main() {
    openfile();
    while(scanf("%d",&n)!=EOF) {
        if(!n) {
            scanf("%d",&s);
            }
        if(n==1) {
            scanf("%d%d%d",&x,&y,&a1);
            x++;
            y++;
            update(x,y,a1);
            }
        if(n==2) {
            scanf("%d%d%d%d",&l,&b,&r,&t);
            l++;
            r++;
            b++;
            t++;
            printf("%d\n",get(r,t)-get(r,b-1)-get(l-1,t)+get(l-1,b-1));
            }
        if(n==3) break;
        }

    }







