#include <iostream>
#include <cstdio>
#include <map>
#include <climits>
#include <utility>
#include <vector>
#include <set>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
set<long long int> vs;
queue<pair<int,long long int> > bfs;
int xx[]= {3,0,2,7,4,1,6,8,5,9};
int yy[]= {0,4,1,3,8,5,2,7,9,6};
long long int a[10],b[10],res;
long long int move1(long long int k) {
    res=0;
    for(int i=0; i<10; i++) {
        b[i]=k/a[10-i-1];
        k=k-b[i]*a[10-i-1];
        }
    for(int i=0; i<10; i++) {
        res+=b[xx[i]]*a[10-i-1];
        }
    return res;
    }
long long int move2(long long int k) {
    res=0;
    for(int i=0; i<10; i++) {
        b[i]=k/a[10-i-1];
        k=k-b[i]*a[10-i-1];
        }
    for(int i=0; i<10; i++) {
        res+=b[yy[i]]*a[10-i-1];
        }
    return res;
    }
main() {
    a[0]=1;
    for(int i=1; i<10; i++)
        a[i]=a[i-1]*10;
    long long int k=0,x1,x2;
    long long int s,f;
    int x;
    s=1238004765ll;
    f=0;
    for(int i=1; i<=10; i++) {
        scanf("%d",&x);
        f=f*10+x;
        }
    bfs.push(make_pair(0,f));
    vs.insert(f);
    while(!bfs.empty()) {
        x=bfs.front().first;
        k=bfs.front().second;
        bfs.pop();
        if(k==s) {
            printf("%d",x);
            return 0;
            }
        x1=move1(k);
        x2=move2(k);
        if(vs.find(x1)==vs.end()) {
            vs.insert(x1);
            bfs.push(make_pair(x+1,x1));
            }
        if(vs.find(x2)==vs.end()) {
            vs.insert(x2);
            bfs.push(make_pair(x+1,x2));
            }
        }
    }
