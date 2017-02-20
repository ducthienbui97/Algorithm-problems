#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <algorithm>
#include <utility>
#include <complex>
#define elif else if
using namespace std;
long long int n,m;
long long int A[5555],B[5555],F[5555][5555];
main(){
		long long int n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&A[i]);
			B[i]=A[i];
		}
		sort(B+1,B+n+1);
		for(int i=1;i<=n;i++){
			if(B[i]!=B[m]) B[m++]=B[i];
		}
		for(int i=1;i<=n;i++){
				F[i][0]=INT_MAX;
				for(int j=1;j<=m;j++)
				F[i][j]=min(F[i-1][j]+abs(A[i]-B[j]),F[i][j-1]);
		}
		printf("%lld",F[n][m]);
}
