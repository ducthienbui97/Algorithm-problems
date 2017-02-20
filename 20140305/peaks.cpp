#include <bits/stdc++.h>
#define elif else if
#define id second
#define h first
#define nil &leaf
using namespace std;
struct node{
    int pr,sz;
    pair<int,int> val;
    node *l,*r;
    void update();
};
struct query{
    int type,a,b,c;
    bool operator<(const query& X)const{
        if(c==X.c) return type<X.type;
        return c<X.c;
    }
};
const int Maxn=1e5+20;
const int Maxv=5e5+20;
int root[Maxn];
int n,m,quest;
node* R[Maxn];
vector<pair<int,int> > mouns;
node leaf;
vector<query> q;
node* newnode(pair<int,int> val){
    node* x=new node;
    x->l=x->r=nil;
    x->pr=rand();
    x->val=val;
    x->sz=1;
    return x;
}
void node::update(){
    if(this!=nil)
        sz=l->sz+r->sz+1;
}
void init(){
    leaf.pr=-1;
    leaf.sz=0;
    leaf.val=make_pair(0,0);
    leaf.l=leaf.r=nil;
    cin>>n>>m>>quest;
    mouns.resize(n);
    for(int i=0;i<n;i++){
        cin>>mouns[i].h;
        mouns[i].id=i;
        root[i]=-1;
        R[i]=newnode(mouns[i]);
    }
    q.resize(m+quest);
    for(int i=0;i<m;i++){
        q[i].type=0;
        cin>>q[i].a>>q[i].b>>q[i].c;
        q[i].a--;
        q[i].b--;
    }
    for(int i=m;i<m+quest;i++){
        q[i].type=i;
        cin>>q[i].a>>q[i].c>>q[i].b;
        q[i].a--;
    }
    sort(q.begin(),q.end());
}
node* insert(node* x,pair<int,int> val){
    if(x==nil) return newnode(val);
                //cerr<<x->val.first<<"->"<<val.first<<endl;

    if(x->val>val){
        x->l=insert(x->l,val);
        if(x->l->pr>x->pr){
            node* now=x->l;
            swap(x,now);
            now->l=x->r;
            x->r=now;
            now->update();
        }
    }else{
        x->r=insert(x->r,val);
        if(x->r->pr>x->pr){
            node* now=x->r;
            swap(now,x);
            now->r=x->l;
            x->l=now;
            now->update();
        }
    }
    x->update();
    return x;
}
int findroot(int x){
    if(root[x]<0) return x;
    return root[x]=findroot(root[x]);
}
void dfs(node *x,node* &r){
    if(x==nil) return;
    dfs(x->l,r);
    dfs(x->r,r);
    //cerr<<x->val.first<<endl;
    r=insert(r,x->val);
    delete x;
}

int find(node* now,int k){
    //cerr<<now->val.first<<" "<<k<<" "<<now->l->sz<<" "<<now->r->sz<<endl;
    if(now==nil) return -1;
    if(k<=now->r->sz) return find(now->r,k);
    if(k==now->r->sz+1) return now->val.first;
    return find(now->l,k-now->r->sz-1);
}
void unique(int x,int y){
    int xx=findroot(x);
    int yy=findroot(y);
    if(xx==yy) return;
    if(abs(root[xx])<abs(root[yy])) swap(xx,yy);
    //cerr<<xx<<"~~~"<<yy<<endl;
    dfs(R[yy],R[xx]);
    root[xx]+=root[yy];
    root[yy]=xx;
    //cerr<<endl;
}
vector<int> ans;
main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    init();
    ans.resize(quest);
    for(int i=0;i<q.size();i++){
        if(q[i].type){
            //cerr<<"X"<<endl;
            ans[q[i].type-m]=find(R[findroot(q[i].a)],q[i].b);
            //cerr<<"Y"<<endl;
        }else{
            //cerr<<q[i].a<<" "<<q[i].b<<"--\n";
            unique(q[i].a,q[i].b);
        }
    }
    for(int i=0;i<ans.size();i++)
        printf("%d\n",ans[i]);
}
/*
10 11 4
1 2 3 4 5 6 7 8 9 10
1 4 4
2 5 3
9 8 2
7 8 10
7 1 4
6 7 1
6 4 8
2 1 5
10 8 10
3 4 7
3 4 6
1 5 2
1 5 6
1 5 8
8 9 2
*/
