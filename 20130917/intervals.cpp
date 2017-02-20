#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
iii a[50005];
int bit[50005];
bool sign[50005];

int get(int x, int y){
	int s= 0, z;
	z= y;
	while(z!=0){
		s+= bit[z];
		z= z&(z-1);
	}
	z= x-1;
	while(z!=0){
		s-= bit[z];
		z= z&(z-1);
	}
	return s;
}

int main(){
	freopen("intervals.inp","r",stdin);
	freopen("intervals.out","w",stdout);
	int n, i, x, y, z, s, j, t, res= 0;
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d", &x, &y, &z);
		a[i]= (iii(y, ii(x,z)));
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++){
		x= a[i].second.first;
		y= a[i].first;
		z= a[i].second.second;
		s= get(x,y);
		if(s>=z) continue;
		s= z-s;
		for(j=y;j>=x;j--){
			if(sign[j]==false){
				s--;
				sign[j]= true;
				res++;
				t= j;
				while(t<=50000){
					bit[t]++;
					t+= (t&(-t));
				}
			}
			if(s==0) break;
		}
	}
	printf("%d\n", res);
	return 0;
}
