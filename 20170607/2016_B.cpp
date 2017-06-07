#include <bits/stdc++.h>
#include <message.h>
#include "again.h"

#define MASTER_NODE 0
#define SENDING_DONE -1
#define LARGE_PRIME 1000000007
using namespace std;
int main(){
    int nNode = NumberOfNodes();
    int id = MyNodeId();
    int n = GetN();
    long long sA = 0;
    long long sB = 0;
    for(int i=id;i < n; i+= nNode){
        //cout << i <<" "<<GetA(i) <<" "<<GetB(i)<<endl;
        sA = (sA + GetA(i))%LARGE_PRIME;
        sB = (sB + GetB(i))%LARGE_PRIME;
    }
    if(id != MASTER_NODE){
        //cout << id <<endl;
        PutLL(MASTER_NODE,sA);
        PutLL(MASTER_NODE,sB);
        Send(MASTER_NODE);
    }else{
        vector<long long> A;
        vector<long long> B;
        A.push_back(sA);
        B.push_back(sB);
        for(int node = 1; node < nNode; node ++){
            //cout << node <<endl;
            Receive(node);
            A.push_back(GetLL(node));
            B.push_back(GetLL(node));
            //cout << node <<" "<<A.back()<<" " <<B.back()<<endl;
        }
        long long ans = 0;
        for(int i=0;i<nNode;i++)
            for(int j=0;j<nNode;j++){
                //cout <<i <<" "<<A[i] <<" "<<endl;
                if((i+j)%nNode) ans = (ans + A[i]*B[j]%LARGE_PRIME)%LARGE_PRIME;
            }
        cout << ans << endl;
    }
    return 0;
}
