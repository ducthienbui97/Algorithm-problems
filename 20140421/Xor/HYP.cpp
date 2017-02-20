#include <bits/stdc++.h>
#define mp make_pair
#define elif else if
using namespace std;
vector<int> h,c;
const int Max=2222;
int a[Max][Max],b[Max][Max];
int n;
bool rev(int t,int _b,int l,int r){
    printf("%d %d %d %d\n",l,r-1,t,_b-1);
    b[t][l]^=1;
    b[_b][l]^=1;
    b[t][r]^=1;
    b[_b][r]^=1;
}
main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>a[i][j];
    for(int i=1;i<=n+1;i++)
    for(int j=1;j<=n+1;j++){
        b[i][j]=a[i-1][j-1]^a[i-1][j]^a[i][j-1]^a[i][j];
    }
    int cnt=0;
    for(int i=1;i<=n+1;i++)
    for(int j=1;j<=n+1;j++)
    if(b[i][j]){
        h.clear();
        c.clear();
        for(int ii=i+1;ii<=n+1;ii++)
        if(b[ii][j]) h.push_back(ii);
        for(int jj=j+1;jj<=n+1;jj++)
        if(b[i][jj]) c.push_back(jj);
        bool ok=false;
        for(int ii=0;!ok&&ii<h.size();ii++)
        for(int jj=0;!ok&&jj<c.size();jj++)
        if(b[h[ii]][c[jj]]){
            ++cnt;
            ok=true;
            rev(i,h[ii],j,c[jj]);
        }
        if(!ok){
            ++cnt;
            rev(i,h[rand()%h.size()],j,c[rand()%c.size()]);
        }
    }
    printf("%d\n",cnt);
}
