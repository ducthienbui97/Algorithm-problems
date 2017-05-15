#include <message.h>
#include <bits/stdc++.h>
#include "pancakes.h"

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
const int Maxn = 1e6;
int main() {
	int id = MyNodeId();
	int nNode = NumberOfNodes();
	int sz = (int) GetStackSize();
	int d = (int) GetNumDiners();
	int cnt = 0;
	int last = -1;
  	for(int i=id*Maxn; i < min(sz,(id+1)*Maxn); i++){
  		int item = GetStackItem(i);
  		if(item < last) cnt++;
  		last = item;

  	}
	if (id == MASTER_NODE) {
		for(int i=1;i<nNode;i++){
			Receive(i);
			cnt += GetInt(i);
		}
		for(int i=1;i*Maxn < sz; i++)
			if(GetStackItem(i*Maxn) < GetStackItem(i*Maxn - 1)) cnt++;
		cout << cnt + 1<<endl;
  	} else {
  		PutInt(MASTER_NODE,cnt);
  		Send(MASTER_NODE);
  	}
  	return 0;
}
