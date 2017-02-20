#include<stdio.h>
#include<queue>
#define MAX   33
#define MAXL   10001
#define x   first
#define y   second
using namespace std;
typedef pair<int,int> ii;
int a[MAX][MAX];
ii r[MAXL];
ii t[MAXL];
int dx[]={-1,-1,1,1};
int dy[]={-1,1,-1,1};
int n,b,g,p;
void init(void) {
    scanf("%d",&n);
    char s[MAX];
    int i,j;
    p=0;
    g=0;
    for (i=1;i<=n;i=i+1) {
        scanf("%s",s);
        for (j=1;j<=n;j=j+1) {
            if (s[j-1]=='+') a[i][j]=0;
            if (s[j-1]=='-') a[i][j]=-1;
            if (s[j-1]=='o') a[i][j]=1;
            if (s[j-1]=='K') a[i][j]=2;
            g=g+(a[i][j]==1);
            p=p+(a[i][j]==0);
        }
    }
    for (i=0;i<=n+1;i=i+1) {
        a[0][i]=-1;
        a[i][0]=-1;
        a[n+1][i]=-1;
        a[i][n+1]=-1;
    }
    b=3*p;
    t[0]=ii(-1,-1);
}
void update(int k) {
    b=k;
    int i;
    for (i=1;i<=b;i=i+1) r[i]=t[i];
}
void btrk(int k) {
    int i,j,l;
    for (i=0;i<4;i=i+1) {
        for (j=1;j<=n+1;j=j+1)
            if (a[t[k-1].x+j*dx[i]][t[k-1].y+j*dy[i]]!=1) {
                if ((a[t[k-1].x+j*dx[i]][t[k-1].y+j*dy[i]]==0) && (ii(t[k-1].x+j*dx[i],t[k-1].y+j*dy[i])!=t[k-2])) {
                    t[k]=ii(t[k-1].x+j*dx[i],t[k-1].y+j*dy[i]);
                    if (k<b) {
                        for (l=0;l<j;l=l+1)
                            a[t[k-1].x+l*dx[i]][t[k-1].y+l*dy[i]]=0;
                        g=g-j+1;
                        a[t[k-1].x+j*dx[i]][t[k-1].y+j*dy[i]]=2;
                        if (g==0) update(k);
                        else btrk(k+1);
                        for (l=1;l<j;l=l+1)
                            a[t[k-1].x+l*dx[i]][t[k-1].y+l*dy[i]]=1;
                        a[t[k-1].x][t[k-1].y]=2;
                        g=g+j-1;
                        a[t[k-1].x+j*dx[i]][t[k-1].y+j*dy[i]]=0;
                    }
                }
                break;
            }
    }
}
void process(void) {
    int i,j;
    for (i=1;i<=n;i=i+1)
        for (j=1;j<=n;j=j+1)
            if (a[i][j]==2) {
                t[1]=ii(i,j);
                btrk(2);
            }
    if (b==3*p) {
        printf("impossible");
        return;
    }
    for (i=1;i<=b;i=i+1) printf("%d %d\n",r[i].x,r[i].y);
}
int main(void) {
    freopen("chkr.inp","r",stdin);
    freopen("chkr.out","w",stdout);
    init();
    process();
    return 0;
}
