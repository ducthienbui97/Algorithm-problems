///

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	
	int N, M;
	scanf( "%d %d", &N, &M );
	
	int grid[N][M];
	for( int n = 0; n < N; n++ ) {
		for( int m = 0; m < M; m++ ) {
			static int val;
			scanf( "%d", &val );
			grid[n][m] = val;
		}
	}
	
	int partial_column_sums[N+1][M];
	for( int m = 0; m <= M; m ++ ) partial_column_sums[0][m] = 0;
	for( int m = 0; m < M; m++ ) {
		for( int n = 1; n <= N; n++ ) {
			partial_column_sums[n][m] = partial_column_sums[n-1][m] + grid[n-1][m];
		}
	}
	
	int best = 0;
	for( int r1 = 0; r1 < N; r1++ ) {
		for( int r2 = r1; r2 < N; r2++ ) {
			int s = 0;
			int m = 0;
			for( int c = 0; c < M; c++ ) {
				int v = partial_column_sums[r2+1][c]-partial_column_sums[r1][c];
				s = max(s+v, 0);
				m = max(m, s);
			}
			best = max(best, m);
		}
	}
	
	printf("%d\n",best);
}
