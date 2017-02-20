#include <bits/stdc++.h>
#define elif else if
#define nil &leaf
using namespace std;
struct node {
    node *l,*r;
    pair<int,int> val;
    int inc,sz,mul,pr;
    long long sumval,summul;
    void update();
    void recal();
    };
node* root,leaf;
node* newnode(pair<int,int> val,int mul) {
    node* x=new node;
    x->pr=rand();
    x->val=val;
    x->sumval=val.first;
    x->sz=1;
    x->mul=mul;
    x->summul=1ll*mul*val.first;
    x->l=x->r=nil;
    x->inc=0;
    return x;
    }
void init() {
    leaf.inc=leaf.sz=leaf.mul=leaf.sumval=leaf.summul=0;
    leaf.val=make_pair(0,0);
    leaf.pr=-1;
    leaf.l=leaf.r=nil;
    root=nil;
    }
void node::recal() {
    if(this==nil) return ;
    if(inc) {
        if(l!=nil) l->inc+=inc;
        if(r!=nil) r->inc+=inc;
        mul+=inc;
        summul+=sumval*inc;
        inc=0;
        }
    }
void node::update() {
    if(this==nil) return;
    l->recal();
    r->recal();
    sz=l->sz+r->sz+1;
    sumval=l->sumval+r->sumval+val.first;
    summul=l->summul+r->summul+1ll*val.first*mul;
    }
node* insert(node* now,pair<int,int> val,int mul) {
    now->recal();
    if(now==nil)
        return newnode(val,mul);
    if(val>now->val) {
        if(now->l!=nil) now->l->inc++;
        now->mul++;
        node* x=now->r=insert(now->r,val,mul);
        if(x->pr>now->pr) {
            swap(x,now);
            x->r=now->l;
            now->l=x;
            x->update();
            }
        }
    else {
        node* x=now->l=insert(now->l,val,mul+1+now->r->sz);
        if(x->pr>now->pr) {
            swap(x,now);
            x->l=now->r;
            now->r=x;
            x->update();
            }
        }
    now->update();
    return now;
    }
node* del(node* x) {
    node* now;
    if(x->l==nil) return x->r;
    elif(x->r==nil) return x->l;
    else {
        x->l->recal();
        x->r->recal();
        if(x->l->pr>x->r->pr) {
            now=x->l;
            x->l=now->r;
            now->r=del(x);
            }
        else {
            now=x->r;
            x->r=now->l;
            now->l=del(x);
            }
        }
    now->update();
    return now;
    }
node* erase(node* now,pair<int,int> val) {
    now->recal();
    if(val>now->val) {
        now->mul--;
        if(now->l!=nil) now->l->inc--;
        now->r=erase(now->r,val);
        }
    elif(val<now->val) now->l=erase(now->l,val);
    else {
        if(now->l!=nil) now->l->inc--;
        return del(now);
        }
    now->update();
    return now;
    }
int n,c;
long long sumL;
int l[200022],t[200022];
void dfs(node* x) {
    if(x==nil) return ;
    dfs(x->l);
    cout<<x->val.first<<" "<<x->summul<<endl;
    dfs(x->r);
    }
int L,T,x;
main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    init();
    cin>>n>>c;
    for(int i=1; i<=n; i++) {
        cin>>l[i]>>t[i];
        root=insert(root,make_pair(t[i],i),1);
        sumL+=l[i];
        }
    printf("%lld\n",sumL-root->summul);
    while(c--) {
        cin>>x>>L>>T;
        root=erase(root,make_pair(t[x],x));
        sumL-=l[x];
        root=insert(root,make_pair(T,x),1);
        sumL+=L;
        l[x]=L;
        t[x]=T;

        printf("%lld\n",sumL-root->summul);

        }
    }
