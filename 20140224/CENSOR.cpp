#include <bits/stdc++.h>
#define elif else if
using namespace std;
bool ok[300033][30],Ok[300033][30];
vector<int> lis[30];
char S[300033],C[111];
int prv[300033];
int nxt[300033];
stack<int> s;
bool mask[300033];
main() {
    ios_base::sync_with_stdio(false);
    cin>>C+1>>S+1;
    int n=strlen(S+1);
    int m=strlen(C+1);
    for(int i=0; i<=n+1; i++) {
        ok[i][0]=true;
        Ok[i][m+1]=true;
        prv[i]=i-1;
        nxt[i]=i+1;
        }
    for(int i=1; i<=m; i++)
        lis[C[i]-'a'].push_back(i);
    int i=1,k=n;
    while(i<=n||k>0) {
        for(; i<=n; i++) if(!mask[i]){
            int pr=prv[i];
            while(mask[pr]) {
                s.push(pr);
                pr=prv[pr];
                }
            while(!s.empty()) prv[s.top()]=pr,s.pop();
            for(int j=0; j<lis[S[i]-'a'].size(); j++)
                if(ok[pr][lis[S[i]-'a'][j]-1]) ok[i][lis[S[i]-'a'][j]]=true;
            if(ok[i][m]) {
                for(int j=1; j<=m; j++) {
                    pr=i;
                    while(mask[pr]) {
                        s.push(pr);
                        pr=prv[pr];
                        }
                    while(!s.empty()) prv[s.top()]=pr,s.pop();
                    mask[pr]=true;
                    }
                break;
                }
            }
        for(; k>0; k--)if(!mask[k]) {
            int pr=nxt[k];
            while(mask[pr]) {
                s.push(pr);
                pr=nxt[pr];
                }
            while(!s.empty()) nxt[s.top()]=pr,s.pop();
            for(int j=0; j<lis[S[k]-'a'].size(); j++)
                if(Ok[pr][lis[S[k]-'a'][j]+1]) Ok[k][lis[S[k]-'a'][j]]=true;
            if(Ok[k][1]) {
                for(int j=1; j<=m; j++){
                    pr=k;
                    while(mask[pr]){
                        s.push(pr);
                        pr=nxt[pr];
                        }
                    while(!s.empty()) nxt[s.top()]=pr,s.pop();
                    mask[pr]=true;
                    }
                break;
                }
            }
        }
    for(int i=1; i<=n; i++)
        if(!mask[i]) putchar(S[i]);
    }
/*
ne
lukanevolisarmu

aba
ababacccababa

banana
babananananadeda

*/
