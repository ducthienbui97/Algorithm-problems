#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

long long A, B, f [22][22][11][2][2], res;
int dig [22], len, D, K;

long long cal (long long N) {
	for (len = 0; N; N /= 10)
        dig [++len] = N % 10;
	memset (f, 0, sizeof f);
	for (int i = 1; i <= len; ++i)
        f [i][0][0][i < len][0] = 1;
	for (; len; --len)
        for (int cnt = 0; cnt < 21; ++cnt)
            for (int cur = 0; cur < 10; ++cur)
                for (int sm = 0; sm < 2; ++sm)
                    for (int nz = 0; nz < 2; ++nz)
                        for (int next = 0; next < 10; ++next) {
                            if (!sm && next > dig [len]) continue;
                            if (!nz && !next) continue;
                            f [len - 1][cnt + (nz && abs (cur - next) <= D)][next][sm || next < dig [len]][1] +=
                                f [len][cnt][cur][sm][nz];
                        }
	for (int cnt = res = 0; cnt <= K; ++cnt)
        for (int cur = 0; cur < 10; ++cur)
            for (int sm = 0; sm < 2; ++sm) res += f [0][cnt][cur][sm][1];
	return res;
}

int main (int ac, char **av) {
	cin >> A >> B >> D >> K;
	cout << cal (B) - cal (A - 1) << endl;
}

