#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <time.h>

using namespace std;

int n,m,s,f;

int main(){
    srand(time(0));
    freopen("0.inp","w",stdout);
    while (true){
        n=rand()%50000+1;
        m=rand()%200001;
        if (n>=30000) break;
    }
    n=50000;
    m=2000;
    while (true){
        s=rand()%n+1;
        f=rand()%n+1;
        if (s!=f) break;
    }
    cout<<n<<" "<<m<<" "<<s<<" "<<f<<"\n";
    int i,u,v,w;
    for (i=1;i<=m;i++)
        while (true){
            u=rand()%n+1;
            v=rand()%n+1;
            if (u!=v){
                w=rand()%30000+1;
                cout<<u<<" "<<v<<" "<<w<<"\n";
                break;
            }
        }
}
