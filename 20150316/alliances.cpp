#include<stdio.h>
#include<string.h>
#include<vector>
#define M 10000
#include<queue>
#define NMAX 72
#define NM 4920
using namespace std;
int r,c;
struct edge{
    int from,to,flow,capa;
    edge(){
        from = 0 ; to = 0 ; flow = 0 ; capa = 0;
    }
    edge(int _from,int _to,int _flow,int _capa){
        from = _from ; to = _to ; flow = _flow ; capa = _capa;
    }
    void show(){
        printf("(%d -> %d) : (%d / %d)\n",from,to,flow,capa);
    }
};
int nvertices;
int INF = 1e9;
int W[NMAX][NMAX];
char ans[4*NMAX][4*NMAX];
int deg[3];
struct maxflow{
    vector<edge> E;
    vector<int> V[M + 20];
    int d[M + 20];
    int ptr[M + 20];
    void add_edge(int from,int to,int flow,int capa){
         V[from].push_back(E.size()) ; E.push_back(edge(from,to,0,capa)) ;
         V[to].push_back(E.size()) ; E.push_back(edge(to,from,0,0));
    }
    bool bfs(int source,int sink){
        queue<int> qq;
        for(int i = 0 ; i <= nvertices ; i++)   d[i] = -1;
        d[source] = 0;
        qq.push(source);
        while(!qq.empty()){
            int u = qq.front();
            qq.pop();
            for(int i = 0 ; i < V[u].size() ; i++){
                int id = V[u][i];
                if(d[E[id].to] == -1 && E[id].capa > E[id].flow){
                    d[E[id].to] = d[u] + 1;
                    qq.push(E[id].to);
                }
            }
        }
        return (d[sink] != -1);
    }
    int dfs(int u,int flow,int sink){
        if(u == sink) return flow;
        for(;ptr[u] < V[u].size() ; ptr[u]++){
            int id = V[u][ptr[u]];
            if(d[E[id].to] == d[u] + 1 && E[id].capa > E[id].flow){
                int pushed = dfs(E[id].to , min(flow , E[id].capa - E[id].flow) , sink);
                if(pushed != 0){
                    E[id].flow+=pushed;
                    E[id^1].flow-=pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    int get_flow(int source,int sink){
        int tot = 0;
        while(bfs(source,sink)){
            //printf("xxyyzz\n");
            memset(ptr , 0 , sizeof ptr);
            while(1){
                int add = dfs(source , INF , sink);
                tot+=add;
                if(add == 0) break;
            }
        }
        return tot;
    }
};
vector<int> alliance[NM];
int label[M];
int dx[] = {0 ,  0 , 1 , -1};
int dy[] = {1 , -1 , 0 ,  0};
maxflow MF;
bool inside(int x,int y){
    return ( x >= 0 && x < r && y >= 0 && y < c);
}
void build_network(){
    scanf("%d %d",&r,&c);
    nvertices = r*c + 1;
    int source = r*c;
    int sink = r*c + 1;
    for(int i = 0 ; i < r ; i++)
        for(int j = 0 ; j < c ; j++){
            scanf("%d",&W[i][j]);
            deg[(i + j)%2]+=W[i][j];
            if(W[i][j] == 2){
                nvertices++;
                label[nvertices] = i*c + j;
                label[i*c + j] = nvertices;
            }
            else label[i*c + j] = i*c + j;
        }
    for(int i = 0 ; i < r ; i++)
        for(int j = 0 ; j < c ; j++){
            int curr = i*c + j;
            if(W[i][j] == 2){
                if( (i + j)%2 == 0){
                    MF.add_edge(source , curr , 0 , 1);
                    MF.add_edge(source , label[curr] , 0 , 1);
                }
                else{
                    MF.add_edge(curr , sink , 0 , 1);
                    MF.add_edge(label[curr] , sink , 0 , 1);
                }
                if((i + j)%2 == 0){
                    for(int k = 0 ; k < 4 ; k++){
                        int x = i + dx[k] ; int y = j + dy[k]; if(!inside(x,y))    continue;
                        int pos = x*c + y;
                        if( k <= 1 ) MF.add_edge(curr , pos , 0 , 1);
                        else MF.add_edge(label[curr] , label[pos] , 0 , 1);
                    }
                }
            }
            else{
                if((i + j)%2 == 0) MF.add_edge(source ,  curr , 0 , W[i][j]);
                else MF.add_edge(curr , sink , 0 , W[i][j]);
                if( (i + j)%2 == 0){
                    for(int k = 0 ; k < 4 ; k++){
                        int x = i + dx[k] ; int y = j + dy[k]; if(!inside(x,y))    continue;
                        int pos = x*c + y;
                        if( k <= 1 ) MF.add_edge(curr , pos , 0 , 1);
                        else MF.add_edge(curr , label[pos] , 0 , 1);
                    }
                }
            }
        }
    int res = MF.get_flow(source,sink);
    if(res != max(deg[0] , deg[1])){
        printf("Impossible!");
        return ;

    }
    for(int i = 0 ; i < MF.E.size() ; i+=2){
        int from = MF.E[i].from ; int to = MF.E[i].to ; int capa = MF.E[i].capa ; int flow = MF.E[i].flow;
        if( from == source || to == sink )  continue;
        if( flow == 0 ) continue;
        int u = from;
        int v = to;
        if( u >= r*c ) u = label[u];
        if( v >= r*c ) v = label[v];
        alliance[u].push_back(v);
        alliance[v].push_back(u);

    }

    for(int i = 0 ; i < 3*r ; i++)
        for(int j = 0 ; j < 3*c ; j++) ans[i][j] ='.';
    for(int i = 0 ; i < r ; i++)
        for(int j = 0 ; j < c ; j++){
            if(W[i][j] == 0) continue;
            ans[i*3 + 1][j*3 + 1] = 'O';
            for(int k = 0 ; k < alliance[i*c + j].size() ; k++){
                int x = alliance[i*c + j][k]/c;
                int y = alliance[i*c + j][k]%c;
                ans[i*3 + 1 - (i - x)][j*3 + 1 - (j - y)] = 'X';
            }
        }
    for(int i = 0 ; i < r*3 ; i++)   puts(ans[i]);
}
main(){
    //freopen("test.inp","r",stdin);
    build_network();

}
