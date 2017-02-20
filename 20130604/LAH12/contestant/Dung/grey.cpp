#include <cstdio>
#include <iostream>

using namespace std;

char a[1050000][25];

int main(){
	freopen("grey.inp","r",stdin);
	freopen("grey.out","w",stdout);
	long n, i, j, k, t;
	scanf("%ld", &n);
	for(i=1;i<=n;i++){
		a[0][i]= '0';
		a[1][i]= '0';
	}
	a[1][n]= '1';
	for(i=1;i<n;i++){
		t= 0;
		for(j=(1<<i);j<(1<<(i+1));j++){
			t++;
			for(k=1;k<=n;k++)
				a[j][k]= a[(1<<i)-t][k];
			a[j][n-i]= '1';
		}
	}
	for(i=0;i<(1<<n);i++){
		for(j=1;j<=n;j++){
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}
