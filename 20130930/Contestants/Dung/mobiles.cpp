#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int bit[1100][1100], n;

void update(int x, int y, int z){
	int k;
	k= x;
	while(y<=n){
		x= k;
		while(x<=n){
			bit[x][y]+= z;
			x+= (x&(-x));
		}
		y+= (y&(-y));
	}
	return;
}

int get(int x, int y){
	int k, sum= 0;
	k= x;
	while(y!=0){
		x= k;
		while(x!=0){
			sum+= bit[x][y];
			x= x&(x-1);
		}
		y= y&(y-1);
	}
	return sum;
}

int main(){
	freopen("mobiles.inp","r",stdin);
	freopen("mobiles.out","w",stdout);
	int i, code, x, y, z, x1, y1, x2, y2;
	while(scanf("%d", &code)){
		if(code==0){
			scanf("%d", &n);
		}
		else if(code==1){
			scanf("%d%d%d", &x, &y, &z);
			x++; y++;
			update(x,y,z);
		}
		else if(code==2){
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x1++; y1++; x2++; y2++;
			printf("%d\n", get(x2,y2)+ get(x1-1,y1-1)- get(x1-1,y2)- get(x2,y1-1));
		}
		else break;
	}
	return 0;
}
