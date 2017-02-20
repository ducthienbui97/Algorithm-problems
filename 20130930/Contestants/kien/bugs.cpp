#include <stdio.h>
#include <map>
using namespace std;

typedef pair<int, int> ii;

int m, n;
int a[300][15]; //
map<ii, int> F[151][11][1024]; //

bool maximize(int &a, int b){ if (a<b) a=b; return false; return true; }

int hash(int a[], int n){
    int i, r=0;
    for (i=1; i<=n; i++)
    r=r*2+a[i];
    return r;
}

int back(int x, int y){
    int r=0;
    int one = hash(a[x], n);
    int two = hash(a[x+1], n);
    int three = hash(a[x+2], n);

    if (x>m) return 0;
    if (y>n) return back(x+1, 1);
    if (F[x][y][one].count(ii(two, three))) return F[x][y][one][ii(two, three)];

    if (!a[x][y] && !a[x+1][y] && !a[x][y+1] && !a[x+1][y+1]){
        a[x][y]=a[x+1][y]=a[x][y+1]=a[x+1][y+1]=true;
        if (!a[x][y+2] && !a[x+1][y+2]) {
            a[x][y+2]=a[x+1][y+2]=true;
            maximize(r, back(x, y+1)+1);
            a[x][y+2]=a[x+1][y+2]=false;
        }
        if (!a[x+2][y] && !a[x+2][y+1]) {
            a[x+2][y]=a[x+2][y+1]=true;
            maximize(r, back(x, y+1)+1);
            a[x+2][y]=a[x+2][y+1]=false;
        }
        a[x][y]=a[x+1][y]=a[x][y+1]=a[x+1][y+1]=false;
    }
    maximize(r, back(x, y+1));
    //printf("back(%d, %d) = %d\n", x, y, r);
    F[x][y][one][ii(two, three)] = r;
    return r;
}

main(){
	freopen("bugs.inp", "r", stdin);
	freopen("bugs.out", "w", stdout);

    int i, j, p, q, k, t;
    scanf("%d", &t);
while (t--){
    scanf("%d%d%d", &m, &n, &k);
    for (i=1; i<=m; i++)
    for (j=1; j<=n; j++){
        for (int k=0; k<(1<<n); k++)
        F[i][j][k].clear();
        a[i][j]=false;
    }

    for (i=1; i<=m; i++)
    a[i][0]=a[i][n+1]=true;
    for (i=1; i<=n; i++)
    a[0][i]=a[m+1][i]=true;

    for (i=1; i<=k; i++){
        scanf("%d%d", &p, &q);
        a[p][q]=true;
    }
    printf("%d\n", back(1, 1));
}
}

