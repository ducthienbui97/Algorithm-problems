#include <bits/stdc++.h>
#define elif else if
using namespace std;
const int Maxn=1e6+20;
int a[Maxn];
int Left[Maxn],Right[Maxn];
int n;
stack<int> s;
void findLeft(){
    memset(Left,0,sizeof Left);
    s=stack<int> ();
    int j=1;
    while(j<=n){
        if(s.empty()){
            Left[j]=0;
            s.push(j++);
        }
        elif(a[s.top()]<a[j]) s.pop();
        else{
            Left[j]=s.top();
            s.push(j++);
        }
    }
}
void findRight(){
    memset(Right,0,sizeof Right);
    s=stack<int>();
    int j=n;
    while(j>0){
         if(s.empty()){
            Right[j]=n+1;
            s.push(j--);
        }
        elif(a[s.top()]<=a[j]) s.pop();
        else{
            Right[j]=s.top();
            s.push(j--);
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int t=2;
    long long ans=0;
    while(t--){
        for(int i=1;i<=n;i++)
            a[i]=-a[i];
        findLeft();
        findRight();
        for(int i=1;i<=n;i++)
            ans+=(long long) 1LL*a[i]*(Right[i]-i)*(i-Left[i]);
    }
    cout<<ans;

    }
