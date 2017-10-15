#include <bits/stdc++.h>

using namespace std;

const int maxN = 150;

map <string, int> topics;
int bookState[maxN];
int n;
int all;
int bookTime[maxN];
int G[2][1<<20];

int main() {
//    freopen("test.txt","r",stdin);
    memset(G, 0x3f, sizeof G);
    string s;
    while (getline(cin,s)) {
        stringstream ss(s);
        int t;
        ss >> t;
        bookTime[n] = t;
        string s2;
        while (ss >> s2){
            if(topics.find(s2) == topics.end())
                topics.emplace(s2,(int)topics.size());
            bookState[n] |= (1<< topics[s2]);
        }
        n ++;
    }

    all =  (1 << topics.size()) - 1;
    G[0][bookState[0]] = bookTime[0];
    G[0][0] = 0;
    for(int i = 1; i < n; i++){
        int rev = 1 - (i&1);
        for(int j = 0; j <= all; j++){
            G[i&1][j] = min(G[i&1][j],G[rev][j]);
            G[i&1][j|bookState[i]] = min(G[i&1][j|bookState[i]], G[rev][j]  + bookTime[i]);
        }

    }
    cout << G[1-(n&1)][all];
}

