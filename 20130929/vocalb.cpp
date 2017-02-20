#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define elif else if
#define input "vocalb.inp"
#define output "vocalb.out"
using namespace std;
inline void openfile() {
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
    }
const int r=97654321;
const int Maxn=300;
int p,q,m;
vector<int> d[60];
inline int cal(char c) {
    if(c>='a'&&c<='z') return c-'a';
    else return c-'A'+26;
    }
char S[33];
int F[555][255][60];
main() {
#ifndef HYQ
    openfile();
#endif
    ios_base::sync_with_stdio(false);
    cin>>p>>q>>m;
    while(m--) {
        cin>>S;
        d[cal(S[1])].push_back(cal(S[0]));
        }
    for(int i=0; i<26; i++) {
        F[1][0][i]=1;
        F[1][1][i+26]=1;
        }
    int n=p+q;
    for(int i=2; i<=n; i++)
        for(int ks=0; ks<=p; ks++)
            for(int j=0; j<52; j++) {
                for(int l=0; l<d[j].size(); l++) {
                    if(j<26) {
                        F[i][ks][j]+=F[i-1][ks][d[j][l]];
                        F[i][ks][j]%=r;
                        }
                    elif(ks>0) {
                        F[i][ks][j]+=F[i-1][ks-1][d[j][l]];
                        F[i][ks][j]%=r;
                        }
                    }
                }
    int ans=0;
    for(int i=0; i<52; i++) {
        ans=(ans+F[n][p][i])%r;
        }
    printf("%d",ans);
    }
/*
2 2 7
AB
ab
BA
ba
Aa
Bb
bB
*/
