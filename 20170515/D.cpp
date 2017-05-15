#include <message.h>
#include <bits/stdc++.h>
#include "todd_and_steven.h"

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
const int Maxn = 1e7;

int main() {
	int id = MyNodeId();
	int nNode = NumberOfNodes();
	int sz1 = GetToddLength();
	int sz2 = GetStevenLength();
	int start = id * Maxn;
	int end = (id+1)*Maxn;
	long long ans = 0;
	for(int i =start; i<min(sz1,end);i++){
		long long val = GetToddValue(i);
		int l = 0;
		int r = sz2 - 1;
		int rep = sz2;
		while(l <= r){
			int mid = (l+r)>>1;
			long long v2 = GetStevenValue(mid);
			if(v2 > val){
				r = mid -1;
				rep = mid;
			}else l = mid + 1;
		}
		ans = (ans + (val^(rep + i))) % LARGE_PRIME;
	}
	for(int i =start; i<min(sz2,end);i++){
		long long val = GetStevenValue(i);
		int l = 0;
		int r = sz1 - 1;
		int rep = sz1;
		while(l <= r){
			int mid = (l+r)>>1;
			long long v2 = GetToddValue(mid);
			if(v2 > val){
				r = mid -1;
				rep = mid;
			}else l = mid + 1;
		}
		ans = (ans + (val^(rep + i))) % LARGE_PRIME;
	}
	if (id == MASTER_NODE) {
		for(int i=1;i<nNode;i++){
			Receive(i);
			ans = (ans + GetLL(i)) % LARGE_PRIME;
		}
		cout << ans <<endl;
		//cout << sz <<endl;
  	} else {
  		PutLL(MASTER_NODE,ans);
  		Send(MASTER_NODE);
  	}
  	return 0;
}
