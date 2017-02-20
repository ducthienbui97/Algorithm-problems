#include <bits/stdc++.h>
#define elif else if
using namespace std;
struct dice{
    int Top,Right,Front;
    int mirror(int x){
        return 7-x;
    }
    dice(){
        Top=1;
        Right=3;
        Front=2;
    }
    int roll_right(){
        Right=mirror(Right);
        swap(Top,Right);
        return Top;
    }
    int roll_left(){
        Top=mirror(Top);
        swap(Top,Right);
        return Top;
    }
    int roll_down(){
        Front=mirror(Front);
        swap(Top,Front);
        return Top;
    }
    int roll_left(int t){
        int rep=(t/4)*(Top+Right+mirror(Top)+mirror(Right));
        while(t&3){
            rep+=roll_left();
            t--;
        }
        return rep;
    }
    int roll_right(int t){
        int rep=(t/4)*(Top+Right+mirror(Top)+mirror(Right));
        while(t&3){
            rep+=roll_right();
            t--;
        }
        return rep;
    }
};
int n,m;
main() {
    ios_base::sync_with_stdio (false);
    dice now;
    long long ans;
    ans=1;
    cin>>n>>m;
    m--;
    for(int i=1;i<=n;i++){
        if(i&1){
           ans+= now.roll_right(m);
        }else ans+=now.roll_left(m);
        if(i!=n) ans+=now.roll_down();
    }
    cout<<ans<<endl;
}
