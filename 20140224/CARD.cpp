#include <bits/stdc++.h>
#define elif else if
#define nil &leaf
using namespace std;
struct node{
    node *l,*r;
    int pr,fr,to,s;
    void update();
};
node leaf,*root;
int n;
void node::update(){
    if(this!=nil)
        s=l->s+r->s+to-fr+1;
    }
node* newnode(int fr,int to){
    node *x=new node;
    x->pr=rand();
    x->l=x->r=nil;
    x->fr=fr,x->to=to;
    x->s=to-fr+1;
    return x;
}
void init(){
    leaf.l=leaf.r=nil;
    leaf.pr=-1;
    leaf.s=leaf.fr=leaf.to=0;
    root=newnode(1,n<<1);
}
int find(node* now,int& need,int av){
    if(now==nil||av==now->l->s+now->to-now->fr+1) return 0;
    int tmp;
    if(av<=now->l->s){
        tmp=find(now->l,need,av);
    }
    elif(av>now->l->s+now->to-now->fr+1){
        tmp=find(now->r,need,av-now->l->s-(now->to-now->fr+1));
    }else{
        av-=now->l->s;
        need=now->fr+av;
        tmp=now->to;
        now->to=now->fr+av-1;
    }
    now->update();
    return tmp;
}
void split(node* x,node* &l,node* &r,int av){
    if(x==nil){
        l=nil;
        r=nil;
        return ;
    }
    if(av<=x->l->s){
        r=x;
        split(x->l,l,r->l,av);
    }
    else{
        l=x;
        split(x->r,l->r,r,av-x->l->s-(x->to-x->fr+1));
    }
    l->update();
    r->update();
}
void merge(node* &x,node*l,node*r){
    if(l==nil) x=r;
    elif(r==nil) x=l;
    elif(l->pr>r->pr){
        x=l;
        merge(x->r,l->r,r);
    }
    else{
        x=r;
        merge(x->l,l,r->l);
    }
    x->update();
}
int cnt;
vector<pair<int,pair<int,int> > > d;
void dfs(node* r){
    if(r==nil) return;
    dfs(r->l);
    d.push_back(make_pair(r->fr,make_pair(++cnt,r->to-r->fr+1)));
    dfs(r->r);
    free(r);
}
void bot(int k){
    int tmp;
    int t=find(root,tmp,n+k);
    node*r1,*r2,*r3,*r4,*r;
    r1=r2=r3=r4=r=nil;
    if(t) r=newnode(tmp,t);
    split(root,r1,r2,n+k);
    r3=r2;
    if(t) merge(r2,r,r3);
    t=find(r1,tmp,n-k);
    if(t) r=newnode(tmp,t);
    split(r1,r3,r4,n-k);
    r1=r4;
    if(t) merge(r4,r,r1);
    merge(r1,r3,r2);
    merge(root,r1,r4);
}
void top(int k){
    int tmp;
    int t=find(root,tmp,n-k);
    node *r1,*r2,*r3,*r4,*r;
    r1=r2=r3=r4=r=nil;
    if(t) r=newnode(tmp,t);
    split(root,r1,r2,n-k);
    r3=r2;
    if(t)  merge(r2,r,r3);
    t=find(r2,tmp,k<<1);
   if(t) r=newnode(tmp,t);
    split(r2,r3,r4,k<<1);
    r2=r4;
    if(t) merge(r4,r,r2);
    merge(r2,r1,r4);
    merge(root,r3,r2);
}
int S[300011];
int get(int x){
    int rep=0;
    for(;x>0;x-=(x&(-x))) rep=max(rep,S[x]);
    return rep;
}
void update(int x,int val){
    for(;x<=cnt;x+=(x&(-x))) S[x]=max(S[x],val);
}
int lis(){
    cnt=0,d.clear();
    dfs(root);
    memset(S,0,sizeof S);
    sort(d.begin(),d.end());
    for(int i=0;i<d.size();i++)
        update(d[i].second.first,d[i].second.second+get(d[i].second.first-1));
    return get(cnt);
}
main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    int t,m,x;
    cin>>t;
    for(;t>0;t--){
        cin>>n>>m;
        init();
        for(;m>0;m--){
            cin>>x;
            if(x<0) bot(abs(x));
            else top(x);
//            dfs(root);
        }
        printf("%d\n",(n<<1)-lis());
    }
}
