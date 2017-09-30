#include <bits/stdc++.h>
using namespace std;
int F[333][333];
int h[333][333],v[333][333];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0; i <m; i++) {
        int x1,y1;
        int x2,y2;
        int w;
        cin >> x1 >> y1 >> w;
        x2 = x1,y2 = y1;
        F[x1][y1] += w;
        for(int voc = w-1; voc > 0; voc --) {
            x1--;
            y1--;
            x2++;
            y2++;
            if(x1 >= 0) {
                h[x1][max(y1,0)] += voc;
                h[x1][min(y2+1,n)] -= voc;
            }
            if(x2 < n) {
                h[x2][max(y1,0)] += voc;
                h[x2][min(y2+1,n)] -= voc;
            }
            if(y1 >= 0) {
                v[max(x1 + 1, 0)][y1] += voc;
                v[min(x2,n)][y1] -= voc;
            }
            if(y2 < n) {
                v[max(x1 + 1, 0)][y2] += voc;
                v[min(x2,n)][y2] -= voc;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < n; j++) {
            h[i][j] += j>0?h[i][j-1]:0;
            v[i][j] += i>0?v[i-1][j]:0;
            F[i][j] += h[i][j] + v[i][j];
            ans = max(ans,F[i][j]);
        }
    cout << ans <<endl;
    return 0;
}

