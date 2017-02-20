#include<bits/stdc++.h>
using namespace std;
const int N=102;
int n,m;
int d[N][N];
int main()
{
    //freopen("fr.cpp","r",stdin);
    int test;
    cin>>test;
    while(test--){
        int p,q;
        for(int i=1;i<=100;++i)
            for(int j=1;j<=100;++j)   d[i][j]=1e9;
        for(int i=1;i<=100;++i)  d[i][i]=0;

        n=0;
        while(cin>>p>>q && p!=0){
            n=max(n,max(p,q));
            d[p][q]=1;
        }
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        double res=0.0;

        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)  res+=1.0*d[i][j];
        printf("%.3lf\n",1.0*res/n/(n-1));

    }

}
