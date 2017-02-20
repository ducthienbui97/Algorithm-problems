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
#include <algorithm>
#include <utility>
#define elif else if
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pi;
int A[16][16];
int b[16][16];
int d[16];
int m,n;
bool done;
vector<int> vecmin;
vector<int> dx;
void touch(int x,int y){
    b[x][y]=!b[x][y];
    b[x+1][y]=!b[x+1][y];
    b[x-1][y]=!b[x-1][y];
    b[x][y-1]=!b[x][y-1];
    b[x][y+1]=!b[x][y+1];
}
void doit(){
    dx.clear();
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            b[i][j]=A[i][j];
    for(int i=1;i<=n;i++)
        if(d[i]) dx.push_back(1),touch(1,i);
        else dx.push_back(0);
    for(int i=2;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(b[i-1][j]) dx.push_back(1),touch(i,j);
            else dx.push_back(0);
    bool check=false;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        if(b[i][j]) check=true;
    if(!check) {
        if(vecmin>dx) vecmin=dx;
        done=true;
            }
}
void bt(int k){
    for(int i=0;i<=1;i++){
        d[k]=i;
        if(k<n) bt(k+1);
        else doit();
    }
}

main(){
   //freopen("fliptile.inp","r",stdin);
   // freopen("fliptile.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&A[i][j]),vecmin.push_back(1);
    bt(1);
    int l=0;
    cout<<endl;
    if(done)
    for(int i=1;i<=m;i++){
        for(int j=1;j<n;j++)
            printf("%d ",vecmin[l++]);
        printf("%d\n",vecmin[l++]);
    }
    else printf("IMPOSSIBLE");
}
