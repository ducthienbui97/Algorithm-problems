#include <bits/stdc++.h>

using namespace std;
int F[111][111][111][3];
vector<int> V,K,X;
const int LAST_X = 0;
const int LAST_V = 1;
const int LAST_K = 2;
const int inf = 1e9;
int between(int l,int r,int x) {
    return x>=l&&x<=r;
}
int cont(vector<int> &v,int l,int r) {
    int rep = 0;
    for(int i:v) rep += between(l,r,i);
    return rep;
}
main() {
    ios_base::sync_with_stdio(false);
    memset(F,0x3f,sizeof F);
    string s;
    int n;
    cin >> n;
    cin >> s;

    for(int i=0; i<n; i++) {
        if(s[i] == 'V') V.push_back(i);
        else if(s[i] == 'K') K.push_back(i);
        else X.push_back(i);
    }
    F[0][0][0][LAST_X] =0;
    for(int i=0; i<=X.size(); i++)
        for(int j=0; j<=V.size(); j++)
            for(int l=0; l<=K.size(); l++)
                for(int s=0; s<3; s++)
                    if(F[i][j][l][s] < inf) {
                        int x = i?X[i-1]:-1;
                        int v = j?V[j-1]:-1;
                        int k = l?K[l-1]:-1;
                        if(i < X.size())
                            F[i+1][j][l][LAST_X] = min(F[i+1][j][l][LAST_X], F[i][j][l][s] + cont(V,X[i],v) + cont(K,X[i],k));
                        if(j < V.size())
                            F[i][j+1][l][LAST_V] = min(F[i][j+1][l][LAST_V], F[i][j][l][s] + cont(X,V[j],x) + cont(K,V[j],k));
                        if(l < K.size() && s != LAST_V)
                            F[i][j][l+1][LAST_K] = min(F[i][j][l+1][LAST_K], F[i][j][l][s] + cont(V,K[l],v) + cont(X,K[l],x));
                    }
    cout << min(min(F[X.size()][V.size()][K.size()][LAST_X],F[X.size()][V.size()][K.size()][LAST_V]),F[X.size()][V.size()][K.size()][LAST_K]) <<endl;
}
