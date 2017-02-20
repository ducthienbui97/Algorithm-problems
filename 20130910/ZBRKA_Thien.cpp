#include <bits/stdc++.h>
#define elif else if
using namespace std;
int a[2][10011];
const int Mod=1e9+7;
main(){
	ios_base::sync_with_stdio(false);
	int n;
	int c;
	cin>>n>>c;
    a[1][0]=1;
	for(int i=2;i<=n;i++){
        bool d=i&1;
        a[d][0]=1;
		for(int j=1;j<=c;j++){
			a[d][j]=(a[d][j-1]+a[!d][j])%Mod;
            if(j>=i){
				a[d][j]=(a[d][j]-a[!d][j-i]+Mod)%Mod;
			}
		}
	}
	cout<<a[n&1][c];
}
