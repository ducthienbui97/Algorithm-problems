#include <message.h>
#include <bits/stdc++.h>
#include "weird_editor.h"

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
long long pw(int x,int v){
	if(v == 0) return 1;
	if(v == 1) return x;
	long long  tmp = pw(x,v/2);
	tmp =  (tmp*tmp)%LARGE_PRIME;
	if(v % 2 == 1) tmp = (tmp * x) % LARGE_PRIME;
	return tmp;
}
int main() {
	int id = MyNodeId();
	int nNode = NumberOfNodes();
	int sz = GetNumberLength();
	deque<pair<int,pair<int,int> > > dq;
	for(int i=id*Maxn; i < min(sz,(id+1)*Maxn); i++){
		int dg = GetDigit(i);
		while(true){
			if(dq.size() == 0 || dq.back().first > dg){
				dq.emplace_back(dg,make_pair(dg,1));
				break;
			}
			else if(dq.back().first == dg){
				dq.back().second.second++ ;
				dq.back().second.first = ((10ll * dq.back().second.first) + dg) % LARGE_PRIME;
				break;
			}
			else if(dq.back().first < dg)
				dq.pop_back();
		}
	}
	if (id == MASTER_NODE) {
		for(int i=1;i<nNode;i++){
			Receive(i);
			int sz = GetInt(i);
			while(sz --){
				int dg = GetInt(i);
				int hs = GetInt(i);
				int cnt = GetInt(i);
				while(true){
					if(dq.size() == 0 || dq.back().first > dg){
						dq.emplace_back(dg,make_pair(hs,cnt));
						break;
					}else if(dq.back().first == dg){
						dq.back().second.second += cnt;
						dq.back().second.first = (pw(10,cnt)*dq.back().second.first + hs) % LARGE_PRIME;
						break;
					}else if(dq.back().first <dg)
						dq.pop_back();
				}
			}
		}
		int cnt = 0;
		long long ans = 0;
		for(int i=0;i<dq.size();i++){
			int hs = dq[i].second.first;
			int cn = dq[i].second.second;
			ans = (ans * pw(10,cn) + hs) % LARGE_PRIME;
			cnt += cn;
		}
		//cout << cnt <<endl;
		//cout << sz <<endl;
		ans = ans * pw(10,sz - cnt) % LARGE_PRIME;
		cout << ans % LARGE_PRIME <<endl;
  	} else {
  		PutInt(MASTER_NODE,dq.size());
  		for(int i=0;i<dq.size();i++){
  			//cout << id <<" "<< dq[i].first <<" "<<dq[i].second.first <<" "<<dq[i].second.second <<endl;
  			PutInt(MASTER_NODE,dq[i].first);
  			PutInt(MASTER_NODE,dq[i].second.first);
  			PutInt(MASTER_NODE,dq[i].second.second);	
  		}
  		Send(MASTER_NODE);
  	}
  	return 0;
}
