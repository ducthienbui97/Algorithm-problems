#include<stdio.h>
int h[1111111],n,d=0;
int l,c1,c2;
int br(int a)
{
    int m1=0,m2=0;
    if (l+a>n) return 0;
    for (int i=a;i<=l+a;i++)
        if (h[i]>m1) {m1=h[i];c1=i;}
        else if (h[i]>=m2) {m2=h[i];c2=i;}
    if ((m1==m2) && (c1==a) && (c2==a+l)) {d++;}
        br(a+1);
}

int main()
{
    scanf("%d%d",&l,&n);
    if (l>=n) {
    printf("%d",d);
    return 0;
    }
    for (int i=1;i<=n;i++) scanf("%d",&h[i]);
    br(1);
    printf("%d\n",d);
}
