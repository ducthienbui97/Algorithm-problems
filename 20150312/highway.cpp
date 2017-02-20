#include <bits/stdc++.h>
using namespace std;
int n;
long long s,t,a[44],b[44],c[44],q[44];
vector<pair <long long,long long> > tmpt[2],tmpm[2],ttime[2],money[2];
void getmin(long long& x,long long y){if(x>y) x=y;}
main(){
   //freopen("Exams/HIGHWAY/test16/HIGHWAY.INP","r",stdin);
    ios_base::sync_with_stdio(false);
    cin>>n>>t>>s;
    cin>>a[1]>>b[1]>>c[1];
    for(int i=2;i<=n;i++)
        cin>>q[i]>>a[i]>>b[i]>>c[i];
    int n1=n>>1;
    int n2=n-n1;
    for(int i=0;i<(1<<n1);i++){
        long long _t=0,_m=0;
        for(int j=0;j<n1;j++){
            if(j && ((i>>(j-1))&1)!=((i>>j)&1)){
                _t+=q[j+1];
            }
            if((i>>j)&1){
                _t+=b[j+1];
                _m+=c[j+1];
            }else{
                _t+=a[j+1];
            }
        }
        tmpt[(i>>(n1-1))&1].push_back(make_pair(_m,_t));
        tmpm[(i>>(n1-1))&1].push_back(make_pair(_t,_m));
    }
    for(int i=0;i<2;i++){
        sort(tmpt[i].begin(),tmpt[i].end());
        sort(tmpm[i].begin(),tmpm[i].end());
        long long mmin = 1ll<<60;
        for(vector<pair<long long,long long> >::iterator it=tmpt[i].begin();it!=tmpt[i].end();it++){
            if(mmin>it->second){
                ttime[i].push_back(*it);
                mmin=it->second;
            }
         }
        mmin = 1ll<<60;
        for(vector<pair<long long,long long> >::iterator it=tmpm[i].begin();it!=tmpm[i].end();it++){
            if(mmin>it->second){
                money[i].push_back(*it);
                mmin=it->second;
            }
        }
    }
    long long ans1=1ll<<60,ans2=1ll<<60;
    for(int i=0;i<(1<<n2);i++){
        long long _t=0,_m=0;
        for(int j=0;j<n2;j++){
            if(j && ((i>>(j-1))&1)!=((i>>j)&1)){
                _t+=q[n1+j+1];
            }
            if((i>>j)&1){
                _t+=b[n1+j+1];
                _m+=c[n1+j+1];
            }else{
                _t+=a[n1+j+1];
            }
        }
        vector<pair<long long,long long> >::iterator it;
        it = upper_bound(ttime[i&1].begin(),ttime[i&1].end(),make_pair(s-_m,(1ll<<60)));
        if(it!= ttime[i&1].begin()){
            it--;
            ans1=min(ans1,it->second+_t);
        }
        it = upper_bound(money[i&1].begin(),money[i&1].end(),make_pair(t-_t,(1ll<<60)));
        if(it!= money[i&1].begin()){
            it--;
            ans2=min(ans2,it->second+_m);
        }
        _t+=q[n1+1];
        it = upper_bound(ttime[!(i&1)].begin(),ttime[!(i&1)].end(),make_pair(s-_m,(1ll<<60)));
        if(it!= ttime[!(i&1)].begin()){
            it--;
            ans1=min(ans1,it->second+_t);
        }
        it = upper_bound(money[!(i&1)].begin(),money[!(i&1)].end(),make_pair(t-_t,(1ll<<60)));
        if(it!= money[!(i&1)].begin()){
            it--;
            ans2=min(ans2,it->second+_m);
        }
    }
    if(ans2==1ll<<60) ans2=-1;
    if(ans1==1ll<<60) ans1=-1;
    printf("%lld %lld",ans2,ans1);
}


