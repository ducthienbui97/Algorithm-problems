#include <bits/stdc++.h>
/*
4 4
luka
o#a#
kula
i#a#
*/
using namespace std;
int n,m;
char c[22][22];
char Min[22];
main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>(&c[i][1]);
        }
    int lmin=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            int les=0;
            int cnt=0;
            for(int l=j; l<=m&&c[i][l]!='#'; l++) {
                cnt++;
                if(!les&&cnt<=lmin) if(c[i][l]<Min[cnt-1]) les=1;
                    else if(c[i][l]>Min[cnt-1]) les=-1;
                }
            if(cnt>1&&(j==1||c[i][j-1]=='#')) {
                if(les==1||!lmin) {
                    les=0;
                    lmin=cnt+1;
                    }
                if(les==0&&cnt<lmin) {
                    lmin=cnt;
                    Min[lmin]=0;
                    for(int l=0; l<cnt; l++)
                        Min[l]=c[i][j+l];
                    }
                }
            les=0;
            cnt=0;
            for(int l=i; l<=n&&c[l][j]!='#'; l++) {
                cnt++;
                if(!les&&cnt<=lmin) if(c[l][j]<Min[cnt-1]) les=1;
                    else if(c[l][j]>Min[cnt-1]) les=-1;
                }
            if(cnt>1&&(i==1||c[i-1][j]=='#')) {
                if(les==1||!lmin) {
                    les=0;
                    lmin=cnt+1;
                    }
                if(les==0&&cnt<lmin) {
                    lmin=cnt;
                    Min[lmin]=0;
                    for(int l=0; l<cnt; l++)
                        Min[l]=c[i+l][j];
                    }

                }
            }
    cout<<Min;
    }
