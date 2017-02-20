#include <iostream>
#include <cstdio>
#include <map>
#include <climits>
#include <utility>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
long long int a[24];
long long int P,k;

struct matrix{
    vector<vector<long long int> > v;
    long long int n,m;
    void set(long long int _n,long long int _m){
        n=_n;
        m=_m;
        v=vector<vector<long long int> > (n,vector<long long int> (m));
    }
    void get(long long int _n,long long int _m){
        for(long long int i=0;i<_n;i++)
            for(long long int j=0;j<_m;j++)
                scanf("%lld",&v[i][j]);
    }
    void show(){
        for(long long int i=0;i<n;i++){
            for(long long int j=0;j<m;j++)
                cout<<v[i][j]<<" ";
            putchar('\n');
        }
    }
    vector<long long int> &operator [] (long long int i) { return v[i]; }
    matrix operator* (matrix b) {
        matrix c;
        long long int p=b.m;
        c.set(n,p);
    for (long long int i = 0; i < n; ++i)
        for (long long int j = 0; j < p; ++j)
            for (long long int k = 0; k < m; ++k){
                c[i][j]= c[i][j]%P + (v[i][k]*b[k][j])%P;
                c[i][j]=c[i][j]%P;
            }

    return c;
    }
};
matrix operator^ (matrix A,long long int x){
        if(x==1) return A;
        matrix s=A^(x/2);
        if(x%2==0){
            return s*s;
        }
        else return s*s*A;
}
main(){
    matrix a,b;
    a.set(1,24);
    b.set(24,24);
    char a1[20],a2[20];
    scanf("%s%s",a1,a2);
    scanf("%lld%lld",&k,&P);
    a[0][3*(a1[0]-'A')]=1;
    a[0][3*(a1[0]-'A')+1]=1;
    a[0][3*(a1[0]-'A')+2]=1;
    b[0][4]=1;    b[0][5]=1;
    b[1][10]=1;   b[1][11]=1;
    b[2][13]=1;   b[2][14]=1;
    b[3][1]=1;    b[3][2]=1;
    b[4][7]=1;    b[4][8]=1;
    b[5][16]=1;   b[5][17]=1;
    b[6][3]=1;    b[6][5]=1;
    b[7][11]=1;   b[7][9]=1;
    b[8][19]=1;   b[8][20]=1;
    b[9][0]=1;    b[9][2]=1;
    b[10][6]=1;   b[10][8]=1;
    b[11][22]=1;  b[11][23]=1;
    b[12][0]=1;   b[12][1]=1;
    b[13][15]=1;  b[13][17]=1;
    b[14][21]=1;  b[14][23]=1;
    b[15][3]=1;   b[15][4]=1;
    b[16][12]=1;  b[16][14]=1;
    b[17][18]=1;  b[17][20]=1;
    b[18][6]=1;   b[18][7]=1;
    b[19][15]=1;  b[19][16]=1;
    b[20][21]=1;  b[20][22]=1;
    b[21][9]=1;   b[21][10]=1;
    b[22][12]=1;  b[22][13]=1;
    b[23][18]=1;  b[23][19]=1;
 //   b.show();
   if(k>1){
    b=(b^(k-1));
    a=a*b;
    }
   // a.show();
    long long int res=0;
    switch(a2[0]){
        case 'A':
            res=(a[0][3]+a[0][9]+a[0][12])%P;
            break;
        case 'B':
            res=(a[0][0]+a[0][6]+a[0][15])%P;
            break;
        case 'C':
            res=(a[0][4]+a[0][10]+a[0][18])%P;
            break;
        case 'D':
            res=(a[0][1]+a[0][7]+a[0][21])%P;
            break;
        case 'E':
            res=(a[0][22]+a[0][16]+a[0][2])%P;
            break;
        case 'F':
            res=(a[0][5]+a[0][13]+a[0][19])%P;
            break;
        case 'G':
            res=(a[0][23]+a[0][8]+a[0][17])%P;
            break;
        case 'H':
            res=(a[0][14]+a[0][11]+a[0][20])%P;
            break;

    }
    cout<<res;
}
