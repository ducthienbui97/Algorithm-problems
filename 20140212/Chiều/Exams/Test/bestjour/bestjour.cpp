#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 510;
const int inf = (int)1e9;

int a[N][N];
int d[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", a[i] + j);
    for (int i = 0; i < n; i++) d[0][i] = 0;
    for (int it = 0; it < n; it++) {
        for (int i = 0; i < n; i++) d[it + 1][i] = inf;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
              if (i == j) {
                continue;
              }
              int dt = d[it][i] + a[i][j];
              if (dt < d[it + 1][j]) {
                  d[it + 1][j] = dt;
              }
            }
    }
    long long p = inf, q = 1;
    for (int i = 0; i < n; i++) {
        long long pp = 0, qq = 1;
        for (int it = 0; it < n; it++) {
            long long num = d[n][i] - d[it][i];
            long long den = n - it;
            if (num * qq > pp * den) {
                pp = num;
                qq = den;
            }
        }
        if (pp * q < p * qq) {
            p = pp;
            q = qq;
        }
    }
    int xx = p, yy = q;
    while (xx > 0 && yy > 0)
        if (xx > yy) xx %= yy;
        else yy %= xx;
    int g = xx + yy;
    p /= g;
    q /= g;
    printf("%d/%d", (int)p, (int)q);
    return 0;
}