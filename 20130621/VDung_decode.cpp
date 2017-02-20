#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > a(30, vector<int> (1,1));
vector<char> tosort;
int move[10005];
char c[10005];
vector<char> result;

int main(){
	freopen("decode.inp","r",stdin);
	freopen("decode.out","w",stdout);
	int n, k, i;
	while(scanf("%s", c)!=EOF){
		scanf("%d", &k);
		
		n= strlen(c);
		for(i=0;i<n;i++){
			tosort.push_back(c[i]);
		}
		sort(tosort.begin(),tosort.end());
		for(i=0;i<n;i++){
			a[tosort[i]-'0'-48].push_back(i+1);
		}
		for(i=0;i<n;i++){
			move[i+1]= a[c[i]-'0'-48][a[c[i]-'0'-48][0]];
			a[c[i]-'0'-48][0]++;
		}
		i= k; result.push_back(c[i-1]);
		while(move[i]!=k){
			result.push_back(c[move[i]-1]);
			i= move[i];
		}
		for(i=n-1;i>=0;i--){
			printf("%c", result[i]);
		}
		printf("\n");
		while(tosort.size()>0) tosort.pop_back();
		for(i=1;i<=26;i++) {
			while(a[i].size()>0) a[i].pop_back();
			a[i].push_back(1);
		}
		while(result.size()>0) result.pop_back();
	}
	return 0;
}
