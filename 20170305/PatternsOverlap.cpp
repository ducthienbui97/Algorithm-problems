#include <bits/stdc++.h>
using namespace std;
string s;
string p;
vector<int> vS,vP;
int done[2222][2222];
bool F[2222][2222];
int test;
bool f(int l,int r){
    if(l<0||r<0) return false;
    if(l==0&&r==0) return true;
    if(done[l][r] == test) return F[l][r];
    done[l][r] = test;
    F[l][r] = false;
    if(l == 0){
        F[l][r] = p[r-1]=='*'?f(l,r-1):false;
    }
    else if(r==0){
        F[l][r] = s[l-1]=='*'?f(l-1,r):false;
    }else{
        if(s[l-1] == '*' && p[r-1] == '*') F[l][r] = f(l-1,r)|f(l,r-1);
        else if(s[l-1] == '*'){
            F[l][r] |= f(l-1,r);
            for(int i=0;i<4;i++){
                int t = (lower_bound(vP.begin(),vP.end(),r)-i) - vP.begin();
                if(t<0) break;
                F[l][r] |= f(l-1,vP[t]-1);

            }
        }
        else if(p[r-1] == '*'){
            F[l][r] |= f(l,r-1);
            for(int i=0;i<4;i++){
                int t = (lower_bound(vS.begin(),vS.end(),l)-i) - vS.begin();
                if(t<0) break;
                F[l][r] |= f(vS[t]-1,r-1);
            }
        }
        if(s[l-1]==p[r-1])
            F[l][r] |= f(l-1,r-1);
    }
   // cout <<l <<" "<<r <<" "<<F[l][r]<<" "<<s[l-1]<<" "<<p[r-1]<<endl;
    return F[l][r];
}
int sol(){
    vS.clear();
    vP.clear();
    cin >> s >> p;
    vS.push_back(0);
    vP.push_back(0);
    for(int i=0;i<s.size();i++)
        if(s[i]!='*') vS.push_back(i+1);
    for(int j=0;j<p.size();j++)
        if(p[j]!='*') vP.push_back(j+1);
    if(f(s.size(),p.size()))
        printf("Case #%d: TRUE\n",test);
    else
        printf("Case #%d: FALSE\n",test);
}
main(){
    freopen("B-large-practice.in","r",stdin);
    freopen("output1.txt","w",stdout);
    int t;
    cin >> t;
    for(test = 1;test <=t;test++) sol();
}
