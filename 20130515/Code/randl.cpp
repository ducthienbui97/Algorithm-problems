#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define maxn 2005
using namespace std;

long long overall[maxn][maxn],shoot[maxn][maxn];
int a[maxn];
int n,k;
long long INF = 1LL << 60;

// Ý tưởng QHĐ ở đây hơi khác một chút
// Sử dụng 2 mảng: overall[i][j] ứng với việc không nhất thiết phải bắn ở ô i
// shoot[i][j] ứng với việc phải bắn ở ô i
// Cách thức QHĐ là tương tự

void overallDP() {
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= k; j++) {
			overall[i][j] = (j) ? overall[i][j - 1] : 0;
			shoot[i][j] = (j) ? shoot[i][j - 1] : -INF;
			if (!j) continue;
			shoot[i][j] = a[i] + max(overall[i - 1][j - 1],shoot[i - 2][j - 1] + a[i - 1]);
			overall[i][j] = max(overall[i][j],overall[i - 1][j]);
			overall[i][j] = max(overall[i][j],shoot[i][j]);
		}
}

long long firstDP() {
	// 1 and n are seperated
	for (int j = 0; j <= k; j++) {
		shoot[0][j] = -INF;
		overall[0][j] = 0;
	}
	for (int j = 0; j <= k; j++) {
		shoot[1][j] = (j) ? a[1] : -INF;
		overall[1][j] = (j) ? a[1] : 0;
	}
	overallDP();
	return overall[n][k];
}

long long secondDP() {
	for (int j = 0; j <= k; j++) {
		shoot[0][j] = -INF;
		overall[0][j] = 0;
	}
	for (int j = 0; j <= k; j++) shoot[1][j] = overall[1][j] = 0;
	overallDP();
	long long sum = a[1];
	int last = n,rem = k - 1;
	long long ret = sum + overall[n][rem];
	while (rem > 0 && last > 1) {
		rem--;
		sum += a[last] + a[last - 1];
		last -= 2;
		ret = max(ret,sum + overall[last][rem]);
	}
	return ret;
}

long long thirdDP() {
	for (int j = 0; j <= k; j++) shoot[0][j] = overall[0][j] = 0;
	for (int j = 0; j <= k; j++) {
		shoot[1][j] = (j) ? a[1] : -INF;
		overall[1][j] = (j) ? a[1] : 0;
	}
	overallDP();
	long long sum = a[n];
	int last = n - 1,rem = k - 1;
	long long ret = sum + overall[last][rem];
	while (rem > 0 && last > 1) {
		rem--;
		sum += a[last] + a[last - 1];
		last -= 2;
		ret = max(ret,sum + overall[last][rem]);
	}
	return ret;
}

long long solve() {
	// Trường hợp này có thể đuổi được hết thỏ
	if (k >= (n + 1)/2) {
		int sum = 0;
		for (int i = 1; i <= n; i++) sum += a[i];
		return sum;
	}
	long long ret = max(firstDP(),secondDP());
	ret = max(ret,thirdDP());
	return ret;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}