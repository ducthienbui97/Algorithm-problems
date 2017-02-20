#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
char d[20];
int m;
int n;
bool check(int k){
     int x=k;
     k=sqrt(k);
     for(int i=2;i<=k;i++)
          if(!(x%i)) return false;
     return true;
}
void bt(int now,int k){
     int x;
     if(now<n)
     for(int i=0;i<2;i++){
          x=k;
          if(i){
              x=x*10+(d[now]-'0');
          }
          bt(now+1,x);
     }
     else {
          if(k<=m) return;
          if(check(k)) m=k;
     }
     return;
}
main(){
     scanf("%s",d);
     n=strlen(d);
     m=0;
     bt(0,0);
     if(m<2) m=-1;
	cout<<m;
     
}
