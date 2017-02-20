#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <climits>
#include <utility>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
main(){
    int n;
    set<int> ms;
    scanf("%d",&n);
    int x;
    int Max=0;
    for(int i=0;i<n;i++){
       scanf("%d",&x);
       if(x==1) continue;
       Max=max(Max,x);
       ms.insert(x);
    }
    set<int> :: iterator it;
    int rep=0;
    while(!ms.empty()){
        rep++;
        it=ms.begin();
        x=*it;
        n=x;
        x--;
        ms.erase(it);
        while(n<=Max){
            n+=x;
            ms.erase(n);
        }
    }
    printf("%d",rep);
}

