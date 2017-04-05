#include <bits/stdc++.h>
using namespace std;
long long a[3333],b[3333];
long long F[3333][3333];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i] -= i;
        b[i] = a[i];
    }
    sort(b,b+n);
    memset(F,0x3f,sizeof F);
    F[0][0] = abs(a[0] - b[0]);
    for(int i=1;i<n;i++)
        F[0][i] = min(F[0][i-1],abs(a[0] - b[i]));
    for(int i=1;i<n;i++){
        F[i][0] = F[i-1][0] + abs(a[i] - b[0]);
        for(int j=1;j<n;j++)
            F[i][j] = min(F[i-1][j] + abs(a[i] - b[j]),F[i][j-1]);
    }
    cout << F[n-1][n-1] <<endl;
}
