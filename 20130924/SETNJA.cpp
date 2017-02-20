#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <climits>
#include <algorithm>
#define elif else if
using namespace std;
const int r=10000;
struct big {
    deque <int> v;
    int size() {
        return v.size();
        }
    int& operator [](int i) {
        return v[i];
        }
    int& back() {
        return v.back();
        }
    int& front() {
        return v.front();
        }
    void push_back(int t) {
        v.push_back(t);
        }
    void pop_back() {
        v.pop_back();
        }

    void push_front(int t) {
        v.push_front(t);
        }
    void pop_front() {
        v.pop_front();
        }
    };
void removezero(big& x) {
    while(x.size()>=1&&x.back()==0)
        x.pop_back();
    }
bool operator==(big& a,big& b) {
    removezero(a);
    removezero(b);
    if(a.size()!=b.size()) return false;
    for(int i=a.size()-1; i>=0; i--)
        if(a[i]!=b[i])return false;
    return true;
    }
bool operator <(big& a,big& b) {
    removezero(a);
    removezero(b);
    if(a.size()<b.size()) return true;
    if(a.size()>b.size()) return false;
    for(int i=a.size()-1; i>=0; i--)
        if(a[i]>b[i]) return false;
    elif(a[i]<b[i]) return true;
    return false;
    }
bool operator >(big& a,big& b) {
    return b<a;
    }
bool operator >=(big& a,big& b) {
    return !(a<b);
    }
bool operator <=(big& a,big& b) {
    return !(a>b);
    }
big getbig(const string& c) {
    int k=0;
    big x;
    int i,j;
    for(i=c.size()-4; i>0; i-=4) {
        k=0;
        for( j=0; j<4; j++) {
            k=10*k+(c[i+j]-'0');
            }
        x.push_back(k);
        }
    k=0;
    for(j=0; j<i+4; j++) {
        k=10*k+(c[j]-'0');
        }
    x.push_back(k);
    return x;
    }
void pin(big& x) {
    removezero(x);
    if(x.size()==0) {
        printf("0\n");
        return;
        }
    for(int i=x.size()-1; i>=0; i--) {
        if(i<x.size()-1) {
            printf("%04d",x[i]);

            }
        else printf("%d",x[i]);
        }
    printf("\n");
    }
big operator - (big a,big b) {
    int x=a.size(),y=b.size();
    if(x<y) {
        for(; x<y; x++)
            a.push_back(0);
        }
    elif(y<x) {
        for(; y<x; y++)
            b.push_back(0);
        }
    int d=0;
    big kq;
    for(int i=0; i<x; i++) {
        kq.push_back(0);
        }
    for(int i=0; i<x; i++) {
        kq[i]=a[i]-b[i]-d;
        d=0;
        if(kq[i]<0) {
            d=1;
            kq[i]=kq[i]+r;
            }
        }
    if(d==1) {
        kq=b-a;
        kq.back()=0-kq.back();
        }

    return kq;
    }
big operator +(big a,big b) {
    int x=a.size(),y=b.size();
    if(x<y) {
        for(; x<y; x++)
            a.push_back(0);
        }
    elif(y<x) {
        for(; y<x; y++)
            b.push_back(0);
        }
    int d=0;
    big kq;
    for(int i=0; i<=x; i++) {
        kq.push_back(0);
        }
    for(int i=0; i<x; i++) {
        kq[i]=d+a[i]+b[i];
        d=0;
        if(kq[i]>=r) {
            d=1;
            kq[i]=kq[i]%r;
            }
        }
    if(d==0) kq.pop_back();
    else kq[x]=1;
    return kq;

    }
big operator *(big a,int b) {
    int k=r,d=0;
    big ans;
    for(int i=0; i<a.size(); i++) {
        ans.push_back(0);
        }
    for(int i=0; i<a.size(); i++) {
        ans[i]=a[i]*b+d;
        d=0;
        if(ans[i]>=k) {
            d=ans[i]/k;
            ans[i]=ans[i]%k;
            }
        }
    while(d) {
        ans.push_back(d);
        d=0;
        if(ans.back()>=k) {
            d=ans.back()/k;
            ans.back()=ans.back()%k;
            }
        }
    return ans;
    }
big operator *(big a,big b) {
    big ans,z;
    int i,j,l,x,y;
    x=a.size();
    y=b.size();
    for(i=0; i<x; i++) {
        z=b*a[i];
        for(j=0; j<i; j++)
            z.push_front(0);
        ans=ans+z;
        }
    return ans;
    }
big operator ^(big a,int x) {
    if(x==1) return a;
    if(x%2==0) {
        big k= a^(x/2);
        return k*k;
        }
    else return a*(a^(x-1));
    }
big div2(big &x) {
    int buf=0;
    for(int i=x.size()-1; i>=0; i--) {
        int d=x[i]&1;
        x[i]=(r*buf+x[i])>>1;
        buf=d;
        }
    removezero(x);
    return x;
    }
vector<int> to2ver(big& x,int l) {
    vector<int> d;
    d.resize(l);
    int cnt=0;
    while(x.size()) {
        d[cnt++]=(x.front()&1);
        div2(x);
        }
    reverse(d.begin(),d.end());
    return d;
    }
big to10ver(vector<int>& d) {
    big x;
    x.push_back(0);
    for(int i=0; i<d.size(); i++) {
        if(d[i]) x.front()++;
        x=x*2;
        }
    div2(x);
    return x;
    }
big operator+(big x,int buf){
    for(int i=0;i<x.size()&&buf;i++){
        x[i]=x[i]+buf;
        buf=x[i]/r;
        x[i]%=r;
        }
    if(buf) x.push_back(buf);
    return x;
}
string C;
vector<big> q;
main(){
    cin>>C;
    big c,ans;
    c.push_back(1);
    q.push_back(c);
    for(int i=0;i<C.length();i++){
        if(C[i]=='P') continue;
        if(C[i]=='*'){
            int n=q.size();
            for(int j=0;j<n;j++){
                q.push_back(q[j]*2+1);
                q.push_back(q[j]*2);
            }
        }
        elif(C[i]=='L')
            for(int j=0;j<q.size();j++)
                q[j]=q[j]*2;
        elif(C[i]=='R')
            for(int j=0;j<q.size();j++)
                q[j]=q[j]*2+1;
    }
    for(int j=0;j<q.size();j++){
        ans=ans+q[j];
    }
    pin(ans);
}

