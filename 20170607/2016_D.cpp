#include <bits/stdc++.h>
#include <message.h>
#include "asteroids.h"

#define MASTER_NODE 0
using namespace std;
const int MaxSize = 300;
int n,nNode,id;
vector<int> F[MaxSize+2];
string S[MaxSize+2];
vector<int> bucket;
vector<int> p;
int W,H,Dw,Up;
int get(int x,int y) {
    while(S[x - Dw].size() <= y) S[x - Dw].push_back(GetPosition(x,S[x - Dw].size()));
    char c = S[x - Dw][y];
    return c=='#'?-1:c-'0';
}
int main() {
    nNode = NumberOfNodes();
    id = MyNodeId();
    W = GetWidth();
    H = GetHeight();
    Dw = id*MaxSize;
    Up = (id+1)*MaxSize;
    if(Up > H) Up = H;
    if(Dw >= Up) return 0;
    for(int i=0; i < W; i += MaxSize)
        bucket.push_back(i);
    bucket.push_back(W);
    F[Up-Dw].resize(W);
    if(Up < H) {
        Receive(id+1);
        for(int y = 0; y < bucket[1]; y++) {
            F[Up-Dw][y] = GetInt(id+1);
            //cout <<Up <<"~"<< y << endl;
            //cout << Up <<" "<<F[Up-Dw][y] <<endl;
        }
    }
    int x = Up - 1;
    int y = 0;
    for(int i=1; i<bucket.size(); i++) {
        int L = bucket[i - 1];
        int R = bucket[i];
        int R2 = i + 1 >= bucket.size()? W : bucket[i+1];
        if(Up < H && R < R2) {
            Receive(id+1);
            for(int y = R; y < R2; y++){
                F[Up-Dw][y] = GetInt(id+1);
                //cout <<Up <<"~"<<y<<endl;
            }
        }
        //cout << R2 <<endl;
        while(y < R2 && x >= Dw && y >= 0) {
            while(F[x - Dw].size() <= y) F[x - Dw].resize(R2);
            F[x - Dw][y] = -1;
            int v = get(x,y);
            //cout << x <<" "<<y <<" "<<v<<endl;
            if(v != -1) {
                if(F[x - Dw + 1][y] != -1)
                    F[x - Dw][y] = max(F[x - Dw][y], F[x - Dw + 1][y] + v);
                if(y > 0) {
                    int v2 = get(x,y - 1);
                    if(v2 != -1 && F[x - Dw +1][y - 1]!= -1)
                        F[x - Dw][y] = max(F[x - Dw][y], F[x - Dw + 1][y - 1] + v + v2);
                }
                if(y < W - 1) {
                    int v2 = get(x,y + 1);
                    //cout << x<<" "<<y <<" "<<v2<<endl;
                    //cout << x <<" "<<y + 1 <<endl;
                    //cout << F[x - Dw +1][y+1] <<endl;
                    //cout << x - Dw + 1 <<" " <<Up - Dw <<endl;
                    if(v2 != -1 && F[x - Dw +1][y + 1]!= -1)
                        F[x - Dw][y] = max(F[x - Dw][y], F[x - Dw + 1][y + 1] + v + v2);
                }
            }
                   // cout <<x <<" "<<y <<" "<<F[x-Dw][y] <<endl;

            if(y == 0 || x == Dw) {
                int t = x - y;
                x = Up - 1;
                y = x - t + 1;
                if(y >= W){
                    t = y - W + 1;
                    x -= t;
                    y = W - 1;
                    //cout <<x <<" "<<y<<endl;
                }
            } else {
                x -= 1;
                y -= 1;
            }
        }
        if(id) {
            for(int y=L; y<R; y++) {
                PutInt(id - 1,F[0][y]);
            }
            Send(id - 1);
        }
    }
    if(!id) {
        int ans = -1;
        for(int i=0; i<W; i++)
            ans = max(ans,F[0][i]);
        cout << ans <<endl;
    }
    return 0;
}



