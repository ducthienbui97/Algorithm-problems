    #include<cstdio>
    #include<vector>
    #include<queue>
    #define MAX 100100
    #define f first
    #define s second
    using namespace std;
    typedef pair<int,int> ii;
    struct row {
    int p,mx,mn;
    row(){}
    row(const int &_p,const int &_mx,const int &_mn) {
    p=_p;mx=_mx;mn=_mn;
    }
    };
    vector<ii> g[MAX];
    int c[MAX];
    int l[MAX];
    row p[MAX][21];
    int n,k;
    void loadgraph(void) {
    scanf("%d",&n);
    int i,j,u,v,w;
    for (i=1;i<=n;i=i+1) {
    c[i]=0;
    l[i]=0;
    g[i].clear();
    for (j=0;j<=19;j=j+1) p[i][j]=row(0,0,0);
    }
    l[0]=-1;
    for (i=1;i<n;i=i+1) {
    scanf("%d",&u);
    scanf("%d",&v);
    scanf("%d",&w);
    g[u].push_back(ii(v,w));
    g[v].push_back(ii(u,w));
    }
    }
    void BFS(void) {
    queue<int> q;
    while (!q.empty()) q.pop();
    c[1]=1;
    l[1]=0;
    q.push(1);
    int i,u;
    while (!q.empty()) {
    u=q.front();q.pop();
    for (i=0;i<g[u].size();i=i+1)
    if (c[g[u][i].f]==0) {
    c[g[u][i].f]=1;
    l[g[u][i].f]=l[u]+1;
    p[g[u][i].f][0]=row(u,g[u][i].s,g[u][i].s);
    q.push(g[u][i].f);
    }
    }
    }
    int max(const int &x,const int &y) {
    if (x>y) return (x); else return (y);
    }
    int min(const int &x,const int &y) {
    if (x<y) return (x); else return (y);
    }
    void process(void) {
    int i,j;
    BFS();
    for (j=1;j<=19;j=j+1)
    for (i=1;i<=n;i=i+1)
    p[i][j]=row(p[p[i][j-1].p][j-1].p,max(p[i][j-1].mx,p[p[i][j-1].p][j-1].mx),min(p[i][j-1].mn,p[p[i][j-1].p][j-1].mn));
    }
    row lca(int u,int v) {
    if (l[u]<l[v]) return (lca(v,u));
    int i,mx,mn;
    mx=-1e7;mn=1e7;
    for (i=19;i>=0;i=i-1)
    if (l[p[u][i].p]>=l[v]) {
    mx=max(mx,p[u][i].mx);
    mn=min(mn,p[u][i].mn);
    u=p[u][i].p;
    }
    if (u==v) return (row(u,mx,mn));
    for (i=19;i>=0;i=i-1)
    if (p[u][i].p!=p[v][i].p) {
    mx=max(mx,max(p[u][i].mx,p[v][i].mx));
    mn=min(mn,min(p[u][i].mn,p[v][i].mn));
    u=p[u][i].p;
    v=p[v][i].p;
    }
    return (row(p[u][0].p,max(mx,max(p[u][0].mx,p[v][0].mx)),min(mn,min(p[u][0].mn,p[v][0].mn))));
    }
    void answer(void) {
    int i,a,b;
    row p;
    scanf("%d",&k);
    for (i=1;i<=k;i=i+1) {
    scanf("%d",&a);
    scanf("%d",&b);
    p=lca(a,b);
    printf("%d %d\n",p.mn,p.mx);
    }
    }
    int main(void) {
        freopen("traffic.inp","r",stdin);
        freopen("traffic.out","w",stdout);
    loadgraph();
    process();
    answer();
    return 0;
    }
