#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

typedef pair<long,long> ii;
long r, c, i, j, result;
vector<vector<bool> > sign;
vector<bool> b;

void bfs(long u, long v){
    long step, now, ofqueue, i, j, f, g;
    queue<ii> ryo;
    ryo.push(ii(u,v));
    ofqueue= 1;
    for(;;){
        now= 0;
        for(i=1;i<=ofqueue;i++){
            ii x= ryo.front(); ryo.pop();
            sign[x.first][x.second]= true;
            f= x.first; g= x.second;
            if(f+1<r && g+1<c && sign[f+1][g+1]==false) {ryo.push(ii(f+1,g+1)); now++;}
            if(f-1>=0 && g+1<c && sign[f-1][g+1]==false) {ryo.push(ii(f-1,g+1)); now++;}
            if(f+1<r && g-1>=0 && sign[f+1][g-1]==false) {ryo.push(ii(f+1,g-1)); now++;}
            if(f-1>=0 && g-1>=0 && sign[f-1][g-1]==false) {ryo.push(ii(f-1,g-1)); now++;}
            if(f+1<r && sign[f+1][g]==false) {ryo.push(ii(f+1,g)); now++;}
            if(f-1>=0 && sign[f-1][g]==false) {ryo.push(ii(f-1,g)); now++;}
            if(g+1<r && sign[f][g+1]==false) {ryo.push(ii(f,g+1)); now++;}
            if(g-1>=0 && sign[f][g-1]==false) {ryo.push(ii(f,g-1)); now++;}
        }
        if(now==0) break; else ofqueue= now;
    }
    return;
}

main(){
    freopen("badgras.inp","r",stdin);
    freopen("badgras.out","w", stdout);
    long x;
    scanf("%ld%ld", &r, &c);
    result= 0;
    for(i=0;i<r;i++){
        b.clear();
        for(j=0;j<c;j++){
            scanf("%ld", &x);
            if(x==0) b.push_back(true);
            else b.push_back(false);
        }
        sign.push_back(b);
    }
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            if(sign[i][j]==false) {
                bfs(i,j);
                result++;
            }
        }
    printf("%ld\n", result);
}
