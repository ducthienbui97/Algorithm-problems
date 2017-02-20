#include <deque>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#define elif else if
#include <queue>
#include <vector>
using namespace std;
long long MMax[55][2][2][2][2][2][2],MMin[55][2][2][2][2][2][2];
bool donemx[55][2][2][2][2][2][2],donemn[55][2][2][2][2][2][2];
vector<int> A1,A2,A3,B1,B2,B3;
long long Max(int now,bool smA1,bool smA2,bool smA3,bool bgB1,bool bgB2,bool bgB3){
    if(now<0) return 0;
    if(donemx[now][smA1][smA2][smA3][bgB1][bgB2][bgB3]) return MMax[now][smA1][smA2][smA3][bgB1][bgB2][bgB3];
    donemx[now][smA1][smA2][smA3][bgB1][bgB2][bgB3]=true;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int l=0;l<2;l++){
                if((!smA1&&i<A1[now])||(!bgB1&&i>B1[now])||(!smA2&&j<A2[now])||(!bgB2&&j>B2[now])||(!smA3&&l<A3[now])||(!bgB3&&l>B3[now])) continue;
                MMax[now][smA1][smA2][smA3][bgB1][bgB2][bgB3]=max(MMax[now][smA1][smA2][smA3][bgB1][bgB2][bgB3],(1LL*(i^j^l))<<now|Max(now-1,smA1||i>A1[now],smA2||j>A2[now],smA3||l>A3[now],bgB1||i<B1[now],bgB2||j<B2[now],bgB3||l<B3[now]));

        }
    return MMax[now][smA1][smA2][smA3][bgB1][bgB2][bgB3];
}
long long Min(int now,bool smA1,bool smA2,bool smA3,bool bgB1,bool bgB2,bool bgB3){
    if(now<0) return 0;
    if(donemn[now][smA1][smA2][smA3][bgB1][bgB2][bgB3]) return MMin[now][smA1][smA2][smA3][bgB1][bgB2][bgB3];
    donemn[now][smA1][smA2][smA3][bgB1][bgB2][bgB3]=true;
    MMin[now][smA1][smA2][smA3][bgB1][bgB2][bgB3]=1LL<<60;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int l=0;l<2;l++){
                if((!smA1&&i<A1[now])||(!bgB1&&i>B1[now])||(!smA2&&j<A2[now])||(!bgB2&&j>B2[now])||(!smA3&&l<A3[now])||(!bgB3&&l>B3[now])) continue;
                MMin[now][smA1][smA2][smA3][bgB1][bgB2][bgB3]=min(MMin[now][smA1][smA2][smA3][bgB1][bgB2][bgB3],(1LL*(i^j^l))<<now|Min(now-1,smA1||i>A1[now],smA2||j>A2[now],smA3||l>A3[now],bgB1||i<B1[now],bgB2||j<B2[now],bgB3||l<B3[now]));
        }
    return MMin[now][smA1][smA2][smA3][bgB1][bgB2][bgB3];
}
void doi(vector<int>& x,long long t){
    x.resize(55);
    for(int i=0;i<55;i++)
        x[i]=(t&(1LL<<i))?true:false;

}
main() {
    freopen("XOR3.INP","r",stdin);
    freopen("XOR3.OUT","w",stdout);
    long long X,Y;
    ios_base::sync_with_stdio(false);
    cin>>X>>Y;
    doi(A1,X);
    doi(B1,Y);
    cin>>X>>Y;
    doi(A2,X);
    doi(B2,Y);
    cin>>X>>Y;
    doi(A3,X);
    doi(B3,Y);
    cout<<Min(54,false,false,false,false,false,false)<<endl<<Max(54,false,false,false,false,false,false);
    }


