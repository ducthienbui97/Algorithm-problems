#include <bits/stdc++.h>
using namespace std;
bool pr[222];
vector<bool> F;
vector<long long> dv;
void solve(int nTest) {
    long long n;
    dv.clear();
    cin >> n;
    //cerr <<"X" <<n<<endl;
    for(long long i=2;i<=n/i;i++){
        long long cur = i;
        //cerr << cur << endl;
        while(n%cur==0) cur*=i;
        cur/=i;
       // cerr << cur <<" "<< n <<endl;
        n/=cur;
        if(cur > 1) dv.push_back(cur);
    }

    if(n > 1) dv.push_back(n);
    F = vector<bool> (1<<dv.size());
    for(int st=0;st<F.size();st++){
        long long val = 1;
        for(int j=0;j<dv.size();j++)
            if(st&(1<<j))
                val*=dv[j];
       // cerr << val <<endl;
        int sum = 0;
        while(val){
            sum += val%10;
            val /=10;
        }
        for(int j = 0; j < dv.size() && pr[sum];j++)
            if(st&(1<<j))
                F[st] = F[st]||(!F[st^(1<<j)]);
        //cerr << st <<" "<<F[st] <<endl;
    }

    cout << "Case #"<<nTest<<": "<<(!F.back()?"Seymour\n":"Laurence\n");
}
main(){
    for(int i=2;i<=200;i++) if(!pr[i]){
        for(int j=i+i;j<=200;j+=i) pr[j] = true;
    }
    freopen("C-small-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}




