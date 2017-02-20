#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<algorithm>
#include<complex>
using namespace std;
#define MP make_pair
#define F first
#define S second
#define PB push_back
const int h[8][3] = {{1, 3, 4}, {0, 2, 5}, {3, 1, 6}, {2, 0, 7}, {5, 7, 0}, {4, 6, 1}, {7, 5, 2}, {6, 4, 3}};
long long matrix[24][24];
long long Cur[24][24];

long long tmp[24][24];
long long source[8][3];
long long MOD;
void Cal_Pow(int k) {
	if (k == 1) {
		for(int i = 0; i < 24; i++)
			for(int j = 0; j < 24; j++)
				Cur[i][j] = matrix[i][j];
		return;
	}
	if (k % 2 == 0) {
		Cal_Pow(k / 2);
		for(int i = 0; i < 24; i++)
			for(int j = 0; j < 24; j++) {
				long long sum = 0;
				for(int p = 0; p < 24; p++) {
					sum += Cur[i][p] * Cur[p][j];					
					sum %= MOD;
				}
				tmp[i][j] = sum;
			}
		for(int i = 0; i < 24; i++)
			for(int j = 0; j < 24; j++)
				Cur[i][j] = tmp[i][j];
	}
	else {
		Cal_Pow(k / 2);
		for(int i = 0; i < 24; i++)
			for(int j = 0; j < 24; j++) {
				long long sum = 0;
				for(int p = 0; p < 24; p++) {
					sum += Cur[i][p] * Cur[p][j];					
					sum %= MOD;
				}
				tmp[i][j] = sum;
			}
		for(int i = 0; i < 24; i++)
			for(int j = 0; j < 24; j++)
				Cur[i][j] = tmp[i][j];		
		for(int i = 0; i < 24; i++)
			for(int j = 0; j < 24; j++) {
				long long sum = 0;
				for(int p = 0; p < 24; p++) {
					sum += Cur[i][p] * matrix[p][j];					
					sum %= MOD;
				}
				tmp[i][j] = sum;
			}		
		for(int i = 0; i < 24; i++)
			for(int j = 0; j < 24; j++) Cur[i][j] = tmp[i][j];		
	}
}
void init() {
	for(int x = 0; x < 8; x++)	
		for(int y = 0; y < 3; y++) {
			int x2 = h[x][y];
			source[x2][y] = x;
		}	
	memset(matrix, 0, sizeof(matrix));
	for(int i = 0; i < 24; i++) {
		int vertex = i / 3;
		int direct = i % 3;		
		for(int j = 0; j < 3; j++) {
			int target = h[vertex][j];			
			if (source[vertex][direct] == target) continue;
			int i2 = target * 3 + j;
			matrix[i][i2] = 1;
		}				
	}
}
char S, T, sp;
int n;
long long Start[24];
long long Res[24];
void process() {
	scanf("%c%c%c", &S, &sp, &T);
	scanf("%d%d", &n, &MOD);
	if (n == 1) {
		bool found = false;
		for(int i = 0; i < 3; i++) {
			if (h[S - 'A'][i] == T - 'A') found = true;
		}
		if (found) cout << 1 << endl;
		else cout << 0 << endl;
		return;
	}	
	long long tong = 0;
	Cal_Pow(n - 1);
//	for(int i = 0; i < 24; i++) cout << Cur[0][i] << endl;
	memset(Start, 0, sizeof(Start));
	for(int init_direct = 0; init_direct < 3; init_direct ++) {
		int Source = h[S - 'A'][init_direct];
		for(int i = 0; i < 24; i++)	{
			if (i / 3 == Source && i % 3 == init_direct) {
				Start[i] = 1;				
			}
		}
	}
	for(int i = 0; i < 24; i++) {
			int sum = 0;
			for(int p = 0; p < 24; p++) {
				sum = sum + Start[p] * Cur[p][i];
				sum %= MOD;
			}
			Res[i] = sum;
		}	
	for(int i = 0; i < 24; i++) {
		if (i / 3 == T - 'A') tong += Res[i];
		tong %= MOD;
	}
	cout << tong << endl;
}
int main() {
	freopen("ant.inp", "r", stdin);
	freopen("ant.out", "w", stdout);
	init();
	process();
	return 0;
}
