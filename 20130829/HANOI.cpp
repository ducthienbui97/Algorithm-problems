#include<bits/stdc++.h>
#define step first
#define to second
using namespace std;
typedef pair<long long int,long long int> pii;
pii F[40][5];
int t;
vector<pii> lis;
char c[4];
int n;
void pre(){
	for(int i=0;i<lis.size();i++)
	if(lis[i].first==1){
		F[1][1]=make_pair(1,lis[i].second);
		break;
	}
	for(int i=0;i<lis.size();i++)
	if(lis[i].first==2){
		F[1][2]=make_pair(1,lis[i].second);
		break;
	}
	for(int i=0;i<lis.size();i++)
	if(lis[i].first==3){
		F[1][3]=make_pair(1,lis[i].second);
		break;
	}
}
void doit(){
	pre();
	for(int i=2;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(F[i-1][F[i-1][j].to].to==j){
				F[i][j]=make_pair(2*F[i-1][j].step+F[i-1][j].step+2,F[i-1][j].to);
			}
			else {
				F[i][j]=make_pair(F[i-1][j].step+F[i-1][F[i-1][j].to].step+1,F[i-1][j].to^j);
			}
		}
		//cout<<i<<" "<<F[i][1].to<<endl;
	}
	cout<<F[n][1].step<<endl;
}
main(){
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		lis.clear();
		for(int i=0;i<6;i++)
		cin>>c,lis.push_back(make_pair(c[0]-'A'+1,c[1]-'A'+1));
		doit();
	}
}
