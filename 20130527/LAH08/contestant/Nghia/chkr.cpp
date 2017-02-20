#include <cstdio>
#include <complex>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#define X real()
#define Y imag()
using namespace std;
typedef complex<int> point;
int dx[]={2,2,-2,-2};
int dy[]={2,-2,-2,2};
int n;
char A[35][35];
int perm[35][35];
int test;
void back(point k,int no)
{
    if(test==5) return;
    if(no==0)  {test=5;printf("YES");return;}
    else
    for(int i=0;i<4;i++)
    {
        int x=k.X+dx[i],y=k.Y+dy[i];
        if(x>=1&&x<=n&&y>=1&&y<=n)
        {
            point tmp=(x,y);
            if(A[x][y]=='o')
            {
                //perm[x][y]=1;
                A[x][y]='+';
                back(tmp,no-1);
                A[x][y]='o';
                //perm[x][y]=0;
            }
            else if(A[x][y]=='+')
            {
                back(tmp,no);
            }
        }
    }
}
char ss[35];
main()
{
    freopen("chkr.inp","r",stdin);
    freopen("chkr.out","w",stdout);
    point K[35];
    int lk=0,o=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",ss);
        for(int j=0;j<n;j++)
        {
            A[i][j+1]=ss[j];
            if(ss[j]=='K')
            {
                lk++;
                K[lk]=(i,j+1);
            }
            if(ss[j]=='o') o++;
        }
    }
    for(int i=1;i<=lk;i++)
    {
        int oo=o;
        back(K[i],oo);
        if(test==5) break;
    }
    if(test!=5) printf("impossible");
}
/*
8
-+-+-+-+
+-+-+-+-
-+-K-+-+
+-+-+-+-
-o-o-+-+
+-K-+-+-
-o-+-+-+
+-K-+-K-
*/
