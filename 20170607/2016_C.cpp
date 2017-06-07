#include <bits/stdc++.h>
#include <message.h>
#include "lisp_plus_plus.h"

#define MASTER_NODE 0
using namespace std;
const int Max = 1e7;
int n,nNode,id;
int find(int nodeId,int r){
    for(int i = nodeId*Max; i < min(n,(nodeId+1)*Max);i++){
        if(GetCharacter(i) == '(') r++;
        else r--;
        if(r<0) return i;
    }
}
int main(){
    nNode = NumberOfNodes();
    id = MyNodeId();
    n = GetLength();
    int left = 0;
    int right = 0;
    for(int i=id*Max;i < min(n,(id+1)*Max); i++){
        if(GetCharacter(i) == '(') right ++;
        else{
            if(right > 0) right --;
            else left ++;
        }
    }

    if(id != MASTER_NODE){
        //cout << id <<endl;
        PutInt(MASTER_NODE,left);
        PutInt(MASTER_NODE,right);
        Send(MASTER_NODE);
    }else{
        int ans = -1;
        if(left > 0) ans = find(0,0);
        else{
            for(int i=1;i<nNode;i++){
                Receive(i);
                int nxL = GetInt(i);
                int nxR = GetInt(i);
                //cout << i <<" "<<nxL <<" "<<nxR<<" "<<left <<" "<<right<<endl;
                if(right - nxL < 0){
                    ans = find(i,right);
                    right -= nxL;
                    break;
                }else{
                    right = right - nxL + nxR;
                }
            }
            //cout << right <<endl;
            if(right > 0) ans = n;
        }
        cout << ans << endl;
    }
    return 0;
}

