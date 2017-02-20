#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <utility>
#include <climits>
#include <vector>
#include <cstring>
#include <deque>
#include <queue>
#include <algorithm>
#include <map>
#define elif else if
using namespace std;
int n,m;
void  printb(	int k){
	for(int i=n;i>=0;i--)
	if(k&(1<<i)) putchar('1');
	else putchar('0');
	putchar('\n');
	}
main(){
	freopen("grey.inp","r",stdin);
	freopen("grey.out","w",stdout);
	scanf("%d",&n);
	m=1<<n;
	n--;
	for(int i=0;i<m;i++){
		printb((i>>1)^i);
		
	}
}
