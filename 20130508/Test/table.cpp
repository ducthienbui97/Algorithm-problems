#include<iostream>
using namespace std;
int N,M,R;
long long a[2][3000],l[3000],r[3000];

void input(){
    cin>>N>>M>>R;
    l[0]=0;
    l[M+1]=0;
    r[0]=0;
    r[M+1]=0;
    
    for(int i=1;i<=M;i++) {
        cin>>a[0][i];
        l[i]=a[0][i];
        r[i]=a[0][i];
    }
}
void process(){
    for(int i=1;i<N;i++){
        for(int j=1;j<=M;j++) {
            a[i%2][j]=(l[j-1]+r[j+1]+a[(i-1)%2][j]+a[(i-1)%2][j]*(i!=1))%R;
            if (i==N-1) cout<<a[i%2][j]<<" ";       
        }
        if (i==N-1) return;
        for(int j=1;j<=M;j++) r[j]=(r[j+1]+a[i%2][j])%R;
        for(int j=M;j>=1;j--) l[j]=(l[j-1]+a[i%2][j])%R;
    }
}
int main(){
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    input();
    process();
}
