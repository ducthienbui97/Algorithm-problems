#include <message.h>
#include <bits/stdc++.h>
#include "query_of_death.h"

#define MASTER_NODE 0
#define SENDING_DONE -1
#define LARGE_PRIME 1000000007
/*
void PutChar(int target, char value);
void PutInt(int target, int value);
void PutLL(int target, long long value);
void Send(int target);

int Receive(int source);
char GetChar(int source);
int GetInt(int source);
long long GetLL(int source);
*/
using namespace std;
const int Maxn = 11e5;

int main() {
	int id = MyNodeId();
	int nNode = NumberOfNodes();
	int sz = GetLength();
	int ans = 0;
	if (id == MASTER_NODE) {
		for(int i=1;i<nNode;i++){
			Receive(i);
			int ok = GetInt(i);
			ans += GetInt(i);
			if(ok >= 0) {
				int end = min(i*Maxn,sz);
				for(int j=ok+1;j<end;j++)
					ans += GetValue(j);
			}
		}
		cout << ans <<endl;
		//cout << sz <<endl;
  	} else {
  		int start = (id-1)*Maxn;
  		int end = min(id*Maxn,sz);
  		int ok = -1;
  		for(int i=start;i<end && ok < 0;i++){
  			int v = GetValue(i); 
  			ans += v;
  			for(int j=0;j<10;j++)
  				if(GetValue(i) != v){
  					ok = i;
  					break;
  				}
  		}
  		PutInt(MASTER_NODE,ok);
  		PutInt(MASTER_NODE,ans);
  		Send(MASTER_NODE);
  	}
  	return 0;
}
