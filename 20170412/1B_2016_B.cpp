#include <bits/stdc++.h>
using namespace std;
string s1,s2;
long long Min;
long long C,J;
const long long pw[19] = {  0,
                            10,
                            100,
                            1000,
                            10000,
                            100000,
                            1000000,
                            10000000,
                            100000000,
                            1000000000,
                            10000000000ll,
                            100000000000ll,
                            1000000000000ll,
                            10000000000000ll,
                            100000000000000ll,
                            1000000000000000ll,
                            10000000000000000ll,
                            100000000000000000ll,
                            1000000000000000000ll};
void bt(int id,long long c,long long j){
    if(pw[s1.size()-id]*(abs(c-j)-1) > Min) return;
    if(id==s1.size()){
        if(abs(c-j) < Min || ((abs(c-j) == Min) &&(c < C || (c==C && j < J)))){
            Min = abs(c-j);
            C = c;
            J = j;
        }
        return;
    }
    else{
        if(s1[id]=='?'&&s2[id]=='?'){
            bt(id+1,c*10,j*10);
            bt(id+1,c*10,j*10+1);
            bt(id+1,c*10+1,j*10);
            bt(id+1,c*10+9,j*10);
            bt(id+1,c*10,j*10+9);
        }else if(s1[id]=='?'){
            bt(id+1,c*10,j*10+s2[id]-'0');
            bt(id+1,c*10+s2[id]-'0',j*10+s2[id]-'0');
            bt(id+1,c*10+9,j*10+s2[id]-'0');
            if(s2[id] != '9') bt(id+1,c*10+s2[id]-'0'+1,j*10+s2[id]-'0');
            if(s2[id] != '0') bt(id+1,c*10+s2[id]-'0'-1,j*10+s2[id]-'0');

        }else if(s2[id]=='?'){
            bt(id+1,c*10+s1[id]-'0',j*10+s1[id]-'0');
            bt(id+1,c*10+s1[id]-'0',j*10);
            bt(id+1,c*10+s1[id]-'0',j*10+9);
            if(s1[id] != '9') bt(id+1,c*10+s1[id]-'0',j*10+s1[id]-'0'+1);
            if(s1[id] != '0') bt(id+1,c*10+s1[id]-'0',j*10+s1[id]-'0'-1);
        }else bt(id+1,c*10+s1[id]-'0',j*10+s2[id]-'0');
    }
}
void solve(int nTest){
    cin >> s1 >> s2;
    Min = 1ll<<62;
    bt(0,0,0);
    cout <<"Case #"<<nTest<<": "<<setfill('0') << setw(s1.size())<<C<<" "<<setw(s1.size())<<J<<endl;;
}
main(){
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}

