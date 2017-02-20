#include <bits/stdc++.h>
/*
7
5
4
3
7
1
2
6
*/
using namespace std;
const int Maxn=100011;
int a[Maxn];
int S[Maxn];
void update(int s){
   while(s<Maxn){
     S[s]++;
    s+=s&(-s);
   }
}
int get(int s){
    int rep=0;
    while(s>0){
        rep+=S[s];
        s-=s&(-s);
    }
    return rep;
}
main(){
    ios_base::sync_with_stdio(false);
    int n,x,ans;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        a[x]=i;
    }
    int cnt1=1,j;
    int cnt2=n;
    for(int i=1;i<=n;i++){
    if(i&1){
        j=cnt1++;
        ans=a[j]-get(a[j]-1)-1;
    }
    else{
        j=cnt2--;
        ans=(n-a[j])-(i-1-get(a[j]));
    }
    update(a[j]);
    printf("%d\n",ans);
    }

}
