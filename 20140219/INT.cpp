#include <bits/stdc++.h>
#define elif else if
using namespace std;
int Nx[1000111];
bool mask[1000111];
int S[1000111];
stack<int> s;
int Next(int t){
    int tmp=t;
    while(mask[t]){
        s.push(t);
        t=Nx[t];
    }
    while(!s.empty()) Nx[s.top()]=t,s.pop();
    return t;
}
int get(int x){
    int rep=0;
    for(;x>0;x-=(x&(-x))) rep+=S[x];
    return rep;
}
void update(int x){
    for(;x<1000111;x+=(x&(-x))) S[x]++;
}
struct seg{
    int a,b,c;
    bool operator <(const seg& X)const{
        return make_pair(b,a)<make_pair(X.b,X.a);
    }
};
vector<seg> d;
int n;
main() {
    ios_base::sync_with_stdio(false);
    for(int i=1;i<1000111;i++)
        Nx[i]=i-1;
    cin>>n;
    d.resize(n);
    for(int i=0;i<n;i++)
        cin>>d[i].a>>d[i].b>>d[i].c;
    sort(d.begin(),d.end());
    for(int i=0;i<n;i++){
        int tmp=get(d[i].b)-get(d[i].a-1);
        d[i].c-=tmp;
        for(int j=Next(d[i].b);d[i].c>0;j=Next(j)){
            mask[j]=true;
            update(j);
            d[i].c--;
        }
    }
    printf("%d",get(1000000));
}
