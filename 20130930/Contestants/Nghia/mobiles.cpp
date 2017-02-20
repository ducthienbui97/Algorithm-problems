#include <algorithm>
#include <iostream>
#include <cmath>
#define ll int
using namespace std;
const int maxS = 1026;
int bit[maxS][maxS];
int S;

void update(int x,int y,int A){
	for(int i=x;i<=S;i+=(i&(-i)))
		for(int j=y;j<=S;j+=(j&(-j))){
			bit[i][j]+=A;
		}
}
ll get(int x,int y){
	ll ans=0;
	for(int i=x;i;i-=(i&-i))
		for(int j=y;j;j-=(j&-j)){
			ans+=1ll*bit[i][j];
		}
	return ans;
}
int main(){
    freopen("mobiles.inp","r",stdin);
    freopen("mobiles.out","w",stdout);
	ios::sync_with_stdio(false);
	int dir;
	int X,Y,A,L,B,R,T;
	while(cin>>dir,dir!=3){
		//if(dir==3) return 0;
		if(dir==0){
			cin>>S;
		}
		else if(dir==1){
			cin>>X>>Y>>A;
			X++;Y++;
			update(X,Y,A);
		}
		else if(dir==2){
			cin>>L>>B>>R>>T;
			R++,T++;
			printf("%d\n",get(R,T)+get(L,B)-get(L,T)-get(R,B));
		}
	}
	return 0;
}
