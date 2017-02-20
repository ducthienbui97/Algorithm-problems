#include<iostream>
#include<cmath>
using namespace std;
int N, a[35000];
int mark[30];
int RMQmax[35000][40];
int RMQmin[35000][40];


void input(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    mark[0]=1;
    for(int i=1;i<30;i++) mark[i]=mark[i-1]<<1;
}

void initRMQ(){
    for(int i=0;i<N;i++) RMQmax[i][0]=a[i];
	int k=(int) trunc(log(N)/log(2));
	for(int j=1;j<=k;j++){
		for(int i=0;i<N-mark[j]+1;i++){
			RMQmax[i][j]=max(RMQmax[i][j-1],RMQmax[i+(mark[j-1])][j-1]);
		}
	}
	for(int i=0;i<N;i++) RMQmin[i][0]=a[i];
	k = (int) trunc(log(N)/log(2));
	for(int j=1;j<=k;j++){
		for(int i=0;i<N-mark[j]+1;i++){
			RMQmin[i][j]=min(RMQmin[i][j-1],RMQmin[i+(mark[j-1])][j-1]);
		}
	}
}

int TimMax(int u, int v){
	int k=(int) trunc(log(v-u+1)/log(2));
	return max(RMQmax[u][k],RMQmax[v-mark[k]+1][k]);
}

int TimMin(int u, int v){
	int k=(int) trunc(log(v-u+1)/log(2));
	return min(RMQmin[u][k],RMQmin[v-mark[k]+1][k]);
}

int tinh(int k){
    if ((k==0) || (k==N-1)) return -1;
    int d,c,md,ans1=-1,ans2=-1;
    d=0;
    c=k-1;
    while(d<=c){
        md=(d+c)/2;
        if (TimMax(md,k-1)>a[k]) {
            d=md+1;
        } else {
            c=md-1;
            ans1=md;
        }
    }
    
    d=k+1;
    c=N-1;
    while(d<=c){
        md=(d+c)/2;
        if (TimMin(k+1,md)<a[k]) {
            c=md-1;
        } else {
            d=md+1;
            ans2=md;
        }
    }
    if ((ans1!=-1) && (ans2!=-1)){
        return ans2-ans1+1;
    } else return -1;
}

void process(){
    int ans=-1,anslength=-1;
    int kq;
    
    for(int i=0;i<N;i++){
        kq=tinh(i);
        if (kq>anslength){
            anslength=kq;
            ans=i;
        }
    }
    if (ans==-1) cout<<-1;
    else cout<<ans+1<<" "<<anslength;
}

int main(){
    //freopen("STICKS.INP","r",stdin); freopen("STICKS.OUT","w",stdout);
    input();
    initRMQ();
    process();
    return 0;
}
