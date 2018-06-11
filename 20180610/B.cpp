#include <bits/stdc++.h>
#include <message.h>
#include "stones.h"
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
const int MAX = 1e6;
const int SIZE = MAX + 10;
int IT[SIZE<<3];
int Farthest[SIZE];
int step[SIZE];
int last[SIZE];
void construct(int node,int l, int r) {
    if(l > r)
        return;
    if(l == r) {
        IT[node] = l;
    } else {
        construct(2*node,l,(l+r)/2);
        construct(2*node+1,(l+r)/2+1,r);
        if(Farthest[IT[2*node]] > Farthest[IT[2*node + 1]])
            IT[node] = IT[2*node];
        else
            IT[node] = IT[2*node + 1];
    }
}

int get(int node,int l,int r,int u,int v) {
    if(l > v || r < u || l > r)
        return -1;
    if(u <= l && r <= v)
        return IT[node];
    int L = get(2*node,l,(l+r)/2,u,v);
    int R = get(2*node+1,(l+r)/2+1,r,u,v);
    if(L == -1)
        return R;
    else if(R == -1)
        return L;
    else if(Farthest[L] > Farthest[R])
        return L;
    else
        return R;
}

main() {
    int id = MyNodeId();
    int nNode = NumberOfNodes();
    int n = GetNumberOfStones();
    int mMax = 0;
    int idxMax = -1;
    int start = id*MAX;
    int endd = min((id+1)*MAX,n);
    for(int i = start + 1; i <= endd; i++) {
        Farthest[i - start] = i + GetJumpLength(i);
        if(Farthest[i - start] > mMax) {
            idxMax = i;
            mMax = Farthest[i - start];
        }
    }
    construct(1,1,endd - start);
    for(int i = endd; i > start; i--) {
        if(Farthest[i - start] > endd) {
            step[i - start] = 1;
            last[i - start] = i - start;
        } else {
            int maximal = get(1,1,endd - start,i + 1 - start, Farthest[i - start] - start);
            step[i - start] = step[maximal] + 1;
            last[i - start] = last[maximal];
        }
    }
    if (id == MASTER_NODE) {
        Farthest[0] = GetJumpLength(0);
        if(Farthest[0] > endd) {
            step[0] = 1;
            last[0] = 0;
        } else {
            int maximal = get(1,1,endd - start, 1, Farthest[0]);
            step[0] = step[maximal] + 1;
            last[0] = last[maximal];
        }
        vector<int> Far;
        Far.push_back(idxMax);
        for(int i = 1; i < nNode; i++) {
            Receive(i);
            Far.push_back(GetInt(i));
        }
        int current = 0;
        int ans = 0;
        int curr_end = endd;
        int curr_id = MASTER_NODE;
        while(true) {
            if(curr_id == MASTER_NODE) {
                ans += step[current];
                current = last[current];
            } else {
                PutInt(curr_id,2);
                PutInt(curr_id, current);
                Send(curr_id);
                Receive(curr_id);
                ans += GetInt(curr_id);
                current = GetInt(curr_id);
            }
            int reach = current + GetJumpLength(current);
            int farthest = current;
            int next_lo = -1;
            if(reach > n) {
                break;
            }
            for(int i = curr_id + 1; (i+1)*MAX < reach; i++) {
                int d = Far[i] + GetJumpLength(Far[i]);
                if(d > farthest) {
                    farthest = d;
                    next_lo = Far[i];
                }
            }
            if(current < curr_end) {
                int  maximal;
                if(curr_id == MASTER_NODE) {
                    maximal = get(1,1,curr_end,current + 1, curr_end);
                } else {
                    PutInt(curr_id, 3);
                    PutInt(curr_id,current + 1);
                    Send(curr_id);
                    Receive(curr_id);
                    maximal = GetInt(curr_id);
                }
                int d = maximal + GetJumpLength(maximal);
                if(d > farthest) {
                    farthest = d;
                    next_lo = maximal;
                }
            }
            int reach_id = (reach - 1)/MAX;
            PutInt(reach_id,1);
            PutInt(reach_id,reach);
            Send(reach_id);
            Receive(reach_id);
            int maximal = GetInt(reach_id);
            int d = maximal + GetJumpLength(maximal);
            if(d > farthest) {
                farthest = d;
                next_lo = maximal;
            }
            current = next_lo;
            curr_id = (current - 1)/MAX;
            curr_end = MAX*(curr_id + 1);
        }
        for(int i = 1; i < nNode; i++) {
            PutInt(i, SENDING_DONE);
            Send(i);
        }
        cout << ans << endl;
    } else {
        PutInt(MASTER_NODE, idxMax);
        Send(MASTER_NODE);
        while(true) {
            Receive(MASTER_NODE);
            int q = GetInt(MASTER_NODE);
            if(q == SENDING_DONE)
                return 0;
            if(q == 1) { // find maximal from start to node;
                int node = GetInt(MASTER_NODE);
                PutInt(MASTER_NODE, start + get(1,1,endd - start,1, node - start));
                Send(MASTER_NODE);
            }
            if(q == 2) {
                int node = GetInt(MASTER_NODE);
                PutInt(MASTER_NODE, step[node - start]);
                PutInt(MASTER_NODE, start + last[node - start]);
                Send(MASTER_NODE);
            }
            if(q == 3) { // find maximal from node to end
                int node = GetInt(MASTER_NODE);
                PutInt(MASTER_NODE,start + get(1,1,endd - start,node - start, endd - start));
                Send(MASTER_NODE);
            }
        }
    }
}
