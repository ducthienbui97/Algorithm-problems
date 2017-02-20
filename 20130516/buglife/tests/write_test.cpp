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

int main(){
    srand(time(0));
    freopen("input.txt","w",stdout);
    cout<<"20\n";
    int i,j,u,v,t,n,n1,n2,m;
    for (i=1;i<=20;i++){
        if (i==1){
            t=0;
            n=1;
            m=0;
        }
        if (i==19){
            t=0;
            n=2000;
            m=100000;
        }
        if (i==20){
            t=1;
            n=2000;
            n1=1000;
            n2=1000;
            m=100000;
        }
        if ((2<=i)&&(i<=18)){
            t=rand()%2;
            if (t==0){
                while (true){
                    n=rand()%2000+1;
                    if (n>1) break;
                }
                m=rand()%100001;
            }
            if (t==1){
                n1=rand()%1000+1;
                n2=rand()%1000+1;
                n=n1+n2;
                m=rand()%100001;
            }
        }
        cout<<"\n";
        cout<<n<<" "<<m<<"\n";
        if (t==0)
            for (j=1;j<=m;j++)
                while (true){
                    u=rand()%n+1;
                    v=rand()%n+1;
                    if (u!=v){
                        cout<<u<<" "<<v<<"\n";
                        break;
                    }
                }
        if (t==1)
            for (j=1;j<=m;j++){
                u=rand()%n1+1;
                v=rand()%n2+1;
                cout<<u<<" "<<v+n1<<"\n";
            }
    }
}
