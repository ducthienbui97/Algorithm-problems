#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

int c,h;
int a[55555];
bool sumn[11111111];
int ans;

void input(){
    int i;
    cin>>c>>h;
    for (i=1;i<=h;i++){
        scanf("%d",&a[i]);
    }
}

void sum(){
    int i,j;
    int res;
    int res1;
    res=0;
    res1=0;
    for (i=1;i<=n;i++){
        res+=a[i];
        sumn[a[i]]=true;
        ans=res;
    }
    res=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++){
            res=a[i]+a[j];
            res1=a[i+1]+res;
            sumn[res]=true;
            sumn[res1]=true;
        }
}


void process(){
    int i;
    int ans;
    ans1=INF;
    for (i=1;i<=ans;i++){
        if (sumn[i])
            if (ans-i>0){
                ans1=min(ans1,ans-i);
            }
    }
    cout<<ans1;
}

int main(){
    freopen("hay4sale","r",strdin);
    freopen("hay4sale","w",stdout);
    input();
    sum();
    process();
}
