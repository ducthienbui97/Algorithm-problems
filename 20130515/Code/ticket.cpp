#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <cstring>
#define maxn 505
using namespace std;

int a[maxn][maxn],c[maxn][maxn],s[maxn][maxn],f[maxn][maxn],trace[maxn][maxn],gate[maxn][maxn];
int n,K;

int main() {
  scanf("%d %d", &n, &K);
  // a: Số người đi từ i đến j
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i < n; i++) {
    // c: Số người xuất phát từ i và đi qua cổng nối giữa sân ga j và j + 1
    for (int j = n - 1; j >= i; j--) c[i][j] = c[i][j + 1] + a[i][j + 1];
  }
  // s: Tổng số người xuất phát ở một trong các sân ga {i,i + 1,...,j}
  // và đi qua cổng nối giữa sân ga j và j + 1
  for (int j = n - 1; j >= 1; j--)
    for (int i = j; i > 0; i--)
      s[i][j] = s[i + 1][j] + c[i][j];

  memset(f,-1,sizeof(f));
  f[1][0] = 0;
  for (int j = 0; j < K; j++)
    for (int i = 1; i <= n; i++) if (f[i][j] >= 0)
      for (int k = i; k < n; k++) {
        // we will update: f[i][j] to f[k + 1][j + 1]
	int tmp = f[i][j] + s[i][k];
	if (f[k + 1][j + 1] < tmp) {
	  f[k + 1][j + 1] = tmp;
	  trace[k + 1][j + 1] = i;
	  gate[k + 1][j + 1] = k;
	}
      }
  
  int pos = 0,ret = 0;
  for (int i = 1; i <= n; i++) if (ret < f[i][K]) {
    ret = f[i][K];
    pos = i;
  }
  printf("%d\n", ret);
  vector<int> v;
  v.clear();
  for (int i = pos,j = K; j > 0; j--) {
    v.push_back(gate[i][j]);
    i = trace[i][j];
  }
  for (int i = v.size() - 1; i >= 0; i--) printf("%d ", v[i]);
  printf("\n");
}