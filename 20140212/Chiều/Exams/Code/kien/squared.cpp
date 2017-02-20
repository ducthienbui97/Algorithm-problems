#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define f1(i,n) for (int i=1; i<=n; i++)
#define N 1003

int n;
char a[N];
int F[N][N];

bool maximize(int &a, int b){ if (a<b) a=b; else return false; return true; }

int f(char *a, char *b, int m, int n){
	f1(i,m) f1(j,n) {
		F[i][j] = max(F[i-1][j], F[i][j-1]);
		if (a[i]==b[j]) maximize(F[i][j], F[i-1][j-1]+1);
	}
	return F[m][n];
}

main(){
	freopen("squared.inp", "r", stdin);
	freopen("squared.out", "w", stdout);
	int Answer=0;
	ios :: sync_with_stdio(false);
	cin >> n >> a+1;
	f1(i,n) maximize(Answer, f(a, a+i, i, n-i));
	cout << n-2*Answer << endl;
}
