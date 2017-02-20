#include <bits/stdc++.h>
using namespace std;
bool F[5555][555];
bool ans[5555];
int a[5555];

main(){
    F[0][0]=true;
    int t,n;
    int M=0;
    ios_base::sync_with_stdio(false);
    cin>>t>>n;
    for(int i=1;i<=n;i++){
        F[0][i]=true;
        cin>>a[i];
        for(int j=t;j>=0;j--){
            F[j][i]=F[j][i-1];
            if(j>=a[i]&&F[j-a[i]][i-1]) F[j][i]=true;
            if(F[j][i]) M=max(M,j);
        }
    }
    for(int i=n;i>0&&M;i--){
        if(F[M][i]&&F[M-a[i]][i-1]){
            M-=a[i];
            ans[i]=true;
        }
    }
    int cnt1=0;
    int cnt2=0;
    for(int i=1;i<=n;i++)
    if(ans[i]){
        printf("%d ",cnt1);
        cnt1+=a[i];
    }
    else {
        printf("%d ",cnt2);
        cnt2+=a[i];
    }

}
