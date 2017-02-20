#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

int n;
int counter;
int counting;
char str[31][31];
int DX[]={0,0,-1,1};
int DY[]={-1,1,0,0};
int tracex[31];
int tracey[31];
pair <int,int> path[11111];

void BackTracking(int x,int y){
    bool ok;
    int u,v,t;
    ok=false;
    for (t=0;t<4;t++){
        u=x+DX[t];
        v=y+DY[t];
        if (str[u][v]=='o'){
            ok=true;
            path[counting]=make_pair(u+DX[t],v+DY[t]);
        }

    }
    if (ok){
        BackTracking(u+DX[t],v+DY[t]);
        counting++;
    }else{
        counting=0;
    }
}

void input(){
    string s;
    cin>>n;
    int m;
    counter=0;
    int i,j;
    for (i=1;i<=n;i++){
        getline(cin,s);
        m=s.length();
        for (j=1;j<=n;j++)
            s[j]=str[i][j];
            if (s[i]=='k'){
                counter++;
                tracex[counter]=i;
                tracey[counter]=j;
            }
    }
}

void process(){
    int i;
    for (i=1;i<=counter;i++){
        BackTracking(tracex[i],tracey[i]);
    }
}

void output(){
    int i;
    if(counting==0) cout<<"impossible";
        else{
        for (i=1;i<=counting;i++)
            printf("%d%d\n",path[i].first,path[i].second);
        }
}

int main(){
    freopen("chkr.inp","r",stdin);
    freopen("chkr.out","w",stdout);
    input();
    process();
    output();
}
