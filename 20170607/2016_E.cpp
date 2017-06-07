#include <bits/stdc++.h>
#include <message.h>
#include "gas_stations.h"

#define MASTER_NODE 0
using namespace std;
const int Max = 5e6;
int n,nNode,id;
int main(){
    nNode = NumberOfNodes();
    id = MyNodeId();
    n = GetNumKms();
    int L = id*Max;
    int R = min(n,id*Max+Max);
    if(L > R) L = R;
    deque<pair<int,int> > d;
    deque<int> v;
    int tank = GetTankSize();
    // Find Min of node
    int Min = 1<<30;
    for(int i = L; i < R;i++){
        v.push_back(GetGasPrice(i));
        if(v.back() < Min) Min = v.back();
    }
    // Broadcast min of node
    for(int i=id+1;i<nNode;i++)
    if(i!= id){
        PutInt(i,Min);
        Send(i);
    }
    // Get min of previous nodes
    vector<int> MinOf(id);
    for(int i=0;i<id;i++){
        Receive(i);
        MinOf[i] = GetInt(i);
    }

    // Preprocess
    for(int i=max(0,L-tank),cnt = 2;;i++){
        if(i == L) break;
        if(!(i % Max)) cnt--;
        if(!cnt){
            // passed thru 2 interval points,
            //remaining distance will alway within tank so no need to go further, just get the min of node
            for(;i < L; i+= Max){
                int price = MinOf[i/Max];
                while(!d.empty() && d.back().second >= price) d.pop_back();
                d.emplace_back(i,price);
            }
            break;
        }
        int price = GetGasPrice(i);
        while(!d.empty() && d.back().second >= price) d.pop_back();
        d.emplace_back(i,price);
    }
    long long ans = 0;
    for(int i=L;i<R;i++){
        int price = v.front();
        while(!d.empty() && d.front().first < i - tank + 1) d.pop_front();
        while(!d.empty() && d.back().second >= price) d.pop_back();
        d.emplace_back(i,price);
        v.pop_front();
        ans += d.front().second;
    }
    if(id != MASTER_NODE){
        PutLL(MASTER_NODE,ans);
        Send(MASTER_NODE);
    }else{
        for(int i=1;i<nNode;i++){
            Receive(i);
            ans += GetLL(i);
        }
        cout << ans << endl;
    }
    return 0;
}


