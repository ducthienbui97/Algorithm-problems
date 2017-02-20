#include <bits/stdc++.h>
using namespace std;
const int Max=1e5+20;
int F[Max];
int S[Max],T[Max];
int a[Max],n;
main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n;i>0;i--)
        S[i]=S[i+1]+a[i];
    deque<int> q;
    q.push_back(0);
    for(int i=n;i>0;i--){
        while(q.size()>1&&S[i]>=T[q[1]]) q.pop_front();
        F[i]=F[q.front()]+1;
        T[i]=S[i]+S[i]-S[q.front()];
        while(q.size()>1&&T[q.back()]>T[i]) q.pop_back();
        q.push_back(i);
    }
    cout<<F[1]<<endl;
}

