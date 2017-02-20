#include<stdio.h>
#define MAX   11111
int f[MAX];
int n;
void init(void) {
    scanf("%d",&n);
    int i,x,y;
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&x);
        scanf("%d",&y);
        f[y]=x;
    }
}
void process(void) {
    int x,y,t,i,j;
    bool p;
    while (true) {
        scanf("%d",&x);
        scanf("%d",&y);
        if ((x==0) && (y==0)) return;
        p=false;
        t=f[x];
        i=1;
        if (t==y) {
            p=true;
            j=1;
        }
        while (true) {
            if (t==x) {
                if (!p) printf("No\n");
                else printf("Yes %d\n",i-j-1);
                break;
            }
            if (i>n) {
                printf("No\n");
                break;
            }
            t=f[t];
            i=i+1;
            if (t==y) {
                p=true;
                j=i;
            }
        }
    }
}
int main(void) {
    freopen("1.inp","r",stdin);
    freopen("1.out","w",stdout);
    init();
    process();
}
