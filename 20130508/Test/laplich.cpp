#include<iostream>
#include<queue>
using namespace std;
struct congviec{
	int thoidiem,w;
};
int n,ans;
congviec D[15000];
priority_queue<int> q;
bool ss(congviec cv1,congviec cv2){
	if (cv1.thoidiem==cv2.thoidiem){
		return cv1.w<cv2.w;
	} else {
		return cv1.thoidiem<cv2.thoidiem;
	}
}
int main(){
	//freopen("laplich.INP","r",stdin);
	//freopen("laplich.OUT","w",stdout);
	while(cin>>n){
		for(int i=0;i<n;i++){
			scanf("%d %d",&D[i].w,&D[i].thoidiem);
		}
		sort(&D[0],&D[n],ss);
		for(int i=0;i<n;i++){
			if (q.size()<D[i].thoidiem) {
                q.push(-D[i].w);
            } else {
				if ((-q.top())<D[i].w){
					q.pop();
					q.push(-D[i].w);
				}
			}
		}
		ans=0;
		while(!q.empty()){
			ans+=(-q.top());
			q.pop();
		}
		cout<<ans<<endl;;
	}
	return 0;
}
