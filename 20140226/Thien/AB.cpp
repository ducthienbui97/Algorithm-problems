#include <bits/stdc++.h>
#define elif else if
using namespace std;
struct big{
    bool d;
    deque<int> v;
    big(){v.clear();d=false;}
    big(string& S){
        if(S[0]=='-') d=true;
        else d=false;
        for(int i=d;i<S.size();i++)
            v.push_front(S[i]-'0');

    }
    int& operator [](int t){return v[t];}
    void  clear0(){
        while(v.size()>1&&v.back()==0) v.pop_back();
        if(v.size()==1&&v.back()==0) d=false;
    }
};
big operator +(big x,big y);
big operator -(big x,big y);
void pin(big & x){
    x.clear0();
    if(x.d) putchar('-');
    for(int i=x.v.size()-1;i>=0;i--)
        printf("%d",x.v[i]);
    putchar('\n');
}
bool operator <(const big& x,const big& y){
    if(x.v.size()==y.v.size()){
        for(int i=x.v.size()-1;0<=i;i--)
        if(x.v[i]==y.v[i]) continue;
        else return x.v[i]<y.v[i];
    }
    return x.v.size()<y.v.size();
}
big operator -(big x,big y){
    big z;
    if(x.d){
        x.d=false;
        z=x+y;
        z.d=!z.d;
        return (z);
    }
    if(y.d){
        y.d=false;
        z=x+y;
        return z;
    }
    if(x<y){
        z=y-x;
        z.d=!z.d;
        return z;
    }
    int r=0;
    for(int i=0;i<x.v.size();i++){
        int t1,t2;
        t1=x[i];
        if(i>=y.v.size()) t2=0;
        else t2=y[i];
        t2+=r;
        r=0;
        if(t1<t2) t1+=10,r=1;
        z.v.push_back(t1-t2);
    }
    z.clear0();
    return z;
}
big operator +(big x,big y){
    big z;
    if(x.d){
        x.d=false;
        z=y-x;
        return z;
    }
    if(y.d){
        y.d=false;
        z=x-y;
        return z;
    }
    int r=0;
    for(int i=0;i<=max(x.v.size(),y.v.size());i++){
        int t1,t2;
        if(i>=x.v.size()) t1=0;
        else t1=x[i];
        if(i>=y.v.size()) t2=0;
        else t2=y[i];
        z.v.push_back(t1+t2+r);
        if(z.v.back()>=10) r=1,z.v.back()-=10;
        else r=0;
    }
    z.clear0();
    return z;
}
big operator / (big x,int y){
    int r=0;;
    for(int i=x.v.size()-1;i>=0;i--){
        x[i]+=r*10;
        r=x[i]%y;
        x[i]/=y;
    }
    x.clear0();
    return x;
}
big T,H;
big A,B;
main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    T=big(s);
    cin>>s;
    H=big(s);
    A=(T+H)/2;
    B=T-A;
    pin(A);
    pin(B);
    }
