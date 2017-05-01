#include <bits/stdc++.h>
using namespace std;
int F[722][722][2][2];
int B[1442][2];
void solve(int nTest) {
    memset(B,0,sizeof B);
    int n[2];
    cin >> n[0] >> n[1];
    for(int j=0; j<2; j++) {
        for(int i=0; i<n[j]; i++) {
            int l,r;
            cin >> l >> r;
            for(; l<r; l++)
                B[l][j] = true;
        }
    }
    memset(F,0x3f,sizeof F);
    int inf = F[0][0][0][0];
    int ans = inf;
    F[0][0][0][0] = 0;
    F[0][0][1][1] = 0;
    for(int i=0; i<=720; i++)
        for(int j=0; j<=720; j++)
            for(int f=0; f<2; f++) {
                int cur = i + j;
                if(!cur) continue;
                if(!B[cur-1][0]) {
                    F[i][j][0][f] = i?min(F[i-1][j][0][f],F[i-1][j][1][f]+1):inf;
                }
                if(!B[cur-1][1]) {
                    F[i][j][1][f] = j?min(F[i][j-1][0][f]+1,F[i][j-1][1][f]):inf;
                }
            }
    cout << "Case #"<<nTest<<": "<<min(min(F[720][720][0][0],F[720][720][1][0]+1),min(F[720][720][0][1]+1,F[720][720][1][1]))<<endl;
}
main() {
    freopen("B-small-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}

/*
1
2 0
900 1260
180 540
*/
