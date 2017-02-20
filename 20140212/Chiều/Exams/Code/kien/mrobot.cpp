#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define M 1000000007LL
#define f0(i,n) for (int i=0; i<n; i++)
#define f1(i,n) for (int i=1; i<=n; i++)

#define N 2000006
long Fact[N], IFact[N];

long power(long a, long k){
	if (k==0) return 1;
	long x = power(a, k/2);
	if (k&1) return x*x%M*a%M;
	return x*x%M;
}

long nCk(long k, long n){
	return Fact[n]*IFact[n-k]%M*IFact[k]%M;
}

main(){
	freopen("mrobot.inp", "r", stdin);
	freopen("mrobot.out", "w", stdout);

	int t; long A, B;
	ios :: sync_with_stdio(false);

	Fact[0]=IFact[0]=1;
	f1(i,2000000) {
		Fact[i]=Fact[i-1]*i%M;
		IFact[i]=power(Fact[i], M-2);
	}

	cin >> t;
	while (t--){
		cin >> A >> B;
		cout << nCk(A-1, B+A-2) << endl;
	}
}
