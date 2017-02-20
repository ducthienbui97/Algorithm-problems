#include <bits/stdc++.h>
#define elif else if
using namespace std;
const int INF=1<<25;
string S;
bool done[100][100][100];
int f[100][100][100];
vector<int> dd[100][100];
vector<pair<int,int> >  d[100];
int F(int i,int j,int k){
        if(done[i][j][k]) return f[i][j][k];
        done[i][j][k]=true;
        f[i][j][k]=INF;
        for(int l=i;l<j;l++)
            for(int cnt=0;cnt<d[k].size();cnt++)
            f[i][j][k]=min(f[i][j][k],max(F(i,l,d[k][cnt].first),F(l+1,j,d[k][cnt].second))+1);

        return f[i][j][k];
}
char c[100];
int  n;
main(){
	freopen("worms.inp","r",stdin);
	freopen("worms.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    while(n--){
        cin>>c;
        dd[c[1]-'A'][c[2]-'A'].push_back(c[0]-'A');
        d[c[0]-'A'].push_back(make_pair(c[1]-'A',c[2]-'A'));

    }
    cin>>S;
    for(int j=0;j<26;j++)
    for(int i=0;i<S.length();i++){
        done[i][i][j]=done[i][i+1][j]=true;
        f[i][i][j]=f[i][i+1][j]=INF;
    }
    for(int i=0;i<S.length();i++){
        f[i][i][S[i]-'A']=0;
    }

    for(int i=1;i<S.length();i++)
    for(int j=0;j<dd[S[i-1]-'A'][S[i]-'A'].size();j++)
        f[i-1][i][dd[S[i-1]-'A'][S[i]-'A'][j]]=1;
    int ans=INF;
    for(int i=0;i<26;i++)
        ans=min(ans,F(0,S.length()-1,i));
    if(ans==INF) ans=-1;
    printf("%d",ans);
}
