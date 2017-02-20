#include <cstdio>
#include <queue>
#define MAX 20000
#define fi "badgras.inp"
#define fo "badgras2.out"
using namespace std;
queue<pair<int, int> > q;
int M, N, s, a[MAX][MAX], c=0, l[]={0, 0, -1, 1, -1, -1, 1, 1}, r[]={-1, 1, -1, 1, -1, 0, 0, 1};
bool ch[MAX][MAX];
void enter()
{
    scanf ("%d%d", &M, &N);
    for (int i=1; i<=M; i++)
    {
        for (int j=1; j<=N; j++)
        {
            scanf ("%d", &a[i][j]);
            if (a[i][j]!=0)
            {
                a[i][j]=1;
                s++;
            }
        }
    }
}

void bfs(int x, int y)
{
    q.push(pair<int, int>(x, y));
    ch[x][y]=true;
//    for (int i=1; i<=7; i++)
//    {
//        if (a[l[i]+x][r[i]+y]==1&&ch[l[i]+x][r[i]+y]==false)
//            bfs(l[i]+x, r[i]+y);
//    }
    while(q.empty()==false)
    {
        pair<int, int> v=q.front();
        q.pop();
        int z=v.first, t=v.second;
        printf ("(%d %d)", z, t);
        for (int i=0; i<=7; i++)
        {
            if (a[l[i]+z][r[i]+t]==1&&ch[l[i]+z][r[i]+t]==false)
            {
                q.push(pair<int, int>(l[i]+z, r[i]+t));
                ch[l[i]+z][r[i]+t]=true;
            }
        }
    }
}
void init()
{
    for (int i=1; i<=M; i++)
        for (int j=1; j<=N; j++)
        {
            if (a[i][j]==1 && ch[i][j]==false)
            {
                c++;
                bfs(i, j);
            }
        }
}

void exit()
{
    printf ("%d %d", c, s);
}

int main()
{
    freopen (fi, "r", stdin);
    freopen (fo, "w", stdout);
    enter();
    init();
    exit();
}
