#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int n,m;
string s;
int val[1000010],sum[1000010],next[1000010];

int total(int u,int v)
{
    return sum[v] - sum[u - 1];
}

int main()
{
    scanf("%d %d\n", &n, &m);
    cin >> s;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        val[i] = (s[i - 1] == 'T') ? 2 : 1;
        sum[i] = sum[i - 1] + val[i];
    }
    
    next[n] = n + 1;
    for (int i = n - 1; i; i--)
    {
        next[i] = next[i + 1];
        if (val[i + 1] == 1) next[i] = i + 1;
    }
    
    while (m--)
    {
      int x;  scanf("%d", &x);
	  // Lời giải này sử dụng tìm kiếm nhị phân để tìm vị trí v xa nhất thỏa mãn sum[v] <= x
	  // Cho nên độ phức tạp là O(N + M log N)
	  // Có thể giảm xuống O(M + N) với phân tích như hôm trước
      if (x > sum[n]) printf("NIE\n"); else
      {
         int u = 1,low = 1,high = n,v = 1;
         while (low <= high)
         {
            int med = (low + high)/2;
            if (sum[med] >= x)
            {
                v = med;  high = med - 1;
            }
              else low = med + 1;
         }
         if (sum[v] == x) printf("%d %d\n", u, v); else
         {
             int delta = 0;
             if (val[u] == 2) delta = min(next[u] - u,next[v] - 1 - v);
             u += delta;  v += delta;
             if (total(u + 1,v) == x) printf("%d %d\n", u + 1, v);
             else if (v < n && total(u + 1,v + 1) == x) printf("%d %d\n", u + 1, v + 1);
             else printf("NIE\n");
         }
      }
    }
}