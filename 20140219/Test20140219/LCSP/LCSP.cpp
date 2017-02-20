#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h>
#define maxn 100005
#define For(i,n) for(int i=0; i<n; i++)

using namespace std;

char X[4][maxn];
int L, result;
map<pair<int, int>,int> occur;
pair<int, int> pairs[2][maxn];

void read(){
	scanf("%s\n%s", X[0], X[1]);
	L = strlen(X[0]);
	For(i,L) X[2][i] = X[0][L - i - 1], X[3][i] = X[1][L - i - 1];
    cerr<<X[0]<<" "<<X[1]<<" "<<X[2]<<" "<<X[3];
}
/*
ADAEABAE
ABADABAE
*/

bool check(int l){
	occur.clear();
	long long r[2] = {1, 1}, base[2] = {27, 29}, cs[2] = {(long long)2e9+7, (long long)2e9+9};
	For(i,l) For(b,2) r[b] = (base[b] * r[b]) % cs[b];
	For(k,2){
		long long mod[2] = {0, 0};
		For(i,l-1) For(b,2) mod[b] = (base[b] * mod[b] + X[2+k][i] - 'A') % cs[b];
		For(i,L-l) {
			For(b,2)
				mod[b] = ((base[b] * mod[b] + (X[2+k][l+i-1] - 'A') - r[b] * ((i > 0)? X[2+k][i-1] - 'A' : 0)) % cs[b] + cs[b]) % cs[b];
			pairs[k][L - i - 1] = make_pair<int,int>(mod[0], mod[1]);
		}
	}
	For(k,2){
		long long mod[2] = {0, 0};
		For(i,l-1) For(b,2) mod[b] = (base[b] * mod[b] + X[k][i] - 'A') % cs[b];
		For(i,L-l) {
			For(b,2)
				mod[b] = ((base[b] * mod[b] + (X[k][l+i-1] - 'A') - r[b] * ((i > 0)? X[k][i-1] - 'A' : 0)) % cs[b] + cs[b]) % cs[b];
			pair<int, int> xy = make_pair<int,int>(mod[0], mod[1]);
			if (pairs[k][i + l - 1] == xy && (k == 0 || occur[xy] == k)){
				occur[make_pair<int,int>(mod[0], mod[1])] = k+1;
				if (k == 1) return true;
			}
		}
	}
	return false;
}

void process(int k){
	int cd = 1 - k, ct = L / 2;
	int best = -1;
	while (cd <= ct){
		int mid = (cd + ct) / 2;
		if (check(2*mid + k))
			best = mid, cd = mid + 1;
		else
			ct = mid - 1;
	}
	result = max(result, 2 * best + k);
}

void print(){
	cout<<result<<endl;
}

int main(){
	read();
	process(0);
	process(1);
	print();
	return 0;
}
