#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
const int Max=1e5+30;
int p[Max];
set<int> ms[Max<<3];
void Hash(vector<int>& h,string & s){
    int hh=0;
    h.clear();

    for(int i=0;i<s.size();i++){
        hh=hh*31+s[i]-'a'+1;
        h.push_back(hh);
    }
}
string S,s;
vector<int> H,h;
vector<int> id;
int get(int l,int r,const vector<int>& h){
    return (h[r]-((l)?(h[l-1]*p[r-l+1]):0));
}
bool cmp(int x,const string&s1,const vector<int>&h1,int y,const string& s2,const vector<int>& h2){
    if(s1[x]!=s2[y]){
        return s1[x]<s2[y];
    }
    int l=0;
    int rep;
    int r=min(s1.size()-x-1,s2.size()-y-1);
    while(l<=r){
        int mid=(l+r)>>1;
        if(get(x,x+mid,h1)==get(y,y+mid,h2)) rep=mid,l=mid+1;
        else r=mid-1;
    }
    if(x+rep==s1.size()-1||y+rep==s2.size()-1){
        return s1.size()-x<s2.size()-y;
    }
    return s1[x+rep+1]<s2[y+rep+1];
}
bool cmp1(int x,int y){
    return cmp(x,S,H,y,S,H);
}
void init(int node,int l,int r){
    if(l==r){
        ms[node].insert(id[l]);
        return;
    }
    init(node<<1,(l),(l+r)>>1);
    init((node<<1)+1,((l+r)>>1)+1,r);
    for(set<int> :: iterator it=ms[node<<1].begin();it!=ms[node<<1].end();it++)
        ms[node].insert(*it);
    for(set<int> :: iterator it=ms[(node<<1)+1].begin();it!=ms[(node<<1)+1].end();it++)
        ms[node].insert(*it);
}
int find(int node,int l,int r,int u,int v,int ll){
    if(u>r||l>v||u>v||l>r) return 1<<30;
    if(u<=l&&r<=v){
        set<int> :: iterator it=ms[node].lower_bound(ll);
        return it!=ms[node].end()?(*it):(1<<30);
    }
    return min(find(node<<1,l,(l+r)>>1,u,v,ll),find((node<<1)+1,((l+r)>>1)+1,r,u,v,ll));
}
bool doit(){
    int ll,rr;
    cin>>ll>>rr>>s;
    --ll;
    --rr;
    Hash(h,s);
    int l=0;
    int rep=-1;
    int r=id.size()-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(cmp(id[mid],S,H,0,s,h)){
            rep=mid;
            l=mid+1;
        }else r=mid-1;
    }
    l=1,r=id.size()-1-rep;
    int r1=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(id.size()-id[rep+mid]>=s.size()&&get(id[rep+mid],id[rep+mid]+s.size()-1,H)==get(0,s.size()-1,h)) r1=mid,l=mid+1;
        else r=mid-1;
    }
    int tmp=find(1,0,id.size()-1,rep+1,rep+r1,ll);
    return tmp+s.size()-1<=rr;
}
main() {
    ios_base::sync_with_stdio(false);
    cin>>S;
    Hash(H,S);
    p[0]=1;
    for(int i=0;i<S.size();i++) id.push_back(i);
    for(int i=1;i<Max;i++)
        p[i]=p[i-1]*31;
    sort(id.begin(),id.end(),cmp1);
    int q;
    init(1,0,id.size()-1);
    for(cin>>q;q--;){
        putchar(doit()?'+':'-');
    }
}
/*
frommarsiam
3 6 10 i
2 11 am
1 9 human
*/
